//
//  UTXO.hpp
//  Volta
//
//  Created by Remy Broun on 5/7/18.
//  Copyright © 2018 Remy Broun. All rights reserved.
//

#ifndef UTXO_hpp
#define UTXO_hpp

#include <stdio.h>
#include <vector>
using namespace std;

class UTXO {
    
    
public:
    UTXO(int amount,int id);
    int amount;
    time_t timeStamp;
    vector<UTXO> splitForChange(int split);
    unsigned int id;
private:
    
    
    
};
#endif /* UTXO_hpp */
