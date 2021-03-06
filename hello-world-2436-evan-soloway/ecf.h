/***************************
Name: Evan Soloway
File: ecf.h
Project: Hello World
Purpose: Prototypes ECF class
***************************/

# ifndef ECF_H
# define ECF_H

# include <iostream>
# include <iomanip>
# define DEVIATION 50 // made this a constant; was variable

class ECF{
	
        protected:
		
	// changed to "protected" from "public"; moved declarations to constructor
	double playerRating; 
	double opponentRating; 
	bool result; 
	
	/*
	All attributes above made "double" so that algorithms 
	involving them will always yield floating point number
	and not integer. Necessary for ELO algorithm, which will inherit
	these attributes.
	*/
	
        public:

        ECF();

	/// Constructor functions
	void provideOpponentRating(double rating);
	void providePlayerRating(double rating);
	void provideResult(bool newResult);
	/// Constructor functions
	
	/*
	Bear in mind this toy program is constructed
	for readability more than anything. If I were coding
	this practically, these 'constructor functions' as
	I'm calling them would be entirely integrated
	into an actual class constructor. Also, I've
	expanded these functions to help illustrate 
	inheritance, as these same constructors will 
	be necessary in subsequent rating classes.
	*/
	
	int getRating();

};

# endif
