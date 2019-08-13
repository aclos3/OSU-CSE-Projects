/***************************************************************************
**   Program Name: Final Project (Menu.cpp)
**   Author: Andrew Clos
**   Date: 8/12/2019
**   Description: The menu class primarily contains functions to display
**				  options to the user and recieves the user's input as well
**				  as controls the updating and printing of the map.  This was
**				  done dynamically and the player's piece is a "real" position
**				  so that this game would have the flexibility to handle more
**				  dynamic user movement.
****************************************************************************/

#include<iostream>
#include<random>
#include "Menu.hpp"
#include "InputValidate.hpp"

Menu::Menu()
{
	setRows(0);
	setCols(0);
}

/***************************************************************************
**   Description: Presents main menu options to the user and sets the user's
**				  name. Takes a pointer to the player and returns an integer.
****************************************************************************/
int Menu::mainMenu(Player* p1)
{
	InputValidate mainTest;
	int choice = 0;

	std::cout << "Please Make Your Choice From the Options Below:" << std::endl;
	std::cout << "(1) Begin the game." << std::endl;
	std::cout << "(2) Quit." << std::endl;

	choice = mainTest.intValidate(YESLIMITS, MINMENU, MAXMENU);
	
	//set player's name for a personal touch.
	if (choice == 1)
	{
		std::cout << "Please Enter the Name for Your Explorer: ";
		p1->setName(mainTest.strValidate(true, MAXNAME));
	}
	
	return(choice);
}

/***************************************************************************
**   Description: Builds the initial Menu map of a double pointer 2d array
**				  of characters.  This was done so that future development
**				  of this game could have increased flexbility to allow the
**				  user to move their character token around the map in a more
**				  freeform manner. 
****************************************************************************/
char** Menu::buildMap(Player *p1)
{
	p1->setPosition(MAPROWS / 2, MAPCOLS / 2);

	char **board = new char*[numRows];

	for (int i = 0; i < numRows; i++)
	{
		board[i] = new char[numCols];
	}

	//fill board initially 
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			if (i == MAPROWS / 2 && j == MAPCOLS / 2)
			{
				board[i][j] = PLAYERSYMBOL;
			}
			else
			{
				board[i][j] = EMPTYSYMBOL;
			}
		}
	}
	return board;
}

/***************************************************************************
**   Description: Displays the map to the console with appropriate symbols
**				  for cardinal directions and colors. Uses several loops and
**				  if statements for proper column alignment.
****************************************************************************/
void Menu::displayMap(char ** userBoard)
{
	
	std::cout << "NW";
	for (int i = 0; i < numCols / 2; i++)
	{
		std::cout << " ";
	}
	std::cout << "N";
	for (int i = 0; i < numCols / 2; i++)
	{
		std::cout << " ";
	}
	std::cout << "NE" << std::endl;

	for (int i = 0; i < numRows; i++)
	{
		if (i == numRows / 2)
		{
			std::cout << "W ";
		}
		else
		{
			std::cout << "  ";
		}
		for (int j = 0; j < numCols; j++)
		{
			if (userBoard[i][j] == PLAYERSYMBOL)
			{
				std::cout << "\033[1;31m@\033[0m";
			}
			//print discovered rooms in their respective colors
			else if (userBoard[i][j] == 42)
			{
				//NW = blue
				if (i <= ROOMROWS && j <= ROOMCOLS)
				{
					std::cout << "\033[1;94m*\033[0m";
				}
				//NC = yellow
				else if (i <= ROOMROWS && j <= ROOMCOLS * 3)
				{
					std::cout << "\033[1;93m*\033[0m";
				}
				//NE = yellow
				else if (i <= ROOMROWS && j <= ROOMCOLS * 5)
				{
					std::cout << "\033[1;91m*\033[0m";
				}
				//WC = black
				else if (i <= (ROOMROWS * 3) && j <= ROOMCOLS)
				{
					std::cout << "\033[3;100;30m*\033[0m";
				}
				//EC = white
				else if (i <= (ROOMROWS * 3) && j <= (ROOMCOLS * 5))
				{
					std::cout << "\033[1;97m*\033[0m";
				}
				//SW = green
				else if (i <= (ROOMROWS * 5) && j <= ROOMCOLS)
				{
					std::cout << "\033[1;92m*\033[0m";
				}
				//SC = cyan
				else if (i <= (ROOMROWS * 5) && j <= (ROOMCOLS * 3))
				{
					std::cout << "\033[1;96m*\033[0m";
				}
				//SE = magenta
				else if (i <= (ROOMROWS * 5) && j <= (ROOMCOLS * 5))
				{
					std::cout << "\033[1;95m*\033[0m";
				}
			}
			else
			{
				std::cout << userBoard[i][j];
			}
		}
		if (i == numRows / 2)
		{
			std::cout << " E";
		}
		std::cout << std::endl;
	}
	std::cout << "SW";
	for (int i = 0; i < numCols / 2; i++)
	{
		std::cout << " ";
	}
	std::cout << "S";
	for (int i = 0; i < numCols / 2; i++)
	{
		std::cout << " ";
	}
	std::cout << "SE" << std::endl;


}

/***************************************************************************
**   Description: Displays the game's instructions to the console. Takes a
**				  pointer to the player class so that the amount of container
**				  space and number of starting shovels updates properly here
**				  if it is changed elsewhere in the program.
****************************************************************************/
void Menu::displayInstructions(Player* p1)
{
	std::cout << "Goal: Gain the maximum number of points by collecting as many valuable gems as possible.  Some gems "<< std::endl;
	std::cout << "are worth more than others, but are often hard to dig or less plentiful. " << std::endl << std::endl;
	std::cout << "Instructions: Start by choosing a region to explore to seek out a new room. Once in that room, use " << std::endl;
	std::cout << "your shovels to dig at dig-sites for gems or look around the room to explore and discover objects " << std::endl;
	std::cout << "to interact with (look around). Each room has a different number of dig-sites, with differing " << std::endl;
	std::cout << "levels of difficulty per site and a different cost of shovels per dig. Generally, the higher the dig " << std::endl;
	std::cout << "price and the lower its probability of success, the more potential value its gems have." << std::endl << std::endl;
	std::cout << "Note: Interacting with an object in the room can produce a gem bonus, do nothing, or " << std::endl;
	std::cout << "a loss of some of your shovels. Digging to a new region costs 10 shovels and the game ends when you " << std::endl;
	std::cout << "run out of shovels or have visited all rooms. You cannot revist a room you've already been to." << std::endl << std::endl;
	std::cout << "There are 8 total " << "\033[1;97mrooms\033[0m" << " to explore. " << std::endl;
	std::cout << "You start with " << p1->getContainerSpace() << "\033[1;97m inventory\033[0m" << " space, and " << p1->getShovels() << "\033[1;97m shovels.\033[0m" << std::endl << std::endl;
}

/***************************************************************************
**   Description: Welcomes the player to the cave and presents the list of
**				  spaces that a player can visit.  Also moves the user's
**				  game token to the correct spot. This function takes a double
**				  pointer of characters to the userboard, a pointer to the player
**				  and an integer value to toggle display of the initial greeting.
****************************************************************************/
int Menu::movePlayer(char ** userBoard, Player *p1, int moveNum)
{
	InputValidate mover;
	int menuMoveChoice = 0;

	
	if (moveNum < 1)
	{   //only display this greeting if the user has not entered a space before.
		std::cout << "Welcome to the cave of wonders, " << p1->getPname() << ". May you find many gems!" << std::endl;
		std::cout << "Please choose the region you'd like to explore." << std::endl;
	}
	else
	{
		std::cout << "Please choose a new location." << std::endl;
	}

	std::cout << "(1) Northwest Corner (NW)." << std::endl;
	std::cout << "(2) North (N)." << std::endl;
	std::cout << "(3) Northeast Corner (NE)." << std::endl;
	std::cout << "(4) West Center (W)." << std::endl;
	std::cout << "(5) East Center (E)." << std::endl;
	std::cout << "(6) Southwest Corner (SW)." << std::endl;
	std::cout << "(7) South Center (S)." << std::endl;
	std::cout << "(8) Southeast Corner (SE)." << std::endl;
	std::cout << "(9) Quit." << std::endl;

	menuMoveChoice = mover.intValidate(YESLIMITS, MINMOVE, MAXMOVE);

	//these if-statements vacate the location of the previous user location
	//and set the new position of the player.  They also call the dig path function
	if (menuMoveChoice == 1)
	{
		userBoard[p1->getRow()][p1->getCol()] = EMPTYSYMBOL;
		p1->setPosition((numRows / 5) - (ROOMROWS / 2 + 1), ((numCols / 5) - (ROOMCOLS / 2 + 1)));
		digPath(userBoard, menuMoveChoice);
	}
	else if (menuMoveChoice == 2)
	{
		userBoard[p1->getRow()][p1->getCol()] = EMPTYSYMBOL;
		p1->setPosition((numRows / 5) - (ROOMROWS / 2 + 1), numCols / 2);
		digPath(userBoard, menuMoveChoice);
	}
	else if (menuMoveChoice == 3)
	{
		userBoard[p1->getRow()][p1->getCol()] = EMPTYSYMBOL;
		p1->setPosition((numRows / 5) - (ROOMROWS / 2 + 1), (numCols - (ROOMCOLS / 2 + 1)));
		digPath(userBoard, menuMoveChoice);
	}
	else if (menuMoveChoice == 4)
	{
		userBoard[p1->getRow()][p1->getCol()] = EMPTYSYMBOL;
		p1->setPosition(numRows / 2, ((numCols / 5) - (ROOMCOLS / 2 + 1)));
		digPath(userBoard, menuMoveChoice);
	}
	else if (menuMoveChoice == 5)
	{
		userBoard[p1->getRow()][p1->getCol()] = EMPTYSYMBOL;
		p1->setPosition(numRows / 2, (numCols - (ROOMCOLS / 2 + 1)));
		digPath(userBoard, menuMoveChoice);
	}
	else if (menuMoveChoice == 6)
	{
		userBoard[p1->getRow()][p1->getCol()] = EMPTYSYMBOL;
		p1->setPosition(numRows - (ROOMROWS / 2 + 1), ((numCols / 5) - (ROOMCOLS / 2 + 1)));
		digPath(userBoard, menuMoveChoice);
	}
	else if (menuMoveChoice == 7)
	{
		userBoard[p1->getRow()][p1->getCol()] = EMPTYSYMBOL;
		p1->setPosition(numRows - (ROOMROWS / 2 + 1), numCols / 2);
		digPath(userBoard, menuMoveChoice);
	}
	else if (menuMoveChoice == 8)
	{
		userBoard[p1->getRow()][p1->getCol()] = EMPTYSYMBOL;
		p1->setPosition(numRows - (ROOMROWS / 2 + 1), numCols - (ROOMCOLS / 2 + 1));
		digPath(userBoard, menuMoveChoice);
	}
	userBoard[p1->getRow()][p1->getCol()] = PLAYERSYMBOL;

	return menuMoveChoice;
}

/***************************************************************************
**   Description: Cleans up memory by deleting the dynamically allocated 
**				  game board. This is not done in the destructor because a 
**				  game board is not instantiated in all cases of the Menu 
**				  class.
****************************************************************************/
void Menu::removeBoard(char** userBoard)
{
	//remove the dynamically allocated array from memory.
	for (int i = 0; i < numRows; i++)
	{
		delete[] userBoard[i];
	}
	delete[] userBoard;
}

/***************************************************************************
**   Description: Erases symbols from the user array to show the paths dug
**				  as part of the map. Reprints board at the end of the call
**				  takes a pointer to the 2d array for the userBoard and an 
**				  integer to represent the direction of the dig. Also opens 
**				  up the graphical representation of the "space" that was
**				  discovered by the digger.
****************************************************************************/
void Menu::digPath(char** userBoard, int direction)
{
	//NW
	if (direction == 1)
	{
		//starting position
		userBoard[MAPROWS / 2][MAPCOLS / 2] = ' ';
		
		//dig the tunnel
		for (int i = 0; i < DIAGONALDIG; i++)
		{
			userBoard[(MAPROWS / 2) - (i / 3)][(MAPCOLS / 2) - i] = ' ';
		}
		
		//clear the room
		for (int i = 0; i < ROOMROWS; i++)
		{
			for (int j = 0; j < ROOMCOLS; j++)
			{
				if (j == 0 || j == ROOMCOLS - 1 || i == 0 || i == ROOMROWS - 1)
				{
					userBoard[i][j] = '*';
				}
				else
				{
					userBoard[i][j] = ' ';
				}	
			}
		}
	}
	//NC
	else if (direction == 2)
	{
		//starting position
		userBoard[MAPROWS / 2][MAPCOLS / 2] = ' ';
		
		//dig the tunnel
		for (int i = 0; i < STRAIGHTDIG; i++)
		{
			userBoard[(MAPROWS / 2) - i][(MAPCOLS / 2)] = ' ';
		}

		//clear the room
		for (int i = 0; i < ROOMROWS; i++)
		{
			for (int j = (ROOMCOLS * 2); j < (ROOMCOLS * 3); j++)
			{
				if (j == (ROOMCOLS * 2) || j == (ROOMCOLS * 3) - 1 || i == 0 || i == ROOMROWS - 1)
				{
					userBoard[i][j] = '*';
				}
				else
				{
					userBoard[i][j] = ' ';
				}
			}
		}
	}
	//NE
	else if (direction == 3)
	{
		userBoard[MAPROWS / 2][MAPCOLS / 2] = ' ';
		
		//dig the tunnel
		for (int i = 0; i < DIAGONALDIG; i++)
		{
			userBoard[(MAPROWS / 2) - (i / 3)][(MAPCOLS / 2) + i] = ' ';
		}

		//clear the room
		for (int i = 0; i < ROOMROWS; i++)
		{
			for (int j = (ROOMCOLS * 4); j < (ROOMCOLS * 5); j++)
			{
				if (j == (ROOMCOLS * 4) || j == (ROOMCOLS * 5) - 1 || i == 0 || i == ROOMROWS - 1)
				{
					userBoard[i][j] = '*';
				}
				else
				{
					userBoard[i][j] = ' ';
				}
			}
		}
	}
	//WC
	else if (direction == 4)
	{
		userBoard[MAPROWS / 2][MAPCOLS / 2] = ' ';
		for (int i = 0; i < DIAGONALDIG; i++)
		{
			userBoard[MAPROWS / 2][(MAPCOLS / 2) - i] = ' ';
		}

		//clear the room
		for (int i = (ROOMROWS * 2); i < (ROOMROWS * 3); i++)
		{
			for (int j = 0; j < ROOMCOLS; j++)
			{
				if (j == 0 || j == (ROOMCOLS - 1) || i == (ROOMROWS * 2) || i == (ROOMROWS * 3) - 1)
				{
					userBoard[i][j] = '*';
				}
				else
				{
					userBoard[i][j] = ' ';
				}
			}
		}
	}
	//EC
	else if (direction == 5)
	{
		userBoard[MAPROWS / 2][MAPCOLS / 2] = ' ';
		for (int i = 0; i < DIAGONALDIG; i++)
		{
			userBoard[MAPROWS / 2][(MAPCOLS / 2) + i] = ' ';
		}

		//clear the room
		for (int i = (ROOMROWS * 2); i < (ROOMROWS * 3); i++)
		{
			for (int j = (ROOMCOLS * 4); j < (ROOMCOLS * 5); j++)
			{
				if (j == (ROOMCOLS * 4) || j == (ROOMCOLS * 5) - 1 || i == (ROOMROWS * 2) || i == (ROOMROWS * 3) - 1)
				{
					userBoard[i][j] = '*';
				}
				else
				{
					userBoard[i][j] = ' ';
				}
			}
		}
	}
	//SW
	else if (direction == 6)
	{
		userBoard[MAPROWS / 2][MAPCOLS / 2] = ' ';
		for (int i = 0; i < DIAGONALDIG; i++)
		{
			userBoard[(MAPROWS / 2) + (i / 3)][(MAPCOLS / 2) - i] = ' ';
		}
		//clear the room
		for (int i = (ROOMROWS * 4); i < (ROOMROWS * 5); i++)
		{
			for (int j = 0; j < ROOMCOLS; j++)
			{
				if (j == 0 || j == (ROOMCOLS - 1) || i == (ROOMROWS * 4) || i == (ROOMROWS * 5) - 1)
				{
					userBoard[i][j] = '*';
				}
				else
				{
					userBoard[i][j] = ' ';
				}
			}
		}
	}
	//SC
	else if (direction == 7)
	{
		userBoard[MAPROWS / 2][MAPCOLS / 2] = ' ';
		for (int i = 0; i < STRAIGHTDIG; i++)
		{
			userBoard[(MAPROWS / 2) + i][MAPCOLS / 2] = ' ';
		}
		//clear the room
		for (int i = (ROOMROWS * 4); i < (ROOMROWS * 5); i++)
		{
			for (int j = (ROOMCOLS * 2); j < (ROOMCOLS * 3); j++)
			{
				if (j == (ROOMCOLS * 2) || j == (ROOMCOLS * 3) - 1 || i == (ROOMROWS * 4) || i == (ROOMROWS * 5) - 1)
				{
					userBoard[i][j] = '*';
				}
				else
				{
					userBoard[i][j] = ' ';
				}
			}
		}
	}
	//SE
	else if (direction == 8)
	{
		userBoard[MAPROWS / 2][MAPCOLS / 2] = ' ';
		for (int i = 0; i < DIAGONALDIG; i++)
		{
			userBoard[(MAPROWS / 2) + (i / 3)][(MAPCOLS / 2) + i] = ' ';
		}

		//clear the room
		for (int i = (ROOMROWS * 4); i < (ROOMROWS * 5); i++)
		{
			for (int j = (ROOMCOLS * 4); j < (ROOMCOLS * 5); j++)
			{
				if (j == (ROOMCOLS * 4) || j == (ROOMCOLS * 5) - 1 || i == (ROOMROWS * 4) || i == (ROOMROWS * 5) - 1)
				{
					userBoard[i][j] = '*';
				}
				else
				{
					userBoard[i][j] = ' ';
				}
			}
		}
	}
}

//set methods for number of rows and columns.
void Menu::setRows(int r)
{
	numRows = r;
}

void Menu::setCols(int c)
{
	numCols = c;
}

//default destructor.
Menu::~Menu()
{

}

