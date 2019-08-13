/***************************************************************************
**   Program Name: Final Project (main.cpp)
**   Author: Andrew Clos
**   Date: 8/12/2019
**   Description: The main method initializes the Menu, Player and game board
**				  and then uses a couple of while loops to call various Menu
**				  and Player functions in order to move through the game. Also
**				  handled here is the passing of classes (via pointers) to 
**				  other functions.
****************************************************************************/

#include<iostream>
#include "Menu.hpp"
#include "Player.hpp"
#include "InputValidate.hpp"

const int NUMROOMS = 8;
const int TUNNELCOST = 10;

int main()
{  
	int gameMenu = 0,
		prevPRow = 0,
		prevPCol = 0,
		moveCount = 0,
		visitedCount = NUMROOMS;
	std::vector<int> goods;

	bool active = true;
	std::string playerName = " ";
	char **gameBoard;
	Player *spelunker = new Player;
	
	//display greetig and title block
	std::cout << "Welcome to a Cave Explorer!" << std::endl;
	std::cout << "Andrew Clos, CS162-400, Final Project." << std::endl << std::endl;

	while (active)
	{
		Menu game1;
		//display main menu to play or quit
		if (game1.mainMenu(spelunker) == 1)
		{
			//set up the map and display it, then set up (instantiate) the Spaces.
			game1.setRows(MAPROWS);
			game1.setCols(MAPCOLS);
			gameBoard = game1.buildMap(spelunker);
			game1.displayMap(gameBoard);
			game1.displayInstructions(spelunker);
			spelunker->setupRooms();

			//the check to make sure the player still has enough shovels after a "round"
			while (spelunker->getShovels() > 9 && gameMenu != 9 && active)
			{
				prevPRow = spelunker->getRow();
				prevPCol = spelunker->getCol();
				gameMenu = game1.movePlayer(gameBoard, spelunker, moveCount);
				
				//if still playing, spelunker enters space!
				if (gameMenu != 9 && active)
				{
					moveCount++;

					//check to see if room has been entered already
					//reset player to previous position if it has
					spelunker->setCurrentSpace(gameMenu);
					if (spelunker->getCurrentSpace()->getVisted())
					{
						gameBoard[prevPRow][prevPCol] = 111;
						spelunker->setRow(prevPRow);
						spelunker->setCol(prevPCol);
						std::cout << "Sorry, this space has already been visited." << std::endl;
						spelunker->restorePrev();
					}
					else
					{
						//decrement visited counter and number of shovels from digging to the space
						visitedCount--;
						spelunker->setShovels(spelunker->getShovels() - TUNNELCOST);
							
						//show map to reflect newly opened space.
						game1.displayMap(gameBoard);

						//load vector with gems found and shovels used in the room and display the map 
						//after the player leaves.
						spelunker->showValues();
						goods = spelunker->getCurrentSpace()->playerEnters(spelunker->getShovels());
						game1.displayMap(gameBoard);

						//update the player's points and shovels, add new gems to inventory.
						spelunker->setPoints(spelunker->getPoints() + (goods.at(0) * spelunker->getCurrentSpace()->getPtsPerGem()));
						spelunker->setShovels(spelunker->getShovels() - goods.at(1));
						spelunker->addContainer(goods.at(0));

						//show quantities of each gem and remaining shovels
						spelunker->showGems();
						std::cout << "Remaining " << "\033[1;97mShovels\033[0m" << ":" << spelunker->getShovels() << std::endl;
					}
				}
				else
				{
					active = false;
				}

				//game over condition for no more shovels is checked
				if (spelunker->getShovels() < 10)
				{
					std::cout << "You don't have enough shovels to dig to another region, the game is over." << std::endl;
					active = false;
				}
				//game over condition for no more spaces to visit is checked.
				if (visitedCount < 1)
				{
					std::cout << "All spaces have been visited." << std::endl;
					active = false;
				}
			}
			//free dynamically allocated memory from the Menu call to create a new game.
			game1.removeBoard(gameBoard);
		}

		//quit
		else
		{
			active = false;
		}

		if (active == false)
		{
			//tally final score.
			spelunker->showPoints();
			std::cout << "Thank you for playing, " << spelunker->getPname() << "." << std::endl;
		}
	}
	//free memory from dynamically allocated "Player" object.
	delete spelunker;
	return 0;
}


