#include "sha256.h"
#include <sstream>
#include <time.h>
#include "Transaction.h"



Transaction::Transaction(uint32_t id,uint32_t _Sent,uint32_t _Produced) : _Id(id), _Sent(_Sent), _Produced(_Produced){
    _tTime = time(nullptr);
    _sHash = _CalculateHash();
}


inline string Transaction::_CalculateHash() const {
    stringstream ss;
    ss <<_Id<<_tTime<<_Sent<<_Produced<<_sData;

    return sha256(ss.str());
}

string Transaction::GetHash(){
   	return _sHash;
}
