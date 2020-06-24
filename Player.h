# ifndef PLAYER_H
# define PLAYER_H

# include <iostream>
# include <iomanip>

class Player{
	
	private: 
	std::string name = "Unnamed"; 
	bool ELO = false, ECF = false;
	
	~Player();
	
	public:
		
		// Constructors
		Player();
		Player(std::string name, bool ELO, bool ECF);
		
		// Methods
		std::string provideName(std::string);
		const char* provideRatingType(); // Only 1 rating allowed per player
		int provideCurrentRating(int);
	
};

# endif
