# include "ELO.h"

double ELO::getWinProbability(){
	return 1/(1+(pow(10,(playerRating-opponentRating)/400)));
}

int ELO::getRating(){
	return playerRating+deviation*(getWinProbability()-(1-getWinProbability()));
}
