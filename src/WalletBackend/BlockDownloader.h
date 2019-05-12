// Copyright (c) 2019, The TurtleCoin Developers
// 
// Please see the included LICENSE file for more information.

#pragma once

#include <atomic>

#include <config/Constants.h>

#include <Nigel/Nigel.h>

#include <SubWallets/SubWallets.h>

#include <Utilities/ThreadSafeDeque.h>

#include <vector>

#include <WalletBackend/SynchronizationStatus.h>

#include <WalletTypes.h>

class BlockDownloader
{
    public:
        /* Destructor */
        ~BlockDownloader();

        /////////////////////////////
        /* Public member functions */
        /////////////////////////////

        /* Retrieve blockCount blocks from the internal store. does not remove
           them. Returns as many as possible if the amount requested is not
           available. May be empty (this is the norm when synced.) */
        std::vector<WalletTypes::WalletBlockInfo> fetchBlocks(const size_t blockCount);

        /* Drops the oldest block from the internal queue */
        void dropBlock();

        /* Start block downloading process */
        void start();

        /* Stop block downloading process */
        void stop();

    private:

        //////////////////////////////
        /* Private member functions */
        //////////////////////////////

        /* Synchronizes pre-fetching blocks */
        void downloader();

        /* Determines if we should prefetch more blocks */
        bool shouldFetchMoreBlocks() const;

        /* Gets checkpoints of stored (not processed) blocks */
        std::vector<Crypto::Hash> getStoredBlockCheckpoints() const;

        /* Gets checkpoints of stored, processed, and infrequent checkpoints */
        std::vector<Crypto::Hash> getBlockCheckpoints() const;

        /* Downloads a set of blocks, if needed */
        bool downloadBlocks();

        //////////////////////////////
        /* Private member variables */
        //////////////////////////////

        /* Cached blocks */
        ThreadSafeDeque<WalletTypes::WalletBlockInfo> m_storedBlocks;

        /* The daemon connection */
        std::shared_ptr<Nigel> m_daemon;

        /* Timestamp to begin syncing at */
        uint64_t m_startTimestamp;

        /* Height to begin syncing at */
        uint64_t m_startHeight;

        /* Sync progress */
        std::shared_ptr<SynchronizationStatus> m_synchronizationStatus;

        std::shared_ptr<SubWallets> m_subWallets;

        /* For synchronizing block downloading */
        std::mutex m_mutex;

        /* Are we ready to go attempt to retrieve more data */
        std::atomic<bool> m_goFish;

        /* Should we try and fetch more data (Used in conjunction with m_goFish) */
        std::condition_variable m_shouldTryFetch;

        /* Should we stop downloading */
        std::atomic<bool> m_shouldStop;

        /* Thread that performs the actual downloading of blocks */
        std::thread m_downloadThread;
};
