
#ifndef WALLET_H
#define WALLET_H

#include "Transaction.h"
#include <string>
#include <vector>
#include "UTXO.hpp"

class Wallet{

public:
	Wallet();
	string getPublicKey(){return publicKey;}
	string getPrivateKey();
	void requestTransaction(Transaction);
	Transaction recieveTransaction();
    int calculateAvailableBalance();
    void addUTXO(UTXO output);
//    void startTranaction();
    void createUTXOtoSend(int amountToSend);


private:
	string privateKey;
	string publicKey;
	float availableBalance;
    vector<Transaction> trRecieved;
    vector<Transaction> trSent;
    vector<UTXO> unspentOutputs;
//    Creates an Output with remaining small Outputs (Called Input)
    vector<UTXO> createUTXOInput(int amountNeeded);
    
    void sendUTXOs(vector<UTXO> UTXOsToSend, int amount);
    void sendTransaction(Transaction tr);
    int findBiggerUTXO(int target);
};

#endif
