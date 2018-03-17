#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <cstdint>
#include <iostream>
using namespace std;

class Transaction {
public:
    Transaction(uint32_t id,uint32_t _Sent,uint32_t _Produced);
    string GetHash();

private:
    uint32_t _Id;
    uint32_t _Sent;
    uint32_t _Produced;
    // uint32_t _greenPercentage;
    string _sData;
    string _sHash;
    time_t _tTime;

    string _CalculateHash() const;

};
#endif
