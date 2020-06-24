#ifndef PLAYER_CPP

# include "Player.h"

// Constructors //
Player::Player(){ // constructor which throws error if objects are not constructed properly
	throw "Necessary information for player not provided.";
}

Player::Player(std::string newName = "", bool newELO, bool newECF){
	
	if(newName==""){throw -1;}
	
	name = newName;
	ELO = newELO;
	ECF = newECF;
	
}

std::string Player::provideName(std::string){return name;}

const char* Player::provideRatingType(){ 
if (ELO){return "ELO";}
else if (ECF){return "ECF";}
return "no rating has been selected";
}

/*
I know that multiple returns in a method are sloppy, however, I've failed to perfect
a way of constructing an instance of this class which would perfectly distinguish
the chosen rating. 
*/


/*
int provideCurrentRating(int){
	if (ELO){return getRating(/*getEloRating*//*)}
else if (ECF){return getRating(/*getECFRating*//*)}
}
*/

#endif
