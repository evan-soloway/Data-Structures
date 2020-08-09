/*********************
Name: Evan Soloway
Assignment: Binary Search Tree
File: bintree.h
Purpose: Provides all preprocessor 
directives and prototypes for class Bintree.
**********************/

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H

# include "data.h"
# include <iostream>
# include <algorithm>
# include <iomanip>

class BinTree{

    private:

    // Attributes
    DataNode*root;
    int count;
    int*debugCount; // REMOVE

    // Overloads for recursion //

    // Adding/Removing
    bool addNode(DataNode*, DataNode**);
    DataNode*removeNode(int, DataNode*);
    DataNode* deleting(int, DataNode*); // removeNode() extension
    DataNode* minValueNode(DataNode*);
    void clear (DataNode*);

    // Getters
    bool getNode(Data*, int, DataNode*);
    int getHeight(DataNode*);

    // Checkers
    bool contains(int, DataNode*);

    // Printers
    void displayPreOrder(DataNode*);
    void displayPostOrder(DataNode*);
    void displayInOrder(DataNode*);
    void allDisplays(); // displayTree() extension

    public:

    BinTree(); // Constructor
    ~BinTree(); // Destructor

    // Adding/Removing
    bool addNode(int, string);  
    bool removeNode(int);
    void clear();

    // Getters
    bool getNode(Data*, int);
    int getHeight();
    int getCount();
    bool getRootData(Data*);

    // Checkers
    bool contains(int);
    bool isEmpty();

    // Printers
    void displayPreOrder();
    void displayPostOrder();
    void displayInOrder();
    void displayTree();

};

#endif /* BINTREE_BINTREE_H */

