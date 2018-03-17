#include "Blockchain.h"
#define BLOCKSIZE 10

Blockchain::Blockchain() {
    _vChain.emplace_back(Block(0, "Genesis Block"));
    _nDifficulty = 2;
}

void Blockchain::AddBlock(Block bNew) {
    bNew.sPrevHash = _GetLastBlock().GetHash();
    bNew.MineBlock(_nDifficulty);
    _vChain.push_back(bNew);
}
Block Blockchain::_GetLastBlock() const {
    return _vChain.back();
}


void Blockchain::addTransaction(Transaction tr){


    listOfTransactions.push_back(tr);

//	switch listOfTransactions.size(){
	//	case:

//	}
//	if (listOfTransactions.size())
//	{
		/* code */
//	}

//	if (listOfTransactions.size() < BLOCKSIZE)
//	{
//		listOfTransactions.push_back(tr);
//	}else{
		// createNewBlock() with transactions.
//	}
}
