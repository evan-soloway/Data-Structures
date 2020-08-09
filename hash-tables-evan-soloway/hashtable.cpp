/*********************
Name: Evan Soloway
Assignment: Hash Tables
File: hashtable.cpp
Purpose: Provides all preprocessor directives and prototypes for class Hashtable.
**********************/

# include "hashtable.h"

Hashtable::Hashtable(){
    count=0;
    for(int i=0;i<HASH_TABLE_SIZE;i++){
        hashtable[i]=nullptr;
        }
}

Hashtable::~Hashtable(){

    count=0;

    for(int i=0;i<HASH_TABLE_SIZE;i++){ 
    
        if(hashtable[i]){
            delete hashtable[i];
            }
        }
}

int Hashtable::hash(int id){

    int hash=id%HASH_TABLE_SIZE;

    return hash;
}

bool Hashtable::insertEntry(int id, string data){

    bool success=false;

    if(id>0){ // skip if id less than zero with false return value

        int hashIndex = this->hash(id);

        if(!hashtable[hashIndex]){ // if hash index unallocated
            hashtable[hashIndex] = new dLinkedList; // allocates object at index
            }

        success = hashtable[hashIndex]->addNode(id, data); // return value from linkedlist object determines success
        }

    if(success){
        count++;
        }

    return success;
}

string Hashtable::getData(int id){

    string data = "object not found";
    bool success=false;
    Data*returnObjct=new Data;
    int hashIndex = this->hash(id);

    if(hashtable[hashIndex]){ // skip if no list at index
        success = hashtable[hashIndex]->getNode(id,returnObjct); // modifies returnObjct pntr
        }

    if(success){
        data = returnObjct->data;
        }

    return data;

}

bool Hashtable::removeEntry(int id){

    bool success = false;
    int hashIndex = this->hash(id);

    if(!hashtable[hashIndex]){ // if no allocated linkedlist at index
        return success;
        } 

    else if(hashtable[hashIndex]->getCount()==1 && hashtable[hashIndex]->exists(id)){ // deletes entire linkedlist object and sets pointer to null if only 1 item sits in the index (i.e. only a head on linked list)
        delete hashtable[hashIndex]; 
        hashtable[hashIndex]=nullptr; 
        success=true;
        } 

    else if(hashtable[hashIndex]->exists(id)){ // if id exists as node in linkedlist object at this index
        success = hashtable[hashIndex]->deleteNode(id);
        }

    if(success){
        count--;    
        }

    return success;
}

int Hashtable::getCount(){
return count;
}

void Hashtable::printTable(){

    for(int i=0;i<HASH_TABLE_SIZE;i++){

        cout << "Entry " << i+1 << ": ";

        if(!hashtable[i]){ // print empty if unallocated linkedlist object
            cout << "EMPTY";
            }     

        else{     
            hashtable[i]->printIDList(); 
            } 
        
        cout << endl;
        }
}
