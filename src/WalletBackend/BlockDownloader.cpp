// Copyright (c) 2019, The TurtleCoin Developers
// 
// Please see the included LICENSE file for more information.

//////////////////////////////////////////
#include <WalletBackend/BlockDownloader.h>
//////////////////////////////////////////

#include <Logger/Logger.h>

std::vector<WalletTypes::WalletBlockInfo> BlockDownloader::fetchBlocks(const size_t blockCount) const
{
    return m_storedBlocks.front_n(blockCount);
}

uint64_t BlockDownloader::getHeight() const
{
    return 0; /* TODO */
}

std::vector<Crypto::Hash> BlockDownloader::getStoredBlockCheckpoints() const
{
    const auto blocks = m_storedBlocks.front_n(Constants::LAST_KNOWN_BLOCK_HASHES_SIZE);

    std::vector<Crypto::Hash> result;

    result.resize(blocks.size());

    std::transform(blocks.rbegin(), blocks.rend(), result.begin(), [](const auto block) { return block.blockHash; });

    return result;
}

std::vector<Crypto::Hash> BlockDownloader::getBlockCheckpoints() const
{
    /* Note that these are in the wrong order - they are oldest to newest,
       when we want the inverse. Skipping an inverse in getStoredBlockCheckpoints
       since we need to concat these anyway which requires another iteration (?) */
    /* Hashes of blocks we have downloaded but not processed */
    const auto unprocessedBlockHashes = getStoredBlockCheckpoints();

    /* Hashes of blocks we have processed in the wallet */
    const auto recentProcessedBlockHashes = m_synchronizationStatus->getRecentBlockHashes();

    std::vector<Crypto::Hash> result;

    /* Add in reverse order for reasons mentioned previously */
    std::copy(unprocessedBlockHashes.rbegin(), unprocessedBlockHashes.rend(), std::back_inserter(result));

    /* If we don't have the desired 50 blocks, add on the recently processed
       block checkpoints. This fixes us not passing the right data when
       we are fully synced or have no store built up yet */
    if (result.size() < Constants::LAST_KNOWN_BLOCK_HASHES_SIZE)
    {
        /* Copy the amount of hashes available, or the amount needed to make
           up the difference, whichever is less */
        const size_t numToCopy = std::min(
            recentProcessedBlockHashes.size(),
            Constants::LAST_KNOWN_BLOCK_HASHES_SIZE - result.size()
        );

        std::copy(recentProcessedBlockHashes.begin(), recentProcessedBlockHashes.begin() + numToCopy, std::back_inserter(result));
    }

    /* Infrequent checkpoints to handle deep forks */
    const auto blockHashCheckpoints = m_synchronizationStatus->getBlockCheckpoints();

    std::copy(blockHashCheckpoints.begin(), blockHashCheckpoints.end(), std::back_inserter(result));

    return result;
}

void BlockDownloader::downloadBlocks()
{
    std::scoped_lock lock(m_mutex);

    const uint64_t localDaemonBlockCount = m_daemon->localDaemonBlockCount();

    const uint64_t walletBlockCount = getHeight();

    if (localDaemonBlockCount < walletBlockCount)
    {
        return;
    }

    const auto blockCheckpoints = getBlockCheckpoints();

    const auto [success, blocks] = m_daemon->getWalletSyncData(
        blockCheckpoints, m_startHeight, m_startTimestamp
    );

    /* If we get no blocks, we are fully synced.
       (Or timed out/failed to get blocks)
       Sleep a bit so we don't spam the daemon. */
    if (!success || blocks.empty())
    {
        /* We may have also failed because we requested
           more data than could be returned in a reasonable
           amount of time, so we'll back off a little bit */
        m_daemon->decreaseRequestedBlockCount();

        Logger::logger.log(
            "Zero blocks received from daemon, possibly fully synced",
            Logger::DEBUG,
            {Logger::SYNC}
        );

        return;
    }

    /* If we received data back, we'll make sure we're back
       to running at full speed in case we backed off a little
       bit before */
    m_daemon->resetRequestedBlockCount();

    /* Timestamp is transient and can change - block height is constant. */
    if (m_startTimestamp != 0)
    {
        m_startTimestamp = 0;
        m_startHeight = blocks.front().blockHeight;

        m_subWallets->convertSyncTimestampToHeight(m_startTimestamp, m_startHeight);
    }

    /* If checkpoints are empty, this is the first sync request. */
    if (blockCheckpoints.empty())
    {
        /* Only check if a timestamp isn't given */
        if (m_startTimestamp == 0)
        {
            /* Loop through the blocks we got back and make sure that
               we were given data for the start block we were looking for */
            const auto it = std::find_if(blocks.begin(), blocks.end(), [this](const auto &block) {
                return block.blockHeight == m_startHeight;
            });

            /* If we weren't given a block with the startHeight we were
               looking for then we don't need to store this data */
            if (it == blocks.end())
            {
                std::stringstream stream;

                stream << "Received unexpected block height from daemon. "
                       << "Expected " << m_startHeight << ", but did not "
                       << "receive that block. Not storing any blocks.";

                Logger::logger.log(
                    stream.str(),
                    Logger::WARNING,
                    {Logger::SYNC, Logger::DAEMON}
                );

                return;
            }
        }
    }

    m_storedBlocks.push_back_n(blocks.begin(), blocks.end());
}
