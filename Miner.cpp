//
//  Miner.cpp
//  Volta
//
//  Created by Remy Broun on 5/4/18.
//  Copyright © 2018 Remy Broun. All rights reserved.
//

#include "Miner.h"
#include "sha256.h"
#include <sstream>

//
//
//

Miner::Miner(): isMining(false){
    
}

void Miner::startMining(){
    isMining = true;
    
//    Call miningProgram();
    
}

//
//void Miner::AddBlock(Block bNew) {
//    bNew.sPrevHash = _GetLastBlock().GetHash();
//    bNew.MineBlock(_nDifficulty);
//    _vChain.push_back(bNew);
//}

Block Miner::createBlock(){
    Block block(0);
//  Get list of Transactions
//  Calculate Merkle root
//  Calculate Number of trxs
//  Calculate Block hash


    //    calculate ;
    
    return block;
}



vector<string> merkleTableBranch(vector<string> leaves){

    vector<string> branch;
    for (int i = 0; i < leaves.size(); i+=2)
    {
        stringstream ss;
        if(i+1 < leaves.size()){
            ss << leaves[i] << leaves[i+1];
        }else{
            ss << leaves[i];
        }
        string hash = sha256(ss.str());
        branch.push_back(hash);
    }
    return branch;
}

string Miner::calculateMerkle(vector<Transaction> _vTransactions){

    vector<string> trHashes;

    // converting transaction to string
    for (int i = 0; i < _vTransactions.size(); i++)
    {
        trHashes.push_back(_vTransactions[i].GetHash());
    }

    while(trHashes.size() > 2){
        trHashes = merkleTableBranch(trHashes);
    }

     return trHashes[0];
    //    cout<<"merkle root : "<<merkleHash<<endl;
}

inline string Miner::_CalculateBlockHash() const {

    int64_t _nNonce = -1;
    time_t _tTime = time(nullptr);
    uint32_t _nIndex = 0;
    string merkleHash = "";
    string sPrevHash = "";


    stringstream ss;
    ss << _nIndex << _tTime << merkleHash << _nNonce << sPrevHash;
    return sha256(ss.str());
}
//
//
void Miner::mineBlock(uint32_t nDifficulty){
    int64_t _nNonce = -1;
    string _sHash = "";

    char cstr[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';

    string str(cstr);

    do {
        _nNonce++;
        _sHash = _CalculateBlockHash();
    } while (_sHash.substr(0, nDifficulty) != str);

    cout << "Block mined: " << _sHash << endl;

}
//
//
//
