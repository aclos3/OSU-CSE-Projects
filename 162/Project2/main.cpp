/***************************************************************************
**   Program Name: Project 2 (main.cpp)
**   Author: Andrew Clos
**   Date: 7/20/2019
**   Description: This main method creates a new Zoo Class and then begins the
**				  game by making a call to the Zoo's public mainMenu function.
**				  Returned by the mainMenu is the count of the total number of
**				  animals that the game ended with.  This is outputted to the
**				  console.
****************************************************************************/

#include<iostream>
#include "Zoo.hpp"

int main()
{
	int animalCount = 0;

	//Declare a Game and run the game's mainMenu.
	Zoo game1;
	animalCount = game1.mainMenu();
	
	std::cout << "Your game ended with a total of " << animalCount << " animals!" << std::endl;
	std::cout << std::endl << "Thank you for playing." << std::endl;
	
	return 0;
}
