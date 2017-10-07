//
//  main.cpp
//  Hashing
//
//  Created by Sumitha on 6/1/17.
//  Copyright © 2017 Sumitha. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <math.h>
#include "HashTable.hpp"
using namespace std;

int main() {
    
    int length = 100000;
    int* a = new int[length];
    int range = 1000;
    double A = 0.2;
    int noOfTimes = 5;
    
    
        
    //Set the seed
    srand ((unsigned int)time(0));
    
    HashTable hashObj;
    int* result = new int[hashObj.getm()];

    //Chaining by multiplicative hashing
    for(int j = 0 ; j < noOfTimes; j++){
        for(int i = 0; i < length; i++){
            //Creates random numbers between 0 and 1000.
            a[i] = rand() % (range + 1);
            hashObj.InsertByMulHash(a[i],A);
        }
        
        for(int i = 0; i < hashObj.getm(); i++){
        
            result[i] = hashObj.NumberOfKeysPerIndex(i);
            
        }
       
    }
    
    for(int i = 0; i <  hashObj.getm(); i++){
        
        cout  << result[i]/noOfTimes<< endl;
    }

    //Chaining by division hashing
   for(int j = 0 ; j < noOfTimes; j++){
        for(int i = 0; i < length; i++){
            //Creates random numbers between 0 and 1000.
            a[i] = rand() % (range + 1);
            hashObj.InsertByDivHash(a[i]);
        }
        
        for(int i = 0; i < hashObj.getm(); i++){
          result[i] = hashObj.NumberOfKeysPerIndex(i);
            
        }
    
    }
    
    for(int i = 0; i <  hashObj.getm(); i++){

        cout  << result[i]/noOfTimes << endl;
    }
    return 0;
    
}
