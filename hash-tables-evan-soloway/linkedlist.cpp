/*********************
Name: Evan Soloway
Assignment: Linked Lists
File: linkedlist.cpp
Purpose: Declares dLinkedList class
**********************/

# include "linkedlist.h"

// addNode() and associated methods below

bool dLinkedList::addHead(int id=-1, string data=""){ // addNode() extension

    head = new Node;

    head->data.id = id;
    head->data.data = data;
    head->next=nullptr;
    head->prev=nullptr;

    return true;
}

bool dLinkedList::nodeCouple(bool success, int id=-1, string data="", // addNode() extension
Node*current=nullptr, Node*newNode=nullptr){

    if(id>current->data.id && !current->next){ // newNode==tail
        current->next = newNode; 
        newNode->prev = current;
        }

    else if(id<current->data.id && !current->prev){ // newNode==head
        current->prev = newNode; 
        newNode->next = current; 
        head = newNode; 
        }

    else{ // newNode==middle (newNode occurs before current node) 
        newNode->prev = current->prev; 
        newNode->next = current; 
        current->prev->next = newNode; 
        current->prev = newNode; 
        } 

    return true;
}

bool dLinkedList::addNode(int id=-1, string data=""){ // set perameters to default -1 and ""; 
                                                      // will return false if default perameters are set
    bool success=false; // flag

    if(id >= 0 && !head){ // newNode is 1st node
        success = this->addHead(id, data);
        } 
    else if(id >= 0 && head){

        Node*current = head;
        Node*newNode = new Node;
        newNode->data.id = id;
        newNode->data.data = data;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        while(id > current->data.id && current->next){
            current=current->next;
            }
        if(id!=current->data.id){ // test if dupe ids are present
            success = nodeCouple(success, id, data, current, newNode);
            } 
        }
    return success;
}

bool dLinkedList::deleting(Node*current){ // deleteNode() extension

    if(!current->next && !current->prev){ // current==only node in list
        head = nullptr;
        }

    else if(!current->prev){ // current==head
        head = current->next;
        current->next->prev = nullptr;                
        }

    else if(!current->next){ // current==tail
        current->prev->next = nullptr;                
        }

    else{ // current==middle
        current->prev->next = current->next;
        current->next->prev = current->prev;
        }

    delete current;
    return true;
}

bool dLinkedList::deleteNode(int id = -1){

    bool success = false;

    if(id >= 0 && head){ // do not enter method body if id's invalid or list is empty

        Node*current = head; // allocating current at head

        while(!(id==current->data.id) && current->next){ // increment until current=tail or current->id=target id
            current = current->next; 
            }

        if(id==current->data.id){ // current==target for deletion
            success=deleting(current);
            }

        }

    return success;

}

bool dLinkedList::getNode(int id=-1, Data*dummyData=nullptr){ 

    bool success = false;

    if(id >= 0 && head){  // i.e. do not enter unless conditions for successful 
                          // "getting" are present. Placing conditional here
                          // also prevents segmentation fault (e.g. would seg fault
                          // if trying to access current->next when head=nullptr)

        Node*current = head;

        while(current->next && id != current->data.id){ // increment until end of list or id==current->id
            current = current->next;
            }

        if(id==current->data.id){ // current==target
            dummyData->data = current->data.data; 
            dummyData->id = current->data.id;
            success = true;
            }
        }

    return success;

}

void dLinkedList::printForward(Node*current){ // printList() extension

    int index = 0;

    while(current){ 
        std::cout << "Node " << index << "'s id is " << current->data.id << std::endl;
        std::cout << "Node " << index << "'s data is " << current->data.data << "\n\n";
        index++;
        current = current->next; 
        }
}

void dLinkedList::printBackward(Node*current){ // printList() extension

    int index = this->getCount()-1;

    while(current->next){ // increment to tail
        current = current->next;
        }

    while(current){ 
        std::cout << "Node " << index << "'s id is " << current->data.id << std::endl;
        std::cout << "Node " << index << "'s data is " << current->data.data << "\n\n";
        index--;
        current = current->prev; 
        }
}

void dLinkedList::printList(bool printBackward){ 

    if(head){ // check that list isn't empty

        Node*current = head;

        if(printBackward){
            this->printBackward(current);    
            }

        else{
            this->printForward(current);
            }
        }

    else{
        std::cout << "List is empty." << std::endl; 
        }

}

void dLinkedList::printIDList(){

    Node*current=head;

    while(current){
        std::cout << current->data.id << "-->";
        current=current->next;
        }
}

int dLinkedList::getCount(){

    int count=0;

    if(head){ // check that list isn't empty

    Node*current = head;

    while(current){
        count++;
        current = current->next; 
        }
    }

    return count;
}

bool dLinkedList::clearList(){

    bool success = false;
    int count=0;
    int length = this->getCount(); 

    Node*current = head;
    Node*tmpNode; // for holding and deleting current node so that "current" can still be incremented

    while(current){  
        count++;
        tmpNode = current; // assign current node to tmp
        current = current->next; // increment current
        delete tmpNode; // delete tmp node
        }

    head=nullptr;

    if(length==count){
        success=true;
        }

    return success;
}

bool dLinkedList::exists(int id=-1){ // default perameter is -1

    bool success = false;

    Node*current = head;

    while(id != current->data.id && current->next){ 
        current = current->next; 
        }

    if(id==current->data.id){
        success=true;
        }

    return success;
}

dLinkedList::~dLinkedList(){ // destructor
    this->clearList();
}

