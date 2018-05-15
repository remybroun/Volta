//
//  Node.hpp
//  Volta
//
//  Created by Remy Broun on 4/20/18.
//  Copyright © 2018 Remy Broun. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <string>
using namespace std;


class Node{
public:
    int Id;
    int wattage;
    void generateKeyPair();
    void getKeyFromFile(string file);
    
    
private:
    void mine();
    void getPrivateKey();
    void getPublicKey();

};
#endif /* Node_hpp */
