#pragma once

#include <cstdint>
#include <array>
#include <filesystem>
#include <vector>
#include <map>
#include <array>
#include <iostream>
#include <memory>

#include "Block.hpp"
#include "Crypto/Hash.hpp"

namespace cumton::blockchain
{

    class BlockChain
    {
    public:
        BlockChain();

        bool AddBlock(const Block &block);

        std::vector<Block *> GetNextBlock(const Block &current_block) const;

        Block *GetPreviosBlock(const Block &current_block) const;

        friend std::ostream &operator<<(std::ostream &stream, const Block &block)
        {
        }

    private:
        std::map<crypto::SHA256, std::unique_ptr<Block>> blockchain_db;
    };

}