/***************************
Name: Evan Soloway
File: main.cpp
Project: Hello World
Purpose: 
***************************/

# include "main.h"

int main(){

Player Vassily_Ivanchuk("Ivanchuk", true, false); // ELO example
Vassily_Ivanchuk.provideRatingInfo(2100, 2200);

Player Paul_Morphy("Morphy", false, true); // ECF example
Paul_Morphy.provideRatingInfo(1000, 1500);

std::cout << Vassily_Ivanchuk.getName() << std::endl;
std::cout << Vassily_Ivanchuk.getRatingType() << std::endl;
std::cout << Vassily_Ivanchuk.getRating() << std::endl;

std::cout << "\n\n";

std::cout << Paul_Morphy.getName() << std::endl;
std::cout << Paul_Morphy.getRatingType() << std::endl;
std::cout << Paul_Morphy.getRating() << std::endl;

return 0;
}
