/*********************
Name: Evan Soloway
Assignment: Coding 02: Stacks Part 1
File: Stack.cpp
Purpose: Declare methods for class Stack
**********************/

# ifndef STACK_CPP
# define STACK_CPP

# include "Stack.h"

Stack::Stack(){
	top = -1;
}

bool Stack::push(int x){
	
	bool noOverflow;
	
	if (top >= SIZE-1){ 
		noOverflow = false;
		throw -2;
	}
	
	else{ 
		noOverflow = true;
		a[++top] = x;
	}

	return noOverflow;
}

int Stack::peek(){
	if(top<BOTTOM){
		throw -3;
	}
	
	else{
		return a[top];
	}
	
}

int Stack::pop(){
	
	int popValue;
	
	if (top<BOTTOM){
		throw -1;
	}
	
	else{
		popValue = a[top--];
		return popValue; 
	}
	
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

# endif
