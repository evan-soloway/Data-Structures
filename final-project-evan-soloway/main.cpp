/*********************
Name: Evan Soloway
Assignment: Final Project
File: main.cpp
Purpose: To test durability of
graph class and objects.
**********************/

# include "main.h"

int main(){

    Graph graph;

    cout << "Hard coding set of vertices: " << endl;

    cout << "Adding 10, Fischer... ";

    if(graph.addVertice(10, "Fischer")){
        cout << "success." << endl;
        }

    else{
        cout << "failure." << endl;
        }

    cout << "Adding 20, Rubin... ";

   if(graph.addVertice(20, "Rubin")){
        cout << "success." << endl;
        }

    else{
        cout << "failure." << endl;
        }

    cout << "Adding 40, Mcconnell... ";
    
   if(graph.addVertice(40, "Mcconnell")){
        cout << "success." << endl;
        }

    else{
        cout << "failure." << endl;
        }

    return 0;
}
