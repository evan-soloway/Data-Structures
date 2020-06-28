# include "Player.h"

// Constructors //
Player::Player(){ // constructor which throws error if objects are not constructed properly
	throw "Necessary information for player not provided.";
}

Player::Player(std::string newName = "", bool newELO=false, bool newECF=false){
	
	if(newName==""){throw -1;}
	
	name = newName;
	ELO = newELO;
	ECF = newECF;
	
}

std::string Player::getName(){return name;}

const char* Player::getRatingType(){ 
if (ELO){return "ELO";}
else if (ECF){return "ECF";}
return "no rating has been selected";
}

/*
I know that multiple returns in a method are sloppy, however, I've failed to perfect
a way of constructing an instance of this class which would perfectly distinguish the chosen rating. 
Finding an optimal solution would require too much time.
*/

void Player::provideRatingInfo(double currentRating, double opponentRating){
if (ELO){elo.providePlayerRating(currentRating); elo.provideOpponentRating(opponentRating);}
else if (ECF){ecf.providePlayerRating(currentRating); ecf.provideOpponentRating(opponentRating);}
}

int Player::getRating(){
if (ELO){return elo.getRating();}
else if (ECF){return ecf.getRating();}
return -1;
}
