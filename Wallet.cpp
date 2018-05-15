//
//  Wallet.cpp
//  Volta
//
//  Created by Remy Broun on 4/19/18.
//  Copyright © 2018 Remy Broun. All rights reserved.
//

#include <stdio.h>
#include "Wallet.h"

#define INFINITY 1000000000


Wallet::Wallet(){



}
//void Wallet::startTranaction(){}


//Looks to see if there is a Big enough transaction
int Wallet::findBiggerUTXO(int target){
    
    for (int i = 0; i < unspentOutputs.size(); i++) {
        if(unspentOutputs[i].amount > target){
            return i;
        }
    }
    return -1;
}

void Wallet::sendUTXOs(vector<UTXO> UTXOsToSend, int amount){
//    maybe call a script that would parse and send a Transaction
//    for (int i = 0; i < UTXOsToSend.size(); i++) {
//        cout<<"Amount : "<<UTXOsToSend[i].amount<<" Time Stamp : "<<UTXOsToSend[i].timeStamp<<endl;
//    }
}

void Wallet::sendTransaction(Transaction tr){
    //    maybe call a script that would parse and send a Transaction
    //    for (int i = 0; i < UTXOsToSend.size(); i++) {
    //        cout<<"Amount : "<<UTXOsToSend[i].amount<<" Time Stamp : "<<UTXOsToSend[i].timeStamp<<endl;
    //    }
}


//Creates a vector of UTXOs to merge together
vector<UTXO> Wallet::createUTXOInput(int amountNeeded){
    UTXO a = unspentOutputs[0];
    UTXO b = a;
    b.amount = INFINITY;
    int sum = 0;
    vector<UTXO> UTXOs;
    
    for (int i = 0; i < unspentOutputs.size(); i++) {
        if (unspentOutputs[i].amount<a.amount){
            a = unspentOutputs[i];
        }
        
    }
    UTXOs.push_back(a);
    sum += a.amount;
    while (sum < amountNeeded) {// I need to allow same amount transactions...
        for (int i = 0; i < unspentOutputs.size(); i++) {
            if (unspentOutputs[i].amount>=a.amount && unspentOutputs[i].amount<b.amount && a.id != unspentOutputs[i].id){
                b = unspentOutputs[i];
            }
        }
        a = b;
        b.amount = INFINITY;
        UTXOs.push_back(a);
        sum += a.amount;

    }
    return UTXOs;
}


void Wallet::createUTXOtoSend(int amountToSend){
    vector<UTXO> outputsToSend;
    if(calculateAvailableBalance() < amountToSend){
        cerr<<"Insufficient Available Balance";
    }else{
        int x = findBiggerUTXO(amountToSend);
//        If there isn't a big enough UTXO
        if (x == -1) {

            vector<UTXO> smallUTXOS = createUTXOInput(amountToSend);
            outputsToSend = smallUTXOS;
        }else{
//            Create Split when recieved
//            unspentOutputs[x].splitForChange(amountToSend);
            outputsToSend.push_back(unspentOutputs[x]);
        }
    }
    sendUTXOs(outputsToSend, amountToSend);
}


int Wallet::calculateAvailableBalance(){
    
    int balance = 0;
    
    for (int i = 0; i < unspentOutputs.size(); i++) {
        balance+= unspentOutputs[i].amount;
    }
    return balance;
}


void Wallet::addUTXO(UTXO output){
    unspentOutputs.push_back(output);
}
