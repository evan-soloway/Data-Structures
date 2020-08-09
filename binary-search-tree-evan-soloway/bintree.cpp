/*********************
Name: Evan Soloway
Assignment: Binary Search Tree
File: bintree.cpp
Purpose: Declares Bintree class.
**********************/

#include "bintree.h"

BinTree::BinTree(){
    root = NULL;
    count = 0;
}

BinTree::~BinTree(){
    clear();
}

// Public //

// Adding/Removing
bool BinTree::addNode(int id, string data){

    bool success=false;

    if(id > 0){ // assuming this is only criteria for "good" data

        DataNode* node = new DataNode;
        node->data.id = id;
        node->data.information = data;

        success = addNode(node, &root);

        if(success){
            count++;        
            }

        }

    return success;
}

bool BinTree::removeNode(int id){

    bool success = false;
    int tempCount = count;

    root = removeNode(id, root);

    if(count < tempCount){
        success = true;
        }

    return success;

}

void BinTree::clear(){
    clear(root);
    count = 0;
}

// Getters
bool BinTree::getNode(Data*dummy, int id){
    
    bool success = false;

    if(id > 0){ // skip if id invalid    
        success = getNode(dummy, id, root);
        }

    return success;
}

int BinTree::getHeight(){

    int height = 0;
    
    if(root){
        height = getHeight(root);
        }

    return height;
}

int BinTree::getCount(){ 
    return count;
}

bool BinTree::getRootData(Data*node){ 

    bool success = false;

    if(root){   

        node->id = root->data.id;
        node->information = root->data.information;

        success = true;

        }

    else{

        node->id = -1;
        node->information = "";
        }

    return success;
}

// Checkers
bool BinTree::contains(int id){

    bool success = false;

    if(id > 0){ // instructions said to "verify" id before recurring, which
                // I assume means checking that the id is valid, but I don't
                // understand why this is necessary when addNode() doesn't
                // allow nodes with invalid ids to be created in the first place
        success = contains(id, root);
        }

    return success;

}

bool BinTree::isEmpty(){ 

    bool success = false;    

    if(!count){ // checks if count==0
        success = true;
        }

    return success;

}

// Printers
void BinTree::displayPreOrder(){
    displayPreOrder(root);
}

void BinTree::displayPostOrder(){
    displayPostOrder(root);
}

void BinTree::displayInOrder(){
    displayInOrder(root);
}

void BinTree::displayTree(){   // When possible I made a point to *not* 
                               // call the public getter for a display 

    if(!count){
        std::cout << "Tree is empty" << std::endl;
        }

    else{
        std::cout << "Tree is NOT empty" << std::endl;
        }

    std::cout << "Height: " << getHeight() << std::endl; // Using public so that if // POSSIBLY
                                                         // root==null height is not rh+1
    std::cout << "Node Count: " << count << std::endl;

    std::cout << std::endl;
    allDisplays();
}

// Private //

// Adding/Removing
bool BinTree::addNode(DataNode*newNode, DataNode**root){

    if(*root){ // skip if root is empty

        if(newNode->data.id < (*root)->data.id){
            std::cout << ".LEFT."; // REMOVE
            addNode(newNode, &((*root)->left));
            }
        
        else if(newNode->data.id > (*root)->data.id){
            addNode(newNode, &((*root)->right));
            }

        }

    else{ // if new node is first node
        *root = new DataNode; // (i.e. root = new DataNode)
        (*root)->data.id = newNode->data.id;
        (*root)->data.information = newNode->data.information;
        (*root)->left = NULL;
        (*root)->right = NULL;
        }

    return true;
}

DataNode* BinTree::removeNode(int id, DataNode*root){

    if(root){ // skip if root is empty

        if(id < root->data.id){
            removeNode(id, root->left);   
            }

        else if(id > root->data.id){
            removeNode(id, root->right);            
            }

        else{
            root = deleting(id, root);
            }    

        }

    return root;

}

DataNode* BinTree::deleting(int id, DataNode*currentRoot){ // removeNode() extension
    DataNode*temp = new DataNode;  

    if(currentRoot->left == NULL){
        temp = currentRoot->right;
        delete currentRoot;
        currentRoot = temp;     
        count--;     
        }

    else if(currentRoot->right == NULL){
        temp = currentRoot->left;
        delete currentRoot;
        currentRoot = temp;      
        count--;         
        }

    else{
        temp = minValueNode(currentRoot->right);
        currentRoot->data.id = temp->data.id;
        currentRoot->data.information = temp->data.information;
        currentRoot->right = removeNode(temp->data.id, currentRoot->right);             
        }   
    return currentRoot;
}

DataNode* BinTree::minValueNode(DataNode* node){ // removeNode() extension

    DataNode* current = node;

    while(current && current->left != NULL){
        current = current->left;
        }

    return current;

}

void BinTree::clear(DataNode*root){
    
    if(root){ // skip if no root
        clear(root->left);
        clear(root->right);
        root->left = NULL;
        root->right = NULL;
        delete root;
        }

return; 
}

// Getters
bool BinTree::getNode(Data*dummy, int id, DataNode*root){

    bool success = false;

    if(root){ // skip if root is empty

        if(root->data.id == id){
            dummy->id = root->data.id;
            dummy->information = root->data.information;
            success = true;        
            }

        else if(id < root->data.id){
            success = getNode(dummy, id, root->left);
            }

        else if(id > root->data.id){
            success = getNode(dummy, id, root->right);
            }

        }

    return success;
}

int BinTree::getHeight(DataNode*root){

    int lh = 0;
    int rh = 0;
    int returnValue = 0;

    if(root){ // skip if root==null
        lh = getHeight(root->left);
        rh = getHeight(root->right);
        returnValue = std::max(lh+1, rh+1);
        }

    return returnValue;

}

// Checkers
bool BinTree::contains(int id, DataNode*root){

    bool success = false;

    if(root){ // skip if root is empty

        if(root->data.id == id){
            success = true;        
            }

        else if(id < root->data.id){
            success = contains(id, root->left);
            }

        else if(id > root->data.id){
            success = contains(id, root->right);
            }
        
        }

    return success;
}

// Printers
void BinTree::displayPreOrder(DataNode* root){

    if(root){

        std::cout << root->data.id << " " << root->data.information << std::endl;

        if(root->left){
            displayPreOrder(root->left);
            }

        if(root->right){
            displayPreOrder(root->right);
            }

        }

return;
}

void BinTree::displayPostOrder(DataNode* root){

    if(root){

        if(root->left){
            displayPostOrder(root->left);
            }

        if(root->right){
            displayPostOrder(root->right);
            }

        std::cout << root->data.id << " " << root->data.information << std::endl;

        }

return;
}

void BinTree::displayInOrder(DataNode* root){

    if(root){

        if(root->left){
            displayInOrder(root->left); 
            }

        std::cout << root->data.id << " " << root->data.information << std::endl;

        if(root->right){
            displayInOrder(root->right);
            }

        }

return;
}

void BinTree::allDisplays(){

    std::cout << "Pre-Order Traversal: " << std::endl;
    displayPreOrder(root); // calling private displayPreOrder method
    std::cout << std::endl;

    std::cout << "In-Order Traversal: " << std::endl;
    displayInOrder(root); 
    std::cout << std::endl;

    std::cout << "Post-Order Traversal: " << std::endl;
    displayPostOrder(root); 
    std::cout << std::endl;

return;
}
