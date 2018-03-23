#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
#include <cstdint>
#include <vector>
#include <queue>
#include "Block.h"
#include "Transaction.h"


using namespace std;

class Blockchain {
public:
    Blockchain();
    void AddBlock(Block bNew);
    void addTransaction(Transaction tr);
    void addTransactions(vector<Transaction> trs);
private:
    uint32_t _nDifficulty;
    vector<Block> _vChain;

    Block _GetLastBlock() const;
    Block * _GetCurrentBlock();
    queue<Transaction> listOfTransactions;


};

#endif
