/***************************
Name: Evan Soloway
File: player.cpp
Project: Hello World
Purpose: Declares Player class methods and constructor.
***************************/

# include "player.h"

Player::Player(std::string newName = "", bool newELO=false, bool newECF=false){
	
	if(newName==""){throw -1;}
        if((!newELO && !newECF) || (newELO && newECF)){throw -1;} 
	
	name = newName;
	elo = newELO;
	ecf = newECF;
	
}

std::string Player::getName(){
    return name;
}

std::string Player::getRatingType(){ 

    std::string ratingType = "no rating has been selected";

    if (elo){
        ratingType = "ELO";
        }

    else if (ecf){
       ratingType = "ECF";
       }

    return ratingType;
}

bool Player::provideRatingInfo(double currentRating, double opponentRating){

    bool success=false;

    if(currentRating<200 || opponentRating<200){ // throws error if ratings don't meet imagined US chess federation requirements
        throw -1;
        } 

    if (elo){
        eloObject.providePlayerRating(currentRating); 
        eloObject.provideOpponentRating(opponentRating);
        success=true;
        }

    else if (ecf){
        ecfObject.providePlayerRating(currentRating); 
        ecfObject.provideOpponentRating(opponentRating);
        success=true;
        }

    return success;
}

int Player::getRating(){
        int rating=-1;

    if (elo){
        rating = eloObject.getRating();
        }
        
    else if (ecf){ 
        rating = ecfObject.getRating();
        }

    return rating;
}
