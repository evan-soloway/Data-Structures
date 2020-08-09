/*********************
Name: Evan Soloway
Assignment: Linked Lists
File: linkedlist.h
Purpose: Provides all preprocessor 
directives and prototypes for linkedlist.cpp.
**********************/

# ifndef LINKED_LIST
# define LINKED_LIST

# include "data.h"
# include <iomanip>
# include <string>
# include <stdlib.h>
# include <iostream>
# include <new>

class dLinkedList{

    private:

    Node*head=nullptr; 

    bool addHead(int, std::string);
    bool nodeCouple(bool, int, std::string, Node*, Node*);
    bool deleting(Node*);
    void printForward(Node*);
    void printBackward(Node*);

    public:

    bool addNode(int, std::string);
    bool deleteNode(int);
    bool getNode(int,Data*);
    void printList(bool=false);
    int getCount();
    bool clearList();
    bool exists(int);
    ~dLinkedList();

};

# endif
