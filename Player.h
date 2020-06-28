# ifndef PLAYER_H
# define PLAYER_H

# include <iostream>
# include <iomanip>
# include "Ratings.h"

class Player{
	
	private: 
	std::string name = "Unnamed"; 
	bool ELO = false, ECF = false;
	
	ECF ecf;
	ELO elo;
	
	public:
		
		// Constructors
		Player();
		Player(std::string name, bool ELO, bool ECF);
		
		// Methods
		std::string getName();
		const char* getRatingType(); // Only 1 rating allowed per player
		void provideRatingInfo(double, double);
		int getRating();
	
};

# endif
