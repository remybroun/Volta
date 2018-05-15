#include "Blockchain.h"
#define BLOCKSIZE 10

Blockchain::Blockchain() {
    _vChain.emplace_back(Block(0));
    _nDifficulty = 1;
}

void Blockchain::AddBlock(Block bNew) {
    bNew.sPrevHash = _GetLastBlock().GetHash();
//    bNew.MineBlock(_nDifficulty);
    _vChain.push_back(bNew);
}
Block Blockchain::_GetLastBlock() const {
    return _vChain.back();
}
Block * Blockchain::_GetCurrentBlock() {
    return &_vChain.back();
}

void Blockchain::addTransaction(Transaction tr){

    listOfTransactions.push(tr);
    if (listOfTransactions.size() >= BLOCKSIZE) {
        for (int i = 0; i<BLOCKSIZE; i++) {
            _GetCurrentBlock()->addTransaction(listOfTransactions.front());
            listOfTransactions.pop();
        }
        _GetCurrentBlock()->calculateMerkle();
        int nextBlockNum = _GetCurrentBlock()->getIndex()+1;
        AddBlock(Block(nextBlockNum));
    }
}

void Blockchain::addTransactions(vector<Transaction> trs){
    
    for (int i = 0; i<trs.size(); i++) {
        listOfTransactions.push(trs[i]);
    }
}

