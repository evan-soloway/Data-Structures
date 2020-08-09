/* 
 * File: data.h
 * Author: Alex Katrompas
 * 
 * DO NOT MODIFY THIS FILE
 * LEAVE THIS COMMENT HEADER HERE
 */

#ifndef DATA_H
#define DATA_H

#include <string>
using std::string;

struct Data {
    int id;
    string data;
};

/*
Despite header at top, I *did* modify this 
to include struct Node. I believe in lecture
you said this was Ok.
*/

struct Node {
    Data data;
    Node *next;
    Node *prev;
};

#endif /* DATA_H */

