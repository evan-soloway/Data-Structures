# ifndef ECF_H
# define ECF_H

# include <iostream>
# include <iomanip>

class ECF{
	
	~ECF();
	
	public:
		
	// class attributes made public so that inheriting classes can access them
	double deviation = 50;
	double playerRating = 0;
	double opponentRating = 0;
	bool result = false;
	
	/*
	All attributes above made "double" so that algorithms 
	involving them will always yield floating point number
	and not integer. Necessary for ELO algorithm, which will inherit
	these attributes.
	*/
	
	/// Constructor functions
	void provideOppenentRating(double rating);
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
