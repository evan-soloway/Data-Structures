/***************************
Name: Evan Soloway
File: main.cpp
Project: Hello World
Purpose: 
***************************/

# include "main.h"

int main(){

int ivanchukRating=2100;
int morphyRating=1000;

std::cout << "Adding players:" << std::endl;

Player Vassily_Ivanchuk("Ivanchuk", true, false); // ELO example
std::cout << "adding Vassily Ivanchuk and providing player info... ";
if(Vassily_Ivanchuk.provideRatingInfo(ivanchukRating, 2200)){
std::cout << "success." << std::endl;
        }
else{
std::cout << "failed." << std::endl;
        }

Player Paul_Morphy("Morphy", false, true); // ECF example
std::cout << "adding Paul Morphy and providing player info... ";
if(Paul_Morphy.provideRatingInfo(morphyRating, 1500)){
std::cout << "success." << std::endl;
        }

else{
std::cout << "failed." << std::endl;
        }

std::cout << "\nDisplaying players' info:" << std::endl;

std::cout << "Rating before match: " << ivanchukRating << std::endl;
std::cout << "Name: " << Vassily_Ivanchuk.getName() << std::endl;
std::cout << "Rating Type: " << Vassily_Ivanchuk.getRatingType() << std::endl;
std::cout << "Rating after winning match against 2200 player: " << Vassily_Ivanchuk.getRating() << std::endl;

std::cout << "\n";

std::cout << "Rating before match: " << morphyRating << std::endl;
std::cout << "Name: " << Paul_Morphy.getName() << std::endl;
std::cout << "Rating Type: " << Paul_Morphy.getRatingType() << std::endl;
std::cout << "Rating after winning match against 1500 player: " << Paul_Morphy.getRating() << std::endl;

std::cout << "\nAdding player with false in constructor for both ELO and ECF ratings:" << std::endl;

try{
Player Bobby_Fischer("Fischer", false, false); 
}

catch(int){
std::cout << "Constructor threw error" << std::endl;
}

std::cout << "\nAdding player with true in constructor for both ELO and ECF ratings:" << std::endl;

try{
Player Bobby_Fischer("", true, true); 
}

catch(int){
std::cout << "Constructor threw error" << std::endl;
}

std::cout << "\nAdding player with no name:" << std::endl;

try{
Player Bobby_Fischer("", true, false); 
}

catch(int){
std::cout << "Constructor threw error" << std::endl;
}

/*

std::cout << "\nadding player and constructing with bad data... ";

try{
if(Bobby_Fischer.provideRatingInfo(100, 200)){
std::cout << "success." << std::endl;
        }

else{
std::cout << "failed." << std::endl;
        }

}

catch(int){"provideRatingInfo() threw error";}

std::cout << "Displaying player info:" << std::endl;
try{
std::cout << Bobby_Fischer.getName() << std::endl;
}

catch(int){
std::cout << "getName() threw error" << endl;
}

try{
std::cout << Bobby_Fischer.getRatingType() << std::endl;
}

catch(int){
std::cout << "getRatingType() threw error" << std::endl;
}

try{
std::cout << Bobby_Fischer.getRating() << std::endl;
}

catch(int){
std::cout << "getRating() threw error" << std::endl;
}
*/
return 0;
}
