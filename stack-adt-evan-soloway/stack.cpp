/*********************
Name: Evan Soloway
Assignment: Coding 03: Stacks Part 2
File: stack.cpp
Purpose: Declares stack methods for Stack class.
**********************/

#include "stack.h"

Stack::Stack(){
	top = -1;
}

Stack::~Stack(){
    for(top=top;top>=BOTTOM;top--){
        delete stack[top];
        }
}

bool Stack::push(int NEWid, string NEWdata){

    bool noOverflow = false;

    if(!NEWdata.empty() && NEWid>=0 && top < STACK_SIZE-1){ 
        Data*tempData = new Data;
        noOverflow = true;
        tempData->id = NEWid;
        tempData->data = NEWdata;
        stack[++top] = tempData;        
        }

    return noOverflow;
}

bool Stack::peek(Data*peekValue){
	
    bool result = false;

    if (top<BOTTOM){

        peekValue->id = -1;
        peekValue->data = ""; 
        }

    else{
        result = true;
        peekValue->id = stack[top]->id;
        peekValue->data = stack[top]->data; 
        }

    return result; 
	
}

bool Stack::pop(Data*popValue){

    bool result = false;

    if (top<BOTTOM){
        popValue->id = -1;
        popValue->data = ""; 
        }
    else{
        popValue->id = stack[top]->id;
        popValue->data = stack[top]->data;
        delete stack[top--]; 
        result = true;
        }

    return result; 
}

bool Stack::isEmpty(){
	
    bool empty;

    if(top<BOTTOM){
        empty = true;
        }

    else{
        empty = false;
        }

    return empty;
	
}
