#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
#include <cstdint>
#include <vector>
#include "Block.h"
#include "Transaction.h"


using namespace std;

class Blockchain {
public:
    Blockchain();
    void AddBlock(Block bNew);
    void AddTransaction(Transaction tr);

private:
    uint32_t _nDifficulty;
    vector<Block> _vChain;

    Block _GetLastBlock() const;
    Block _GetCurrentBlock() const;
    vector<Transaction> listOfTransactions;
    void addTransaction(Transaction tr);

};

#endif
