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

        /////////////////////////////
        /* Public member functions */
        /////////////////////////////

        /* Retrieve blockCount blocks from the internal store. does not remove
           them. Returns as many as possible if the amount requested is not
           available. May be empty (this is the norm when synced.) */
        std::vector<WalletTypes::WalletBlockInfo> fetchBlocks(const size_t blockCount) const;

    private:

        //////////////////////////////
        /* Private member functions */
        //////////////////////////////

        uint64_t getHeight() const;

        std::vector<Crypto::Hash> getStoredBlockCheckpoints() const;

        std::vector<Crypto::Hash> getBlockCheckpoints() const;

        void downloadBlocks();

        //////////////////////////////
        /* Private member variables */
        //////////////////////////////

        /* Cached blocks */
        ThreadSafeDeque<WalletTypes::WalletBlockInfo> m_storedBlocks;

        /* The daemon connection */
        std::shared_ptr<Nigel> m_daemon;

        /* Ensure we're only making one request at once */
        std::mutex m_mutex;

        /* Timestamp to begin syncing at */
        uint64_t m_startTimestamp;

        /* Height to begin syncing at */
        uint64_t m_startHeight;

        /* Sync progress */
        std::shared_ptr<SynchronizationStatus> m_synchronizationStatus;

        std::shared_ptr<SubWallets> m_subWallets;
};
