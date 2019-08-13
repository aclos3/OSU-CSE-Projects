/***************************************************************************
**   Program Name: Project 3 (main.cpp)
**   Author: Andrew Clos
**   Date: 7/31/2019
**   Description: Main greets the user and then shows them a menu to begin
**			      character selection. An array is filled with the selected
**				  characters and cycles of combat and displaying rounds
**				  is entered until one of the players dies. Then game stats
**				  are displayed to the console and the user is asked if they'd
**				  like to play again.
****************************************************************************/

#include<iostream>
#include "InputValidate.hpp"
#include "Game.hpp"

const int NUMPLAYERS = 2;
const bool BROADCAST = true;

int main()
{  
	int playerClasses[NUMPLAYERS];
	int roundCounter = 0,
		playAgain = 1;
	InputValidate again;
	
	
	std::cout << "Welcome to a Fantasy Combat!" << std::endl;
	std::cout << "Andrew Clos, CS162-400, Project 3." << std::endl;

	while(playAgain == 1)
	{
		//establish a new game, and create classes. Store these in array via for-loop
		//which will make it easier to scale the game to addtional players if desired.
		Game game1;
		
		for (int i = 0; i < NUMPLAYERS; i++)
		{
			playerClasses[i] = game1.initMenu(i + 1);

			if (playerClasses[i] == 6)
			{
				playAgain = 2;
				//prevent from looping again if the first player chose to quit
				i = i + NUMPLAYERS;
			}
		}
		if (playAgain == 1)
		{
			game1.createClasses(playerClasses, NUMPLAYERS);
			
			//this while loop is active while all player characters are alive and the exit
			//option from the menus has not been selected by the user.
			while (game1.characterAlive(BROADCAST) == 0 && playAgain == 1)
			{
				roundCounter++;
				game1.printStats(roundCounter);
				game1.combat();
			}

			//end game, show stats.
			game1.showStats();

			//ask to play again.
			std::cout << "Would you like to play again?" << std::endl;
			std::cout << "(1) Yes." << std::endl;
			std::cout << "(2) No." << std::endl;
			playAgain = again.intValidate(YESLIMITS, MINYN, MAXYN);
		}
		
		if(playAgain == 2)
		{
			std::cout << "Thank you for playing." << std::endl;
		}
	} 
	return 0;
}


