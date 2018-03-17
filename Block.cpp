#include "Block.h"
#include "sha256.h"
#include <sstream>
#include <time.h>
#include "Transaction.h"


Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn) {
    _nNonce = -1;
    _tTime = time(nullptr);
}

string Block::GetHash() {
    return _sHash;
}

void Block::MineBlock(uint32_t nDifficulty) {
    char cstr[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';

    string str(cstr);

    do {
        _nNonce++;
        _sHash = _CalculateHash();
        cout<<"Attempt"<<_nNonce<<endl<<_sHash<<endl;
    } while (_sHash.substr(0, nDifficulty) != str);

    cout << "Block mined: " << _sHash << endl;
}

inline string Block::_CalculateHash() const {
    stringstream ss;
    ss << _nIndex << _tTime << merkleHash << _sData << _nNonce << sPrevHash;

    return sha256(ss.str());
}

void Block::addTransaction(Transaction _tr){
    if (_vTransactions.size() < 10)
    {
        _vTransactions.push_back(_tr);
    }else{

    }
}

vector<string> merkleTableDivider(vector<string> leaves){

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

void Block::calculateMerkle(){
    vector<string> trHashes;

    // converting transaction to string
    for (int i = 0; i < _vTransactions.size(); i++)
    {
        trHashes.push_back(_vTransactions[i].GetHash());
    }

    while(trHashes.size() > 2){
        for(int i = 0; i < trHashes.size(); i++){
            cout<<trHashes[i]<<endl;
        }

        trHashes = merkleTableDivider(trHashes);
        cout<<"newLevel"<<endl;
    }
    string merkleroot = trHashes[0];
    cout<<"merkle root : "<<merkleroot<<endl;

}

unsigned int Block::numberOfTransactions(){
    return _vTransactions.size();
}


