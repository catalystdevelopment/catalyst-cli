// Copyright (c) 2019, The TurtleCoin Developers
//
// Please see the included LICENSE file for more information.

/////////////////////////////////
#include <Miner/BlockUtilities.h>
/////////////////////////////////

#include <Common/CryptoNoteTools.h>
#include <Common/Varint.h>

#include <Serialization/CryptoNoteSerialization.h>
#include <Serialization/SerializationTools.h>

std::vector<uint8_t> getParentBlockBinaryArray(const CryptoNote::BlockTemplate &block, const bool headerOnly)
{
    std::vector<uint8_t> parentBlockBinaryArray;

    auto serializer = makeParentBlockSerializer(block, false, headerOnly);

    if (!toBinaryArray(serializer, parentBlockBinaryArray))
    {
        throw std::runtime_error("Can't serialize parent block header.");
    }

    return parentBlockBinaryArray;
}

std::vector<uint8_t> getBlockHashingBinaryArray(const CryptoNote::BlockTemplate &block)
{
    std::vector<uint8_t> blockHashingBinaryArray;

    if (!toBinaryArray(static_cast<const CryptoNote::BlockHeader&>(block), blockHashingBinaryArray))
    {
        throw std::runtime_error("Can't serialize BlockHeader");
    }

    std::vector<Crypto::Hash> transactionHashes;
    transactionHashes.reserve(block.transactionHashes.size() + 1);
    transactionHashes.push_back(getObjectHash(block.baseTransaction));
    transactionHashes.insert(transactionHashes.end(), block.transactionHashes.begin(), block.transactionHashes.end());

    Crypto::Hash treeHash;

    Crypto::tree_hash(transactionHashes.data(), transactionHashes.size(), treeHash);

    blockHashingBinaryArray.insert(blockHashingBinaryArray.end(), treeHash.data, treeHash.data + 32);

    auto transactionCount = Common::asBinaryArray(Tools::get_varint_data(block.transactionHashes.size() + 1));

    blockHashingBinaryArray.insert(blockHashingBinaryArray.end(), transactionCount.begin(), transactionCount.end());

    return blockHashingBinaryArray;
}

Crypto::Hash getBlockHash(const CryptoNote::BlockTemplate &block)
{
    auto blockHashingBinaryArray = getBlockHashingBinaryArray(block);

    if (block.majorVersion >= CryptoNote::BLOCK_MAJOR_VERSION_2)
    {
        const auto& parentBlock = getParentBlockBinaryArray(block, false);
        blockHashingBinaryArray.insert(blockHashingBinaryArray.end(), parentBlock.begin(), parentBlock.end());
    }

    return CryptoNote::getObjectHash(blockHashingBinaryArray);
}

Crypto::Hash getMerkleRoot(const CryptoNote::BlockTemplate &block)
{
    return CryptoNote::getObjectHash(getBlockHashingBinaryArray(block));
}

Crypto::Hash getBlockLongHash(const CryptoNote::BlockTemplate &block)
{
    const auto rawHashingBlock = getBlockHashingBinaryArray(block);

    Crypto::Hash hash;

    if (block.majorVersion == CryptoNote::BLOCK_MAJOR_VERSION_1)
    {
        cn_slow_hash_v0(rawHashingBlock.data(), rawHashingBlock.size(), hash);
    }
    else if (block.majorVersion == CryptoNote::BLOCK_MAJOR_VERSION_2
          || block.majorVersion == CryptoNote::BLOCK_MAJOR_VERSION_3)
    {
        cn_slow_hash_v0(rawHashingBlock.data(), rawHashingBlock.size(), hash); 
    }
    else if (block.majorVersion == CryptoNote::BLOCK_MAJOR_VERSION_4)
    {
        cn_lite_slow_hash_v1(rawHashingBlock.data(), rawHashingBlock.size(), hash);
    }
    else if (block.majorVersion >= CryptoNote::BLOCK_MAJOR_VERSION_5)
    {
        cn_turtle_lite_slow_hash_v2(rawHashingBlock.data(), rawHashingBlock.size(), hash);
    }
    else 
    {
        throw std::runtime_error("Unknown block major version.");
    }

    return hash;
}
