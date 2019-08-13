/***************************************************************************
**   Program Name: Lab 3 (main.cpp)
**   Author: Andrew Clos
**   Date: 7/11/2019
**   Description: This main method creates a Game object and then calls the
**				  game's mainMenu function.  All other functions of this 
**				  program are handled within the Game class itself.
****************************************************************************/

#include<iostream>
#include<array>
#include "Game.hpp"

int main()
{
	//Declare a Game and run the game's mainMenu.
	Game game1;
	game1.mainMenu();
 
	return 0;
}
