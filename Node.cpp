//
//  Node.cpp
//  Volta
//
//  Created by Remy Broun on 4/20/18.
//  Copyright © 2018 Remy Broun. All rights reserved.
//

#include "Node.hpp"
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;




void Node::generateKeyPair(){
    
    
    system("mkdir keys");

//    Generate private key
    system("openssl ecparam -name secp256k1 -out keys/secp256k1.pem");
    system("openssl ecparam -in keys/secp256k1.pem -genkey -noout -out keys/privateKey.pem");
    

    
//    Generate public key from private key
//    openssl ec -in ecprivkey.pem -pubout -out ecpubkey.pem
    system("openssl ec -in keys/privateKey.pem -pubout -out keys/publicKey.pem");
    getKeyFromFile("keys/publicKey.pem");
}

// Function to get Public Key
void Node::getKeyFromFile(string fileName){
    
    string line;
    string key;
    string file;
    
    ifstream myfile (fileName);
    if (myfile.is_open())
    {
        while (getline (myfile,line))
        {
            file+=line;
            cout << line <<endl<<endl;
        }
        myfile.close();
    }
    
//    Find beginning of key
    size_t startIndex = file.find("KEY-----");
    
//    Shift right by "KEY-----"
    startIndex+=8;
    if (startIndex == string::npos) {
        cout<<"This is not a key file"<<endl;
    }
    
    
    // Looking for the end delimiter
    string::size_type endIndex = file.find( "-----END", startIndex );
    
//    Start index, length to substring
    key = file.substr( startIndex, endIndex - (file.length() - endIndex));
    
    cout<<key;
    
    
}
