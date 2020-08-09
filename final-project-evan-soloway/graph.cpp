/*********************
Name: Evan Soloway
Assignment: Final Project
File: graph.cpp
Purpose:  Graph class declaration
**********************/

# include "graph.h"

Graph::Graph(){

    for(int x=0; x<OG_VERTICES;x++){
        ogVertices[x] = nullptr;
        }

}

Graph::~Graph(){

    Vertex*temp;

    for(int x=0; x<OG_VERTICES;x++){

        while(ogVertices[x]){
            temp = ogVertices[x];
            ogVertices[x] = ogVertices[x]->link;
            delete temp;
            }
       
        }

}

// Adding/Removing
bool Graph::addVertice(int id=-1, string data=""){

    bool success = false;
    bool noVertices = true;
    int availableIndex = 0;

   for(int x;x<OG_VERTICES;x++){
        if(ogVertices[x]){
            noVertices = false;    
            availableIndex = x;  
            }
        }

    if(noVertices){ // if no nodes have been allocated
        createOg(id, data);
        }

    else{ // if vertices are available to join new node to
        nodeJoin(id, data, availableIndex);
        }

    return success;
}

void Graph::createOg(int id, string data){ // addvertice() extension

    int vListHead = 0;
  
    ogVertices[0] = new Vertex;
    ogVertices[0]->link = nullptr;
    ogVertices[0]->data.id = id;
    ogVertices[0]->data.data = data;

    for(int x=0;x<30;x++){

        if(!vList[x]){
            vListHead = x;               
            }

        }
    
    vList[vListHead] = new Node;
    vList[vListHead]->next = ogVertices[0];

return;   
}

void Graph::nodeJoin(int id, string data, int index){ // addvertice() extension

    int vListHead = 0;
    Vertex*newVertex = new Vertex;

    newVertex = new Vertex;
    newVertex->link = ogVertices[index];
    newVertex->data.id = id;
    newVertex->data.data = data;

    for(int x=0;x<30;x++){

        if(!vList[x]){
            vListHead = x;               
            }

        }    

    vList[vListHead] = new Node;
    vList[vListHead]->next = newVertex;

return;
}

bool Graph::addEdge(Vertex*newNode){

    bool success = false;

    if(!newNode){
        newNode = new Vertex;
        }

    for(int x=0; x<OG_VERTICES;x++){ // iterating over all initial vertices for open link

        while(ogVertices[x]){

            if(!ogVertices[x]->link){
                ogVertices[x]->link = newNode;
                success = true;
                }

            ogVertices[x] = ogVertices[x]->link;
            }  

        }

return success;
}
