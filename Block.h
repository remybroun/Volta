#ifndef BLOCK_H
#define BLOCK_H

#include <cstdint>
#include <iostream>
#include "Transaction.h"
#include <vector>

using namespace std;

class Block {
public:
    string sPrevHash;

    Block(uint32_t nIndexIn, const string &sDataIn);

    string GetHash();

    void MineBlock(uint32_t nDifficulty);
    void addTransaction(Transaction _tr);
    unsigned int numberOfTransactions();
    void calculateMerkle();
private:
    uint32_t _nIndex;
    int64_t _nNonce;
    string _sData;
    string _sHash;
    time_t _tTime;
    vector<Transaction> _vTransactions;
    string merkleHash;
    string _CalculateHash() const;
};
#endif
