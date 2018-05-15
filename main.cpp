#include "Blockchain.h"
#include "Block.h"
#include <stdlib.h>
#include "Wallet.h"
#include "Transaction.h"
#include "Node.hpp"
//#include "mykernel.cl.h"
//
//#ifdef __APPLE__
//#include <OpenCL/opencl.h>
//#else
//#include <CL/cl.h>
//#endif


int main() {
//    Blockchain bChain = Blockchain();
    
//    Block bl1 = Block(1,"number1");
//    for(int i = 0; i<1000;i++){
//        bChain.addTransaction(Transaction(1,20,30));
//    }
//
//
//

    Node n = Node();
    n.generateKeyPair();
    
    Wallet w = Wallet();
    for (int i = 1 ; i < 20; i++) {
        w.addUTXO(UTXO(i,i));
    }
    
    cout<<endl<<w.calculateAvailableBalance()<<endl;
    w.createUTXOtoSend(48);
    
    return 0;
}
