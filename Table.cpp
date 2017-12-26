// Name:Eric J. Hachuel
// CSCI 455 PA5
// Fall 2016

// Table.cpp  Table class implementation


/*
 * Modified 11/22/11 by CMB
 *   changed name of constructor formal parameter to match .h file
 */

#include "Table.h"
#include <iostream>
#include <string>
#include <cassert>


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************


Table::Table() {
    
    //Initialize size of table to constant value
    hashSize = HASH_SIZE;
    
    //Set the number of entries to 0
    numberEntries = 0;
    
    //Generate table with hashSize
    hashTable = new ListType[hashSize];
    
    //Initialize all entries to NULL
    for(int i = 0; i<hashSize; i++){
        hashTable[i] = NULL;
    }
}


Table::Table(unsigned int hSize) {
    
    //Initialize size of table to input size
    hashSize = hSize;
    
    //Set the number of entries to 0
    numberEntries = 0;
    
    //Generate table with hashSize
    hashTable = new ListType[hashSize];
    
    //Initialize all entries to NULL
    for(int i = 0; i<hashSize; i++){
        hashTable[i] = NULL;
    }
}


int * Table::lookup(const string &key) {
    
    //get hashCode from name string
    int hashNumber = hashCode(key);
    
    //Create and return pointer to specific bin 
    int * pointerToBin = listFind(hashTable[hashNumber], key);
    return pointerToBin;
   
}

bool Table::remove(const string &key) {
    
    //get hashCode from name string
    int hashNumber = hashCode(key);
    
    //If key is found in bin, remove and decrement number of entries
    if(listRemove(hashTable[hashNumber], key)){
        numberEntries--;
        return true;
    }
    else{
        return false;
    }
}

bool Table::insert(const string &key, int value) {
    
    //get hashCode from name string
    int hashNumber = hashCode(key);
    
    //If key is found in bin, add item and increment number of entries
    if(listAdd(hashTable[hashNumber], key, value)){
        numberEntries++;
        return true;
    }
    return false;
}
   


int Table::numEntries() const {
  return numberEntries;    
}


void Table::printAll() const {
    for(int i = 0; i<hashSize; i++){
        printList(hashTable[i]);
    }
}

void Table::hashStats(ostream &out) const {
    
    out << "number of buckets: " << hashSize << endl;
    out << "number of entries: " << numberEntries << endl;
    out << "number of non-empty buckets: " << nonEmptyBuckets() << endl;
    out << "longest chain: " << longestChainNumber() << endl;
  
}


// add definitions for your private methods here
int Table::nonEmptyBuckets() const{
    
    int nonEmpty = 0;
    for(int i = 0; i < hashSize; i++){
        
        if(hashTable[i] != NULL){
            nonEmpty++;
        }
    }
    return nonEmpty;
}


int Table::longestChainNumber() const{
    
    int finalLongest = 0;
    int currLongest = 0;
    
    for(int i = 0; i < hashSize; i++){
        
        if(hashTable[i] != NULL){
            currLongest = listLength(hashTable[i]);
            
            if(currLongest > finalLongest){
                finalLongest = currLongest;
            }
        }
    }
    return finalLongest;
}