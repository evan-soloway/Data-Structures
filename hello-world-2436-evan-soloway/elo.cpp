/***************************
Name: Evan Soloway
File: elo.cpp
Project: Hello World
Purpose: Declares ELO class methods and constructor.
***************************/

# include "elo.h"

ELO::ELO(){
winProbability=0;
}

double ELO::getWinProbability(){
	return 1/(1+(pow(10,(playerRating-opponentRating)/400)));
}

int ELO::getRating(){
	return playerRating+DEVIATION*(getWinProbability()-(1-getWinProbability()));
}
