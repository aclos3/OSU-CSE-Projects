/***************************************************************************
**   Program Name: Project 1 (main.cpp)
**   Author: Andrew Clos
**   Date:
**   Description: Each simulation will require a Menu and an Ant class that are 
**                initialized/called in the main method. Additionally, since 
**                the board size is user defined, a dynamically allocated 2d
**                array is needed.  The main method uses values in the 
**                gameParams array to operate functions that establish a board,
**                print the board and have the ant take steps.
****************************************************************************/

#include<iostream>
#include<array>
#include "Ant.hpp"
#include "Menu.hpp"

int main()
{
	bool playing = true;

	//Welcome user with the main menu
	Menu menu1;
	playing = menu1.mainMenu();

	while (playing)
	{
		int gameParams[5] = { 0,0,0,0,0 };
		//start the simulation by collecting the user defined parameters
		menu1.paramMenu(gameParams);

		// dynamically allocated 2d array for the game board. Many functions of Ant will use this.
		char **board = new char*[gameParams[0]];

		for (int i = 0; i < gameParams[0]; i++)
		{
			board[i] = new char[gameParams[1]];
		}
		//with game parameters established, make a new Ant and send it the parameters (point to array)
		Ant ant1(gameParams);
		//make a new board and print it
		ant1.makeBoard(board);
		ant1.printBoard(board);
		//start executing the steps
		for (int i = 0; i < gameParams[2]; i++) 
		{    
			ant1.takeStep(board);
			//the board and step count are printed with each step. Remove
			//these lines and/or comment out the step count for faster printing 
			ant1.printBoard(board);
			std::cout << "Step Count: " << i + 1 << std::endl;
		}
		//remove the dynamically allocated array from memory.
		for (int i = 0; i < gameParams[0]; i++)
		{
			delete[] board[i];
		}
		delete[] board;
		//ask if the user wants to play again.
		playing = menu1.playAgain();
	}
    return 0;
}
