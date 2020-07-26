# ifndef PLAYER_H
# define PLAYER_H

# include "Ratings.h"

class Player{
	
	private: 
	std::string name = "Unnamed"; 
	bool elo = false, ecf = false;
	
	ECF ecfObject;
	ELO eloObject;
	
	public:
		
		// Constructors
		Player(std::string name, bool newELO, bool newECF);
		
		// Methods
		std::string getName();
		const char* getRatingType(); // Only 1 rating allowed per player
		void provideRatingInfo(double currentPlayer, double opponent);
		int getRating();
	
};

# endif
