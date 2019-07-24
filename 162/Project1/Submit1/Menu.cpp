/***************************************************************************
**   Program Name: Project 1 (Menu.cpp)
**   Author: Andrew Clos
**   Date:
**   Description: The Menu class is what first greets the user and from this
**                class, menu options are presented, game parameters are 
**                gathered from the user and validated.  Input validation and
**                each menu level were given their own functions
**                to an arry of integers.   
****************************************************************************/

#include<iostream>
#include<string>
#include<sstream>
#include<random>
#include "Menu.hpp"

const char YESLIMITS = 'y';

/***************************************************************************
**   Description: This function welcomes the user and gives them the option
**                to begin the simulation or quit.  This portion was kept 
**                separate from the paramMenu user data collection so that it
**                can be called once when the program is started, but doesn't
**                need to be repeated if the user elects to play again.  The
**                function returns a bool to the caller true=begin, false=quit.
****************************************************************************/
bool Menu::mainMenu()
{
	int menuChoice = 0;
	
	std::cout << "Welcome to Langton's Ant!" << std::endl;
	std::cout << "Andrew Clos, CS162-400, Project 1." << std::endl;
	std::cout << "(1) Start Langton's Ant simulation." << std::endl;
	std::cout << "(2) Quit." << std::endl;
	menuChoice = intValidate(YESLIMITS, 1, 2);
	if (menuChoice == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/***************************************************************************
**   Description: This function initializes variables to establish row, column
**                and step limits and then displays the prompts to get user
**                input for the game parameters.  These parameters are stored
**                in an array.  The array is passed to the function as a 
**                pointer.
****************************************************************************/
void Menu::paramMenu(int *params)
{
	bool mainMenu = true;
	int menuChoiceRandom = 0,
		 minRow = 1,  //defining min and max values for the board size
		 maxRow = 150,
		 minCol = 1,
		 maxCol = 150,
		 minSteps = 1,
		 maxSteps = 32767;
	//while loop collects all necessary parameters from user and stores them in an array
	while (mainMenu)
	{
		std::cout << "Langton's Ant Simulation Started!" << std::endl;
		std::cout << "                \\(* *)/" << std::endl;
		std::cout << "                  (A) " << std::endl;
		std::cout << "                --(R)-- " << std::endl;
		std::cout << "                  (C)  " << std::endl;
		std::cout << "                 /(|)\\ " << std::endl;
		std::cout << "Please enter the number of rows for the board (an integer between " << minRow << " and " << maxRow << "): ";
		params[0] = intValidate(YESLIMITS, minRow, maxRow);
		std::cout << "You've chosen a board that is " << params[0] << " rows tall (cells numbered 0 through " << params[0] - 1 << ")." << std::endl;
		std::cout << "Please enter the number of columns for the board (an integer between " << minCol << " and " << maxCol << "): ";
		params[1] = intValidate(YESLIMITS, minCol, maxCol);
		std::cout << "You've chosen a board that is " << params[1] << " columns wide (cells numbered 0 through " << params[1] - 1 << ")." << std::endl;
		std::cout << "Please enter the number of steps for the ant to take (an integer between " << minSteps << " and " << maxSteps << "): " << std::endl;
		params[2] = intValidate(YESLIMITS, minSteps, maxSteps);
		std::cout << "You've directed the Ant to take " << params[2] << " steps." << std::endl;
		std::cout << "***I am including Random Ant Start as Extra Credit***" << std::endl;
		std::cout << "(1) I'd like the Ant to start at a random location." << std::endl;
		std::cout << "(2) I'd like to choose the starting location of the Ant." << std::endl;
		menuChoiceRandom = intValidate(YESLIMITS, 1, 2);
		
		//**Extra credit** I chose to add the random ant start location as an option.
		if (menuChoiceRandom == 1)
		{  // source cited for C++11 random use: https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
			std::random_device randDev;
			std::mt19937 randSeed(randDev());
			std::uniform_int_distribution<> randomRow(0, params[0] - 1);
			params[3] = randomRow(randSeed);
			std::uniform_int_distribution<> randomCol(0, params[1] - 1);
			params[4] = randomCol(randSeed);
			std::cout << "Random Ant Starting onlocation is row: " << params[3] << ", column: " << params[4] << std::endl;
			mainMenu = false;
		}
		else
		{
			std::cout << "Please enter the starting row for the ant (an integer between 0 and " << params[0] - 1 << ")." << std::endl;
			params[3] = intValidate(YESLIMITS, 0, params[0] - 1);
			std::cout << "Please enter the starting column for the ant (an integer between 0 and " << params[1] - 1 << ")." << std::endl;
			params[4] = intValidate(YESLIMITS, 0, params[1] - 1);
			mainMenu = false;
		}
	}
	gameParameters(params);
	mainMenu = false;
}
/***************************************************************************
**   Description: Integer input validation. This function prompts the user to
**                enter data and takes that input as a string. It steps 
**                through the string to make sure each character is a valid 
**                digit 0 - 9. The first character is also allowed to be a '-'
**                symbol to indicate a negative number. If the characters are
**                found to be valid digits, the string is converted to an int
**                and if use-limits is flagged ('y') by the caller, the 
**                integer will be checked against the upper and lower limits.
**                The function returns an integer and takes a character and two
**                integers as arguements to perform optional limit checking.
****************************************************************************/
int Menu::intValidate(char useLimits, int lowerLimit, int upperLimit)
{
	bool intValid = true;
	int userInt = 0;
	std::string userEntry = "";

	while (intValid)
	{
		int badCount = 0;

		std::cin >> userEntry;
		//step through the string and make sure each value is an integer.
		for (unsigned int i = 0; i < userEntry.length(); i++)
		{
			if (i == 0)
			{
				if (userEntry[i] != 45 && (userEntry[i] > 57 || userEntry[i] < 48))
				{
					std::cout << "'" << userEntry[i] << "' is not a valid digit, please try again." << std::endl;
					badCount++;
				}
			}
			else if (userEntry[i] > 57 || userEntry[i] < 48)
			{
				std::cout << "'" << userEntry[i] << "' is not a valid digit, please try again." << std::endl;
				badCount++;
			}
		}
		if (badCount == 0) //if the string passes the digit check badCount will be 0.
		{
			std::istringstream(userEntry) >> userInt;
			intValid = false;
			
			if (useLimits == 'y') //perform optional size validation
			{
				intValid = true;

				if (userInt < lowerLimit)
				{
					std::cout << "Entry is below the lower limit, please try again." << std::endl;
				}
				else if (userInt > upperLimit)
				{
					std::cout << "Entry is above the upper limit, please try again." << std::endl;
				}
				else
				{
					intValid = false;
				}
			}
		}
		else
		{
			std::cout << "A total of " << badCount << " out of " << userEntry.length() << " characters entered were not valid integer elements." << std::endl;
		}
		std::cin.clear();
		std::cin.ignore(32767, '\n');
	}
	return userInt;
}
/***************************************************************************
**   Description: TDisplays the game parameter legend and prints this game's
**                user parameters to the console.  It is called only after
**                user entry is completed, but was made a separate, public
**                function in case I wanted to add a "reprint" user 
**                parameters option to the menu.  It takes a pointer to an 
**                array of game parameters.
****************************************************************************/
void Menu::gameParameters(int* gameParams)
{
	std::cout << "Game Parameter Definition: [rows, columns, steps, starting row, starting column ]" << std::endl;
	std::cout << "This session's parameters: [";

	for (int i = 0; i < 5; i++)
	{
		if (i == 4)
		{
			std::cout << gameParams[i] << " ";
		}
		else
		{
			std::cout << gameParams[i] << ", ";
		}
	}
	std::cout << "]" << std::endl;
}
/***************************************************************************
**   Description: The play again function is called to ask the user if they
**                want to quit or play again. This returns true or false
**                true = play again, false = quit.
****************************************************************************/
bool Menu::playAgain()
{
	int menuChoice = 0;

	std::cout << "(1) Play Again." << std::endl;
	std::cout << "(2) Quit." << std::endl;
	menuChoice = intValidate(YESLIMITS, 1, 2);

	if (menuChoice == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
