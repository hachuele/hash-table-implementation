// Name:Eric J. Hachuel
// Loginid:hachuelb
// CSCI 455 PA5
// Fall 2016


#include <iostream>
#include <cassert>
#include <vector>
#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
  key = theKey;
  value = theValue;
  next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
  key = theKey;
  value = theValue;
  next = n;
}


//*************************************************************************
// put the function definitions for your list functions below

//***************FUNCTION DEFINITIONS***************

int* listFind(ListType & list, string student){
  
    ListType currNode = list;
    
    //Traverse through the linked list - taken from slides
    while(currNode !=NULL){
        
        //check if equal to target
        if(currNode->key == student){
            return &(currNode->value); //return address of value
        }
        
        //update value
        currNode = currNode->next;
        
    }
    //return NULL if not found
    return NULL;
    
}
  
bool listRemove(ListType & list, string student){
    
    //Initialize previous and current Nodes
    ListType currNode;
    
    //Set previous node to NULL
    ListType prevNode = NULL;
    
    //Loop through while pointing to previous node and current nodes
    for(currNode = list; currNode!=NULL; prevNode = currNode, currNode = currNode->next){
        
        //If the student is found
        if(currNode->key == student){
            
            //check if previous is NULL
            if(prevNode != NULL){
                //change next node of previous Node to skip node
                prevNode->next = currNode->next;
            }
            
            else{
                //Change the pointer to the beginning of list
                list = currNode->next;
            }
            //delete memory, return true to signal end loop
            delete currNode;
            return true;
        }
    }
    return false;
}
  
bool listAdd(ListType & list, string student, int score){
    ListType currNode = list;
    list = new Node(student, score, currNode);
    return true;
}


void printList(ListType & list){
    ListType currNode = list;
    
    while(currNode != NULL){
        cout << currNode->key << " " << currNode->value << " " << endl;
        currNode = currNode->next;
    }
}


int listLength(ListType & list){
    
    int length = 0;
    ListType currNode;
    
    for(currNode = list; currNode!=NULL; currNode = currNode->next){
        length++;
    }
    return length;
}