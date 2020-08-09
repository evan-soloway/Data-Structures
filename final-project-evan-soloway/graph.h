/*********************
Name: Evan Soloway
Assignment: Final Project
File: graph.h
Purpose: Graph class prototypes
**********************/

# ifndef GRAPH_H
# define GRAPH_H

# include "data.h"
# define OG_VERTICES 5

class Graph{

    public:

    Graph();
    ~Graph();

    // Adding/Removing
    bool addVertice(int, string);
    bool addEdge(Vertex*);

    // Traversals
    void breadthFirstTraversal();
    void beadthFirstTraversal();

    private:

    Vertex*ogVertices [OG_VERTICES];
    Node*vList [30]; // array for storing linear paths of nodes

    // Adding/Removing
    void createOg(int, string);
    void nodeJoin(int, string, int);

};

# endif // GRAPH_H
