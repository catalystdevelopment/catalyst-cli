// Copyright (c) 2019, The TurtleCoin Developers
//
// Please see the included LICENSE file for more information.

/////////////////////////////////
#include <Utilities/ParseExtra.h>
/////////////////////////////////

#include <config/Constants.h>

namespace Utilities
{
    std::string getPaymentIDFromExtra(const std::vector<uint8_t> &extra)
    {
        const ParsedExtra parsed = parseExtra(extra);
        return parsed.paymentID;
    }

    Crypto::PublicKey getTransactionPublicKeyFromExtra(const std::vector<uint8_t> &extra)
    {
        const ParsedExtra parsed = parseExtra(extra);
        return parsed.transactionPublicKey;
    }

    ParsedExtra parseExtra(const std::vector<uint8_t> &extra)
    {
        ParsedExtra parsed { Constants::NULL_PUBLIC_KEY, std::string() } ;

        bool seenPubKey = false;
        bool seenPaymentID = false;

        for (auto it = extra.begin(); it != extra.end(); it++)
        {
            const uint8_t c = *it;

            const auto elementsRemaining = std::distance(it, extra.end());

            /* Found a pubkey */

            /* Public key looks like this

               [...data...] 0x01 [public key] [...data...]

            */
            if (c == Constants::TX_EXTRA_PUBKEY_IDENTIFIER && elementsRemaining > 32 && !seenPubKey)
            {
                /* Copy 32 chars, beginning from the next char */
                std::copy(it + 1, it + 1 + 32, std::begin(parsed.transactionPublicKey.data));

                /* Advance past the public key */
                it += 32;

                seenPubKey = true;

                /* And continue parsing. */
                continue;
            }

            /* Found a payment ID, and have space for extra nonce size, pid identifier,
               and pid. */

            /* Payment ID looks like this (payment ID is stored in extra nonce)

               [...data...] 0x02 [size of extra nonce] 0x00 [payment ID] [...data...]

            */
            if (c == Constants::TX_EXTRA_NONCE_IDENTIFIER 
                && elementsRemaining > 1 + 1 + 32
                && *(it + 2) == Constants::TX_EXTRA_PAYMENT_ID_IDENTIFIER
                && !seenPaymentID)
            {
                const auto dataBegin = it + 3;

                Crypto::Hash paymentIDHash;

                /* Copy the payment ID into the hash */
                std::copy(dataBegin, dataBegin + 32, std::begin(paymentIDHash.data));

                /* Convert to a string */
                std::string paymentID = Common::podToHex(paymentIDHash);

                /* Convert it to lower case */
                std::transform(paymentID.begin(), paymentID.end(),
                               paymentID.begin(), ::tolower);

                parsed.paymentID = paymentID;

                /* Advance past the payment ID */
                it += 32 + 1 + 1;

                seenPaymentID = true;

                /* And continue parsing */
                continue;
            }
        }

        return parsed;
    }
}
