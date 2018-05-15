//
//  Miner.hpp
//  Volta
//
//  Created by Remy Broun on 5/4/18.
//  Copyright © 2018 Remy Broun. All rights reserved.
//
//
#ifndef Miner_hpp
#define Miner_hpp
#include <string>
#include <stdio.h>
#include "Wallet.h"
#include "Block.h"
#include <cstdint>
#include <string>

using namespace std;

class Miner {

public:
    Miner();
    void startMining();
    void mineBlock(uint32_t nDifficulty);
    Block createBlock();

private:
    bool isMining;
    string ID;
    string _CalculateBlockHash() const;
    static string calculateMerkle(vector<Transaction> _vTransactions);

    
};

#endif /* Miner_hpp */
