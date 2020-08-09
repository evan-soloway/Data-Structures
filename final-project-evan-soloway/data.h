/*********************
Name: Evan Soloway
Assignment: Final Project
File: data.h
Purpose: A repository for
all structs relevant to
the project.
**********************/

#ifndef DATA_H
#define DATA_H

#include <string>
using std::string;

struct Data {
    int id;
    string data;
};

struct Vertex {
    Data data;
    Vertex*link;
};

struct Node { // for listing linear path of ogVertices
    Data data;
    Vertex*next;

};

#endif /* DATA_H */
