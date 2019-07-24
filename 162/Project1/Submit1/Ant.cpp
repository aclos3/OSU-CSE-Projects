/***************************************************************************
**   Program Name: Project 1 (Ant.cpp)
**   Author: Andrew Clos
**   Date:
**   Description: The Ant class holds parameters of the simulation (proivded
**                by the caller as pointer to an array).  With this information
**                public functions can be called that will make a board, print
**                the board to the console and have the Ant take a step.
**                The step is started when the takeStep function is called.
**                This function will then, in turn call the turn and color
**                toggle private functions. The Ant always starts pointing 
**                north, and when meeting the board boundary, will "clip"
**                across to the other side of the matrix.
****************************************************************************/

#include<iostream>
#include "Ant.hpp"

//default constructor
Ant::Ant()
{
	rows = 0;
	cols = 0;
	steps = 0;
	antRow = 0;
	antCol = 0;
	antDir = 0;
}
//constructor to build the Ant Class
Ant::Ant(int *userParams)
{
	setRows(userParams[0]);
	setCols(userParams[1]);
	setSteps(userParams[2]);
	setAntRow(userParams[3]);
	setAntCol(userParams[4]);
	setDir(0); 
}
/***************************************************************************
**   Description: The make board function takes a pointer to the board array
**                and fills it with space characters ' ' based on the user
**                specified size of the game board. This function takes a 
**                pointer to the array and returns nothing.
****************************************************************************/
void Ant::makeBoard(char** userBoard)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			userBoard[i][j] = ' ';
		}
	}
}
/***************************************************************************
**   Description: Print board first prints a legend to explain the ant color.
**                I chose to change the ant's * color based on the direction
**                it is pointing.  This prints at the top of each board so 
**                that the user has it for quick reference.  The printing
**                uses a nested for-loop to step through the array and 
**                contains nested if statements to detect where the ant is 
**                then print the ant with proper color.  The ant character
**                is never actually in the userBoard array, which made it
**                much easier to track the color (black/white) of the space
**                the ant is occupying. This function takes a pointer to the 
**                array and returns nothing.
****************************************************************************/
void Ant::printBoard(char** userBoard)
{
	std::cout << "\033[1;31mRed *\033[0m" << ":ant points " << "\033[1;31mnorth.\033[0m " << "\033[1;96mBlue *\033[0m" << ":ant points " << "\033[1;96msouth.\033[0m ";
	std::cout << "\033[1;92mGreen *\033[0m" << ":ant points " << "\033[1;92mwest.\033[0m " << "\033[1;95mMagenta *\033[0m" << ":ant points " << "\033[1;95meast.\033[0m " << std::endl << std::endl;
	for (int i = 0; i < cols + 4; i++)
	{
		std::cout << "_";
	}
	std::cout << std::endl;
	for (int i = 0; i < rows; i++)
	{
		std::cout << "| ";
		for (int j = 0; j < cols; j++)
		{   
			if (j == antCol && i == antRow)  //checks to see if the ant should go here.
			{    
				if (antDir == 0) //0 = north, 1 = east, 2 = south, 3 = west
				{
					std::cout << "\033[1;31m*\033[0m";
				}
				else if (antDir == 1)
				{
					std::cout << "\033[1;95m*\033[0m";
				}
				else if (antDir == 2)
				{
					std::cout << "\033[1;96m*\033[0m";
				}
				else if(antDir == 3)
				{
					std::cout << "\033[1;92m*\033[0m";
				}
			}
			else
			{
				std::cout << userBoard[i][j];
			}
		}
		std::cout << " |" << std::endl;
	}
	for (int i = 0; i < cols + 4; i++)
	{
		std::cout << "-";
	}
	std::cout << std::endl;
}
/***************************************************************************
**   Description: Taking a step involves first checking to see if the Ant is
**                facing a boundary. If so, the ant is moved to the other
**                side of the matrix.  If not, the ant moves forward normally.
**                This method then calls two other private helper functions to
**                turn the ant and toggle the color of the square.  This 
**                function takes a pointer to the array and returns nothing.
****************************************************************************/
void Ant::takeStep(char** userBoard)
{
	//is the Ant pointed at a boundary? If yes move, but clip ant to other side.
	if (antDir == 0 && antRow == 0)
	{
		antRow = rows - 1;
	}
	else if (antDir == 2 && antRow == (rows-1))
	{
		antRow = 0;
	}
	else if (antDir == 3 && antCol == 0)
	{
		antCol = cols - 1;
	}
	else if (antDir == 1 && antCol == (cols-1))
	{
		antCol = 0;
	}
	else  //ant is not facing a boundary
	{
		//move ahead from direction ant is facing.
		if (antDir == 0)           //north
		{
			antRow = antRow - 1;
		}
		else if (antDir == 1)      //east
		{
			antCol = antCol + 1;
		}
		else if (antDir == 2)     //south
		{
			antRow = antRow + 1;
		}
		else if (antDir == 3)     //west
		{
			antCol = antCol - 1;
		}
	}
	turnTheAnt(userBoard);
	toggleColor(userBoard);
}
/***************************************************************************
**   Description: Turning the Ant requires checking the color of the square
**                the Ant has landed on and turning 90 degrees left or right.
**                antDir can be 0, 1, 2, or 3, which correspond to 0, 90, 180
**                and 270 degrees. This function takes a pointer to the array 
**                and returns nothing.
****************************************************************************/
void Ant::turnTheAnt(char** userBoard)
{
	if (userBoard[antRow][antCol] == '#')  //on a black
	{
		if (antDir == 0)
		{
			antDir = 3;
		}
		else
		{
			antDir = antDir - 1;
		}
	}
	else if (userBoard[antRow][antCol] == ' ') //on a white
	{
		if (antDir == 3)
		{
			antDir = 0;
		}
		else
		{
			antDir = antDir + 1;
		}
	}
}
/***************************************************************************
**   Description: Toggling the color of the square the Ant has landed on is
**                performed here and is very simple.  The value of the matrix
**                is checked and then the opposite value is applied. This 
**                function takes a pointer to the array and returns nothing.
****************************************************************************/
void Ant::toggleColor(char** userBoard)
{
	if (userBoard[antRow][antCol] == '#')
	{
		userBoard[antRow][antCol] = ' ';
	}
	else if (userBoard[antRow][antCol] == ' ')
	{
		userBoard[antRow][antCol] = '#';
	}
}
//set method for initial number of rows
void Ant::setRows(int initRows)
{
	rows = initRows;
}
//set method for initial number of columns
void Ant::setCols(int initCols)
{
	cols = initCols;
}
//set method for initial number of steps
void Ant::setSteps(int initSteps)
{
	steps = initSteps;
}
//set method for initial ant row
void Ant::setAntRow(int initX)
{
	antRow = initX;
}
//set method for initial ant column
void Ant::setAntCol(int initY)
{
	antCol = initY;
}
//set method for initial ant direction
void Ant::setDir(int initDir)
{
	antDir = initDir;
}