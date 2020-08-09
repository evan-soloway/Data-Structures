/*********************
Name: Evan Soloway
Assignment: Coding 03: Stacks Part 2
File: stack.h
Purpose: header file for Stack.cpp, including class prototype and necessary libraries imported.
**********************/

# ifndef STACK_H
# define STACK_H

/*
 * notice there are no other includes here because they are not needed.
 * if you do need other things included, they would go here
 */

# include "data.h"
# include <string>
# define STACK_SIZE 10 // do not modify this define
# define BOTTOM 0 // constant

class Stack {

public:

    bool push(int, string);
    bool isEmpty();
    bool pop(Data*);
    bool peek(Data*);
    Stack();
    ~Stack();

private:

    // these are the only attributes you need. do not modify them or add any
    int top; // this is your top index
    Data *stack[STACK_SIZE]; // this is your stack, it is an array of Data pointers
};

# endif //STACK_H
