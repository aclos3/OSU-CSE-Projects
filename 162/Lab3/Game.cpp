/***************************************************************************
**   Program Name: Lab 3 (Game.cpp)
**   Author: Andrew Clos
**   Date: 7/11/2019
**   Description: The program runs mostly from this Class. There is a default
**				  constructor to establish a game with basic parameters. It 
**				  includes functions to show the menus, take userInput (with 
**				  calls to validation), display the game parameters, begin 
**			      the rounds, show the final score and prompt the user to ask
**				  if they'd like to play again.
****************************************************************************/

#include<iostream>
#include<iomanip>
#include<random>
#include<string>
#include "Game.hpp"
#include "InputValidate.hpp"
#include "Die.hpp"

const char YESLIMITS = 'y';
//constants for min and max game parameters that aren't to be changed by the user.
const int	MINROUNDS = 1,
			MAXROUNDS = 1000,
			MINDICESIDES = 1,
			MAXDICESIDES = 20;

/***************************************************************************
**   Description: default constructor to establish a six sided dice for each
**				  player, scores of zero and one round for the game. Also, 
**				  each player starts as non-Loaded Dice types.
***************************************************************************/
Game::Game()
{
	p1Score = 0;
	p2Score = 0;
	setP1Sides(6);
	setP2Sides(6);
	setRounds(1);
	setP1Loaded(false);
	setP2Loaded(false);
}
/***************************************************************************
**   Description: default destructor.
***************************************************************************/
Game::~Game()
{

}
/***************************************************************************
**   Description: This function welcomes the user and gives them the option
**                to begin the game or quit.  A while loop keeps the program
**				  running and the various game functions are called in order
**				  from this loop.  Also in the while loop is a counter, so 
**				  that a new menu option to run the same simulation again can
**				  be added after the first game is played.
****************************************************************************/
void Game::mainMenu()
{
	int menuChoice = 0,
		runCounter = 0;
	InputValidate mainMenuCheck;
	bool active = true;

	while (active)
	{
		std::cout << "Welcome to War Game!" << std::endl;
		std::cout << "Andrew Clos, CS162-400, Lab 3." << std::endl;
		std::cout << "(1) Start War Game." << std::endl;
		std::cout << "(2) Quit." << std::endl;
		if (runCounter != 0)  //we don't want this menu option visible for the first run of the program.
		{
			std::cout << "(3) Run the game again with the same parameters as last time." << std::endl;
			menuChoice = mainMenuCheck.intValidate(YESLIMITS, 1, 3);
		}
		else
		{
			menuChoice = mainMenuCheck.intValidate(YESLIMITS, 1, 2);
		}
		//starts a new game
		if (menuChoice == 1)  
		{
			paramMenu();
			//printing three random ASCII dice for fun
			printDice();
			printDice();
			printDice();
			showParams();
			beginGame();
			endGame(p1Score, p2Score);
			std::cout << std::endl << "Thank you for playing, now returning you to the main menu." << std::endl << std::endl;
		} //starts a new game, but skips the user entry prompts and runs with values from the last iteration
		else if (menuChoice == 3)  
		{
			beginGame();
			endGame(p1Score, p2Score);
			std::cout << std::endl << "Thank you for playing, now returning you to the main menu." << std::endl << std::endl;
		}
		else  //quit
		{
			active = false;
		}
		runCounter++;
	}
}
/***************************************************************************
**   Description: Print's ASCII dice to the screen, randomly with one to six
**			      sides.              
****************************************************************************/
void Game::printDice()
{
	//source cited for help with "true" random number generation: https://stackoverflow.com/questions/19665818/generate-random-numbers-using-c11-random-library
	std::random_device randDev;
	std::mt19937 randSeed(randDev());
	std::uniform_int_distribution<> randomDice(1, 6);
	int roll = randomDice(randSeed);

	if (roll == 1)
	{
		std::cout << "  #########   " << std::endl;
		std::cout << "  #       #   " << std::endl;
		std::cout << "  #   O   #   " << std::endl;
		std::cout << "  #       #   " << std::endl;
		std::cout << "  #########   " << std::endl;
	}
	else if (roll == 2)
	{
		std::cout << "  #########   " << std::endl;
		std::cout << "  # O     #   " << std::endl;
		std::cout << "  #       #   " << std::endl;
		std::cout << "  #     O #   " << std::endl;
		std::cout << "  #########   " << std::endl;
	}
	else if (roll == 3)
	{
		std::cout << "  #########   " << std::endl;
		std::cout << "  # O     #   " << std::endl;
		std::cout << "  #   O   #   " << std::endl;
		std::cout << "  #     O #   " << std::endl;
		std::cout << "  #########   " << std::endl;
	}
	else if (roll == 4)
	{
		std::cout << "  #########   " << std::endl;
		std::cout << "  # O   O #   " << std::endl;
		std::cout << "  #       #   " << std::endl;
		std::cout << "  # O   O #   " << std::endl;
		std::cout << "  #########   " << std::endl;
	}
	else if (roll == 5)
	{
		std::cout << "  #########   " << std::endl;
		std::cout << "  # O   O #   " << std::endl;
		std::cout << "  #   O   #   " << std::endl;
		std::cout << "  # O   O #   " << std::endl;
		std::cout << "  #########   " << std::endl;
	}
	else if (roll == 6)
	{
		std::cout << "  #########   " << std::endl;
		std::cout << "  # O   O #   " << std::endl;
		std::cout << "  # O   O #   " << std::endl;
		std::cout << "  # O   O #   " << std::endl;
		std::cout << "  #########   " << std::endl;
	}
}
/***************************************************************************
**   Description: This function handles reception of the user entered data.
**                It makes calls for input validation and then calls the set 
**                methods to set the game's private member variables.
****************************************************************************/
void Game::paramMenu()
{   
	InputValidate paramMenuCheck;

	std::cout << "War Game Started!" << std::endl;
	std::cout << "Please enter the number of rounds you'd like to play (an integer between " << MINROUNDS << " and " << MAXROUNDS << "): ";
	setRounds(paramMenuCheck.intValidate(YESLIMITS, MINROUNDS, MAXROUNDS));
	std::cout << "Would you like Player 1's dice to be loaded? ('Y' or 'y' = Yes, 'N' or 'n' = No): ";
	setP1Loaded(paramMenuCheck.boolValidate());
	std::cout << "Would you like Player 2's dice to be loaded? ('Y' or 'y' = Yes, 'N' or 'n' = No): ";
	setP2Loaded(paramMenuCheck.boolValidate());
	std::cout << "Please enter the number of dice sides for Player 1 (an integer between " << MINDICESIDES << " and " << MAXDICESIDES << "): ";
	setP1Sides(paramMenuCheck.intValidate(YESLIMITS, MINDICESIDES, MAXDICESIDES));
	std::cout << "Please enter the number of dice sides for Player 2 (an integer between " << MINDICESIDES << " and " << MAXDICESIDES << "): ";
	setP2Sides(paramMenuCheck.intValidate(YESLIMITS, MINDICESIDES, MAXDICESIDES));
}
/***************************************************************************
**   Description: Displays the game parameter legend and prints this game's
**                user parameters to the console.  
****************************************************************************/
void Game::showParams()
{
	std::cout << "Game Parameter Definition: [Rounds, Player 1 Dice, Player 2 Dice, Player 1 Sides, Player 2 Sides]" << std::endl;
	std::cout << "This game's parameters:    [   " << rounds << ", ";
	if (p1Loaded == true)
	{
		std::cout << std::setw(13);
		std::cout << "Loaded,";
	}
	else 
	{
		std::cout << std::setw(13);
		std::cout << "Normal,";
	}
	if (p2Loaded == true)
	{
		std::cout << std::setw(13);
		std::cout << "Loaded,";
	}
	else
	{
		std::cout << std::setw(13);
		std::cout << "Normal,";
	}
	std::cout << std::setw(12);
	std::cout << " " << p1Sides;
	std::cout << std::setw(15);
	std::cout << " " << p2Sides << "      ]" << std::endl;
}

/***************************************************************************
**   Description: Initializes the Die and/or LoadedDie Objects, and then
**				  begins stepping through the rounds by calling the Die or
**				  LoadedDie's rollDice function and tallies the score.
**				  Then, it sets the final scores for Player 1 and 2.
****************************************************************************/
void Game::beginGame()
{
	int p1Total = 0,
		p2Total = 0,
		p1RoundScore = 0,
		p2RoundScore = 0;
	std::string p1 = "",
				p2 = "";

	//this pair of if-else statements initializes the Die to their proper types.
	if (p1Loaded == true)
	{
		dieP1 = new LoadedDie(p1Sides);
		p1 = "Loaded ";
	}
	else
	{
		dieP1 = new Die(p1Sides);
		p1 = "Normal ";
	}
	if (p2Loaded == true)
	{
		dieP2 = new LoadedDie(p2Sides);
		p2 = "Loaded ";
	}
	else
	{
		dieP2 = new Die(p2Sides);
		p2 = "Normal ";
	}
	//step through each round, rolling dice, printing results and tallying scores.
	for (int i = 0; i < rounds; i++) 
	{
		p1RoundScore = dieP1->rollDice();
		p2RoundScore = dieP2->rollDice();

		std::cout << std::endl << "**** Round " << i + 1 << " ****" << std::endl;
		std::cout << "Player 1's " << dieP1->getDiceSides() << " sided, " << p1 << "die, rolled a: " << p1RoundScore << std::endl;
		std::cout << "Player 2's " << dieP2->getDiceSides() << " sided, " << p2 << "die, rolled a: " << p2RoundScore << std::endl;
		if (p1RoundScore > p2RoundScore)
		{
			std::cout << "Player 1 won this round by " << p1RoundScore - p2RoundScore << " points!" << std::endl;
		}
		else if (p2RoundScore > p1RoundScore)
		{
			std::cout << "Player 2 won this round by " << p2RoundScore - p1RoundScore << " points!" << std::endl;
		}
		else
		{
			std::cout << "This round was a draw." << std::endl;
		}
		p1Total = p1Total + p1RoundScore;
		p2Total = p2Total + p2RoundScore;
		std::cout << "The overall score so far is, Player 1: " << p1Total << ". Player 2: " << p2Total << "." << std::endl;
	}
	//delete the dynamic objects to free up memory.
	delete dieP1;
	delete dieP2;

	setP1Score(p1Total);
	setP2Score(p2Total);
}
/***************************************************************************
**   Description: The endGame function declares a winner and prints the score
**				  of each player.
****************************************************************************/
void Game::endGame(int p1, int p2)
{
	std::cout << std::endl << "Here are the results of the game!" << std::endl;
	if (p1 > p2)
	{
		std::cout << "Player 1 won the the game by a score of "<< p1 << " to " << p2 << ". That's a difference of " << p1 - p2 << " points!" << std::endl;
	}
	else if (p2 > p1)
	{
		std::cout << "Player 2 won the the game by a score of " << p2 << " to " << p1 << ". That's a difference of " << p2 - p1 << " points!" << std::endl;
	}
	else
	{
		std::cout << "This game resulted in a draw." << std::endl;
	}
}
/***************************************************************************
**   Description: The following seven functions are just set methods for the
**				  user defined parameters and player scores.
****************************************************************************/
void Game::setRounds(int userRounds)
{
	rounds = userRounds;
}
void Game::setP1Sides(int userP1Sides)
{
	p1Sides = userP1Sides;
}
void Game::setP2Sides(int userP2Sides)
{
	p2Sides = userP2Sides;
}
void Game::setP1Loaded(bool userP1Load)
{
	p1Loaded = userP1Load;
}
void Game::setP2Loaded(bool userP2Load)
{
	p2Loaded = userP2Load;
}
void Game::setP1Score(int gameP1Score)
{
	p1Score = gameP1Score;
}
void Game::setP2Score(int gameP2Score)
{
	p2Score = gameP2Score;
}