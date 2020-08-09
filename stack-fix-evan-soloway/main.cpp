/*********************
Name: Evan Soloway
Assignment: Coding 02: Stacks Part 1
File: realMain.cpp
Purpose: To manipulate and test Stack,
insuring that in common and obscure 
scenarios it operates correctly.
**********************/

# include "main.h"

int main(){ // nothin' but tests

	int index = 0;
	int numPops = 0;
	int newNumber;
	
	Stack evanStack;
	
	try{
		evanStack.peek(); // should throw exception
	}
	catch(int){
		std::cout << "stack has not been filled with anything" << std::endl;
	}
	
	std::cout << "\n";
	
	while (index<10){ // increments 10 times
		newNumber = rand() % 1000;
		std::cout << "New number is: " << newNumber << std::endl;

		try{
			evanStack.push(newNumber);
		}
		catch(int){
			std::cout << "stack is in overflow";
		}
		
		try{
			std::cout << "Top of stack is: " << evanStack.peek() << std::endl; // this should output the number just pushed onto the stack
		}
		catch(int){
			std::cout << "stack is empty" << std::endl;
		}
		
		++index;
		
	}
	
	/*
	If evanStack.isFull is implemented correctly and top is initialized correctly, 
	then above loop will execute exactly 10 times.
	*/
	
	std::cout << "\n";
	
	try{
		evanStack.push(10); // should throw exception
	}
	catch(int){
		std::cout << "Exception occurred as stack is in overflow" << std::endl; 
	}
	
	std::cout << "\n";
	
	while(!evanStack.isEmpty()){ 
	
	try{ // I put try statement around each increment rather than over entire loop to disambiguate which index (if any) threw error
		std::cout << "Top of stack is: " << evanStack.peek() << std::endl;
		std::cout << "Number being popped is: " << evanStack.pop() << std::endl; // should be same as top of stack
		numPops++;
	}
	
	catch(int){
		std::cout << "Stack is overdrawn at index " + index; 
	}
	
	/*
	the above exception will not be thrown should the isEmpty() method prove accurate. However, if
	no exception is thrown but index exceeds 9 during loop, then an error in implementation has occurred.
	*/
	
		std::cout << "...is at Index " << --index << std::endl;
	}
	
	std::cout << "\n";
	
	try{
		std::cout << evanStack.pop(); // exception will now be thrown
	}
	
	catch(int){
		std::cout << "stack is empty after " << numPops << " pops" << std::endl; 
	}
	
	try{
		evanStack.peek(); // should throw exception
	}
	catch(int){
		std::cout << "stack has been emptied";
	}
	
	return 0;
	
}

