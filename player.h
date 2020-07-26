/***************************
Name: Evan Soloway
File: player.h
Project: Hello World
Purpose: Prototypes Player class. 
***************************/

# ifndef PLAYER_H
# define PLAYER_H

# include "ratings.h"

class Player{
	
	private: 
	std::string name; 
	bool elo, ecf;
	
	ECF ecfObject;
	ELO eloObject;
	
	public:
		
		Player(std::string name, bool newELO, bool newECF);
		
		std::string getName();
		std::string getRatingType(); 
		bool provideRatingInfo(double currentPlayer, double opponent);
		int getRating();
	
};

# endif
