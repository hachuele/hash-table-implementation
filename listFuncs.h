// Name:Eric J. Hachuel
// Loginid:hachuelb
// CSCI 455 PA5
// Fall 2016


//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.


#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H
  
using namespace std;

struct Node {
  string key;
  int value;

  Node *next;

  Node(const string &theKey, int theValue);

  Node(const string &theKey, int theValue, Node *n);
  
};

typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.

//***************FUNCTION HEADERS***************

//Finds specified student in linked listed
//Returns the address of the student's grade
int* listFind(ListType & list, string student);

//Finds and removes specified student from linked list
bool listRemove(ListType & list, string student);

//Adds specified student and its score to the linked list
bool listAdd(ListType & list, string student, int score);

//Prints student score key-value pairs
void printList(ListType & list);

//Returns the length of the specified linked list
int listLength(ListType & list);


#endif
