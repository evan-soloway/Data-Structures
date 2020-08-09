/*********************
Name: Evan Soloway
Assignment: Coding 02: Stacks Part 1
File: Stack.h
Purpose: Prototype for class Stack
**********************/

# ifndef STACK_H
# define STACK_H

# define SIZE 10 // constant
# define BOTTOM 0 // constant

# include <iostream>
# include <iomanip>

class Stack{
	
	int top, a[SIZE];
	
	public:
		
	Stack();
	bool push(int x);
	bool isEmpty();
	int peek();
	int pop();
	
};

# endif
