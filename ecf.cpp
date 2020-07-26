/***************************
Name: Evan Soloway
File: ecf.cpp
Project: Hello World
Purpose: Declares ECF class methods and constructor.
***************************/

# include "ecf.h"

ECF::ECF(){

opponentRating=0;
playerRating=0;
result=false;

};

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
	return opponentRating-DEVIATION+(100*result);
}
