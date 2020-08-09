/*********************
Name: Evan Soloway
Assignment: Hash Tables
File: hashtable.h
Purpose: Hashtable class prototypes and relevant constants named.
**********************/

# ifndef HASH_TABLE_H
# define HASH_TABLE_H
# define HASH_TABLE_SIZE 15

# include <iostream>
# include <string>
# include "linkedlist.h"
# include "data.h"

using std::cout;
using std::endl;
using std::string;

class Hashtable{

    int count;
    int hash(int);
    dLinkedList*hashtable [HASH_TABLE_SIZE];

    public:

    Hashtable();
    ~Hashtable();

    bool insertEntry(int, string);
    string getData(int);
    bool removeEntry(int);
    int getCount();
    void printTable();

/* Please read this comment to understand my reasoning with the printTable() method: 

I've struggled with printTable() because the Hashtable class does not have 
access to the linkedlist head of each linkedlist object in the table and therefore
cannot traverse the linkedlist at a given index in the hashtable. Here are solutions 
I've considered to this problem and my reasons for selecting the one I did.

    1. Create a private attribute idList in hashtable class and allocate as 
    int idList [IDLISTLNGTH] where idListlngth would be declared as constant 
    in preprocessor command (i.e. # define IDLISTLNGTH 100). In method insertEntry(), 
    idList would have the id of the inserted element added to it. In removeEntry(), 
    the given id would be set to NULL. In printTable(), a for loop whose length is
    is the constant IDLISTLNGTH would iterate over the array and print the id it's
    currently pointing to if that id was not equal to null and was equal to current
    table entry index % hash_table_size. Every element in the array would be initilized
    to zero in the constructor.

    TL;DR: 1. Create an idList array and iterate over to print list.

    *The Problem: In the instructions, there was no limit to how long the "separate chain"
    at each table index could be, so how could I know what to make the constant idListLngth?
    For all I know, the separate chain at each table entry could stretch for infinity. 
    I briefly considered making idArray a pointer which would become an allocated array 
    in the constructor, with the idListLngth being passed to the object from main(), but
    decided this over-complicated the object and was arbitrary.

    2. Remove separate linkedlist class entirely and incorporate all necessary methods
    into Hashtable class so that hashtable itself is an array of linkedlist heads rather
    than objects.

    *The Problem: Requires rewriting and rethinking linkedlist design, and overcomplicates
    the Hashtable class, which I feel should exclusively manipulate the hashtable and not deal
    with the exposed linkedlist.

    3. Modify the linkedlist class by either changing the method printList() to reflect
    what's asked in this assignment, or by adding an entirely new method called printIdList().

    *The Problem: Though this is the simplest solution (and therefore best imo), it requires
    changing the linkedlist class from what it was in previous assignment, which would seem
    to violate loose coupling (after all, if I'm changing the class for this, why not then
    change it to not list ids in order, not contain Node*prev attribute in Node, etc.)

I decided on the 3rd solution. There were more variations to these 3 I didn't fully detail. This 
whole problem turned out to be the most provocative and time-consuming of the whole
assignment. If you do object to the 3rd solution and dock points for it, please leave note 
hinting at ideal/common solution which I cannot find.
*/

};

# endif
