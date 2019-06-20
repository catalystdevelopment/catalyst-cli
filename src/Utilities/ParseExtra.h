// Copyright (c) 2019, The TurtleCoin Developers
//
// Please see the included LICENSE file for more information.

#pragma once

#include <CryptoTypes.h>

#include <string>

#include <vector>

namespace Utilities
{
    struct ParsedExtra
    {
        Crypto::PublicKey transactionPublicKey;
        std::string paymentID;
    };

    std::string getPaymentIDFromExtra(const std::vector<uint8_t> &extra);

    Crypto::PublicKey getTransactionPublicKeyFromExtra(const std::vector<uint8_t> &extra);

    ParsedExtra parseExtra(const std::vector<uint8_t> &extra);
}
