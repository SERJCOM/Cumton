#include <catch2/catch_test_macros.hpp>

#include "Blockchain/Block.hpp"
#include "Blockchain/BlockchainDB.hpp"

TEST_CASE("BLOCKCHAIN DB TEST")
{
    using namespace cumton::blockchain;
    using namespace cumton;

    auto db = CreateBlockChainDB();

    Block block1;
    block1.prev_block = utilities::crypto::sha256("1");
    block1.CalculateBlockHash();

    Block block2;
    block2.prev_block = block1.block_hash;
    block2.CalculateBlockHash();

    Block block3;
    block3.prev_block = block2.block_hash;
    block3.CalculateBlockHash();

    db->AddNewBlock(block1);
    db->AddNewBlock(block2);
    db->AddNewBlock(block3);

    REQUIRE(db->GetSize() == 3);

    REQUIRE(db->GetBlock(block2.block_hash) == block2);

    REQUIRE(db->GetBlock(block1.block_hash) == block1);
}

