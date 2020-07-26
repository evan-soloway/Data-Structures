# include "Player.h"

Player::Player(std::string newName = "", bool newELO=false, bool newECF=false){
	
	if(newName==""){throw -1;}
        if((!newELO && !newECF) || (newELO && newECF)){throw -1;} // added this throw
	
	name = newName;
	elo = newELO;
	ecf = newECF;
	
}

std::string Player::getName(){return name;}

const char* Player::getRatingType(){ 
std::string ratingType = "no rating has been selected";
if (elo){
ratingType = "ELO";
        }
else if (ecf){
ratingType = "ECF";
}

return ratingType;
}

void Player::provideRatingInfo(double currentRating, double opponentRating){

if (elo){
eloObject.providePlayerRating(currentRating); 
eloObject.provideOpponentRating(opponentRating);
        }

else if (ecf){
ecfObject.providePlayerRating(currentRating); 
ecfObject.provideOpponentRating(opponentRating);
        }
}

int Player::getRating(){
int rating=-1;
if (elo){rating = eloObject.getRating();}
else if (ecf){rating = ecfObject.getRating();
}

return rating;
}
