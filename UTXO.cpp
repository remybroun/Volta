//
//  UTXO.cpp
//  Volta
//
//  Created by Remy Broun on 5/7/18.
//  Copyright © 2018 Remy Broun. All rights reserved.
//

#include "UTXO.hpp"

UTXO::UTXO(int amount, int id):amount(amount), id(id){
    timeStamp = time(nullptr);
}

vector<UTXO> UTXO::splitForChange(int split){
    
    UTXO amountToSend(split,1);
    UTXO change(amount - split,2);
    vector<UTXO> newPair;
    newPair.push_back(amountToSend);
    newPair.push_back(change);
    
    
    return(newPair);
}
