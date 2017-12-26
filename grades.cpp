// Name:Eric J. Hachuel
// Loginid:hachuelb
// CSCI 455 PA5
// Fall 2016
/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include <sstream>
#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>


//***************METHOD HEADERS***************

//Inserts this name and score in the grade table. 
//If this name was already present, it does not do the insert.
void insertName(Table* &grades, stringstream &ss);

//Changes the score for name. 
//Print an appropriate message if this name isn't present.
void changeName(Table* &grades,stringstream &ss);

//Looks up the name, and print out his or her score.
//prints out a message if the student is not in the table.
void lookupName(Table* &grades,string name);

//Removes this student. 
//If this student wasn't in the grade table, print a message to that effect. 
void removeName(Table* &grades,string name);

//Prints out all names and scores in the table.
void printAllNames(Table* &grades);

//Prints out the number of entries in the table. 
int getNumEntries(Table* &grades);


//***************METHOD DEFINITIONS***************

void insertName(Table* &grades, stringstream &ss) {
    
    //local variable initialization
    string name; //the name of the student to add
    int score; //the student's score to add
    
    //Save stream inputs from command line into local variables
    ss >> name;
    ss >> score;
    
    //if the name is not found in the table, insert it.
    if(grades->lookup(name) == NULL){
        grades->insert(name, score);
    }
    
    //if the name is found, do nothing and print the following message
    else{
        cout << "The name you seek to add is already present in the table." << endl;
    }
}

void changeName(Table* &grades, stringstream &ss) {
    
    //local variable initialization
    string name; //the name of the student to update score
    int newScore; //the student's new score
    
    //Save stream inputs from command line into local variables
    ss >> name;
    ss >> newScore;
    
    //if the name is found in the table, update its score
    if(grades->lookup(name) != NULL){
        *(grades->lookup(name)) = newScore;
    }
    
    //if the name is not found, no changes are made
    else{
        cout << "The student you seek to change is not present in the table." << endl;
    }
    
}

void lookupName(Table* &grades, stringstream &ss) {
    
    //local variable initialization
    string name; //the name of the student to look up
    
    //Save stream inputs from command line into local variables
    ss >> name;
    
    //if the student is found in the table, print his/her grade to cout
    if(grades->lookup(name) != NULL){
        
        int score = *(grades->lookup(name));
        
        cout << name <<"'s score is: " << score << endl;
    }
    
    else{
        cout << "The student you seek to look up is not present in the table." << endl;
    }
}

void removeName(Table* &grades, stringstream &ss) {
    
    //local variable initialization
    string name; //the name of the student to remove from the table
    
    //Save stream inputs from command line into local variables
    ss >> name;
    
    //if the student is found, remove from table
    if(grades->lookup(name) != NULL){
        grades->remove(name);
    }
    
    else{
        cout << "The student you seek to remove is not present in the table." << endl;
    }
}

void printAllNames(Table* &grades) {
    grades->printAll();
}

int getNumEntries(Table* &grades) {
    return grades->numEntries();
}



int main(int argc, char * argv[]) {

    // gets the hash table size from the command line
    int hashSize = Table::HASH_SIZE;

    Table * grades; // Table is dynamically allocated below, so we can call
    // different constructors depending on input from the user.

    if (argc > 1) {
        hashSize = atoi(argv[1]); // atoi converts c-string to int

        if (hashSize < 1) {
            cout << "Command line argument (hashSize) must be a positive number"
                    << endl;
            return 1;
        }

        grades = new Table(hashSize);

    } else { // no command line args given -- use default table size
        grades = new Table();
    }

    grades->hashStats(cout);

    //initialize inputCommands string for stringstream
    string inputCommands; //the command line input
    string function; //the function called in the command line
    
    //boolean to enable exiting program
    bool quit = false;

    //Loop through until user quits program with 'quit' command
    while (!quit) {
        
        cout << "cmd> ";

        //Get line from command line
        getline(cin, inputCommands);
        
        //Pass input to stringstream ss
        stringstream ss(inputCommands);

        //first stringstream input is the function chosen by the user
        ss >> function;
        
        if (function == "insert") {
            insertName(grades, ss);
        }
        
        else if (function == "change") {
            changeName(grades, ss);
        }
        
        else if (function == "lookup") {
            lookupName(grades, ss);
        }
        
        else if (function == "remove") {
            removeName(grades, ss);
        }
        
        else if (function == "print") {
            printAllNames(grades);
        }
        
        else if (function == "size") {
            cout << getNumEntries(grades) << endl;
        }
        
        else if (function == "stats") {
            grades->hashStats(cout);
        }
        
        else if (function == "help") {
            
            cout << endl;
            cout << "***************HELP COMMAND SUMMARY***************" << endl;
            cout << endl;
            cout << "INSERT COMMAND" << endl;
            cout << "Command sequence: insert name score" << endl;
            cout << "Inserts this name and score in the grade table. If this name was already present, it does not do the insert." << endl;
            cout << endl;
            cout << "CHANGE COMMAND" << endl;
            cout << "Command sequence: change name newscore" << endl;
            cout << "Changes the score for the given name" << endl;
            cout << endl;
            cout << "LOOKUP COMMAND" << endl;
            cout << "Command sequence: lookup name" << endl;
            cout << "Looks up the name, and prints out his or her score, or a message indicating that the student is not in the table" << endl;
            cout << endl;
            cout << "REMOVE COMMAND" << endl;
            cout << "Command sequence: remove name" << endl;
            cout << "Remove given student. If this student wasn't in the grade table, prints a message to that effect." << endl;
            cout << endl;
            cout << "PRINT COMMAND" << endl;
            cout << "Command sequence: print" << endl;
            cout << "Prints out all names and scores in the table." << endl;
            cout << endl;
            cout << "SIZE COMMAND" << endl;
            cout << "Command sequence: size" << endl;
            cout << "Prints out the number of entries in the table." << endl;
            cout << endl;
            cout << "STATS COMMAND" << endl;
            cout << "Command sequence: stats" << endl;
            cout << "Prints out statistics about the hash table at this point." << endl;
            cout << endl;
            cout << "HELP COMMAND" << endl;
            cout << "Command sequence: help" << endl;
            cout << "Prints out currently displayed brief command summary." << endl;
            cout << endl;
            cout << "QUIT COMMAND" << endl;
            cout << "Command sequence: quit" << endl;
            cout << "Exits the program." << endl;
            cout << endl;
            cout << "***************END OF HELP COMMAND SUMMARY***************" << endl;
            cout << endl;
        }
        
        else if (function == "quit") {
            quit = true;
        }
        
        //Invalid command if none of the above functions entered
        else {
            cout << endl;
            cout << "ERROR: Invalid Command" << endl;
            cout << "see 'help' command" << endl;
            cout << endl;
        }
    }
    
    return 0;
}