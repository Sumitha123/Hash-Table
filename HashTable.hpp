//
//  HashTable.hpp
//  Hashing
//
//  Created by Sumitha on 6/2/17.
//  Copyright © 2017 Sumitha. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <ctime>
#include <math.h>
using namespace std;
#ifndef HashTable_hpp
#define HashTable_hpp

class HashTable{
    
    private:
    
    static const int m = 100;
    struct data{
        int key;
        data *next;
    };
     data* hashTable[m];
    
    public :
    
    int getm() const;
    
    HashTable();
    int MulHashFunction(int key, double A);
    int DivHashFunction(int key);
    void InsertByMulHash(int key,double A);
    void InsertByDivHash(int key);
    int NumberOfKeysPerIndex(int index);
    
    
};

#endif /* HashTable_hpp */
