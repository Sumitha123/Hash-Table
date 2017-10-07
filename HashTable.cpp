//
//  HashTable.cpp
//  Hashing
//
//  Created by Sumitha on 6/2/17.
//  Copyright © 2017 Sumitha. All rights reserved.
//

#include "HashTable.hpp"
using namespace std;

HashTable :: HashTable(){
    for(int i = 0; i < m; i ++){
        hashTable[i] = new data;
        hashTable[i] -> key = NULL;
        hashTable[i] -> next = NULL;
    }
}
int HashTable :: getm() const{
    return m;
}


int HashTable :: MulHashFunction(int key, double A){
    
    int index = floor(m*(fmod((key*A),1)));
    return index;
}

int HashTable :: DivHashFunction(int key){
    int index = key % m;
    return index;
}


void HashTable :: InsertByMulHash(int key, double A){
    
    int index = MulHashFunction(key,A);
    //Inspecting the bucket associated with the index
    if (hashTable[index] -> key == (int)NULL){
        
        hashTable[index] -> key = key;
        
    }
    else{
        data* Ptr = hashTable[index];
        data* New = new data;
        New -> key = key;
        New -> next = NULL;
        while(Ptr -> next != NULL){
            Ptr = Ptr -> next;
        }
        Ptr -> next = New;
        

    }

 
}

void HashTable :: InsertByDivHash(int key){
    
    int index = DivHashFunction(key);
    //Inspecting the bucket associated with the index
    if (hashTable[index] -> key == (int)NULL){
        
        hashTable[index] -> key = key;
        
    }
    else{
        data* Ptr = hashTable[index];
        data* New = new data;
        New -> key = key;
        New -> next = NULL;
        while(Ptr -> next != NULL){
            Ptr = Ptr -> next;
        }
        Ptr -> next = New;
        
        
    }
    
    
}
int HashTable :: NumberOfKeysPerIndex(int index){
    int count = 0;
    if(hashTable[index] -> key ==  (int)NULL){
        return count;
   
    }
    else{
        count++;
        data* Ptr = hashTable[index];
        while(Ptr->next != NULL){
            count++;
            Ptr = Ptr -> next;
        }
    }
    return count;
    
}
