# include "ECF.h"

void ECF::provideOpponentRating(double rating){
	opponentRating = rating;
}

void ECF::providePlayerRating(double rating){
	playerRating = rating;
}

void ECF::provideResult(bool newResult){
	result = newResult;
}

int ECF::getRating(){
	return opponentRating-deviation+(100*result);
}
