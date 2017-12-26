// Name:Eric J. Hachuel
// CSCI 455 PA5
// Fall 2016

// pa5list.cpp
// a program to test the linked list code necessary for a hash table chain

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"


int main() {
    
    ListType a = new Node("Bruno", 100);
    listAdd(a, "Eric", 80);
    listAdd(a, "Teague", 70);
    listAdd(a, "Pablo", 100);
    listAdd(a, "Pablo", 120);
    listAdd(a, "Jesus", 130);
    
    cout << "The list length is:" << listLength(a) <<endl;
    
    printList(a);
    
    listRemove(a, "Eric");
    printList(a);
    listRemove(a, "Teague");
    printList(a);
    listRemove(a, "Bruno");
    printList(a);
    listRemove(a, "Pablo");
    printList(a);
    listRemove(a, "Pablo");
    printList(a);
    listRemove(a, "Pablo");
    printList(a);
    
    cout << "The list length is:" << listLength(a) <<endl;
    
  return 0;
  
}
