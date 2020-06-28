# include "Player.h"

Player::Player(std::string newName = "", bool newELO=false, bool newECF=false){
	
	if(newName==""){throw -1;}
	
	name = newName;
	elo = newELO;
	ecf = newECF;
	
}

std::string Player::getName(){return name;}

const char* Player::getRatingType(){ 
if (elo){return "ELO";}
else if (ecf){return "ECF";}
return "no rating has been selected";
}

/*
I know that multiple returns in a method are sloppy, however, I've failed to perfect
a way of constructing an instance of this class which would perfectly distinguish the chosen rating. 
*/

void Player::provideRatingInfo(double currentRating, double opponentRating){
if (elo){eloObject.providePlayerRating(currentRating); eloObject.provideOpponentRating(opponentRating);}
else if (ecf){ecfObject.providePlayerRating(currentRating); ecfObject.provideOpponentRating(opponentRating);}
}

int Player::getRating(){
if (elo){return eloObject.getRating();}
else if (ecf){return ecfObject.getRating();}
return -1;
}
