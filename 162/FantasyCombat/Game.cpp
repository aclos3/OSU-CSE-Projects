/***************************************************************************
**   Program Name: Project 3 (Game.cpp)
**   Author: Andrew Clos
**   Date: 7/31/2019
**   Description: The game contains private member variables for pointers to
**				  Character class objects. There is also a private member
**				  function to view the current stats of the game. Public
**				  functions include the initial and choose characters menus
**				  as well as a print function to display the characters.
**				  Additionally, there is a function to create the new classes
**				  at the start of a function to print end-game stats, to
**				  perform combat, and check to see if the characters are both
**				  still alive.
****************************************************************************/

#include<iostream>
#include<random>
#include<string>
#include "Game.hpp"


/***************************************************************************
**   Description: Default constructor
***************************************************************************/
Game::Game()
{

}

/***************************************************************************
**   Description: Initial game menu to greet player and have them choose
**				  their class.
***************************************************************************/
int Game::initMenu(int playerNum)
{
	int playerClass = 0;

	std::cout << "Player " << playerNum << ", please choose your class." << std::endl;
	playerClass = chooseChar();

	return playerClass;
}

/***************************************************************************
**   Description: Players select a class, calls to input validation are made
**				  and the player has the option to view the description of
**				  the character and optionally choose another one. A new 
**				  instance of the character class is created and then 
**				  destroyed for the viewing of the description. The function
**				  returns the class of the chosen character as an integer.
***************************************************************************/
int Game::chooseChar()
{
	int playerClass = 0;
	bool charChosen = false;
	InputValidate charTest;

	//remain in loop until character is chosen.
	while (!charChosen)
	{
		displayChars();
		playerClass = charTest.intValidate(YESLIMITS, MINCLASS, MAXCLASS);

		if (playerClass == 1)
		{   //each of these if-statements creates a class of chosen character, but gives
			//the user the option to choose again.  These classes are then destroyed.
			p1 = new Barbarian();
			if (menuViewStats(p1) == 2)
			{
				std::cout << "Please choose again." << std::endl;
				delete p1;
			}
			else
			{
				charChosen = true;
				delete p1;
			}
		}
		else if (playerClass == 2)
		{
			p1 = new Vampire();
			if (menuViewStats(p1) == 2)
			{
				std::cout << "Please choose again." << std::endl;
				delete p1;
			}
			else
			{
				charChosen = true;
				delete p1;
			}
		}
		else if (playerClass == 3)
		{
			p1 = new BlueMen();
			if (menuViewStats(p1) == 2)
			{
				std::cout << "Please choose again." << std::endl;
				delete p1;
			}
			else
			{
				charChosen = true;
				delete p1;
			}
		}
		else if (playerClass == 4)
		{
			p1 = new Medusa();
			if (menuViewStats(p1) == 2)
			{
				std::cout << "Please choose again." << std::endl;
				delete p1;
			}
			else
			{
				charChosen = true;
				delete p1;
			}
		}
		else if (playerClass == 5)
		{
			p1 = new HarryPotter();
			if (menuViewStats(p1) == 2)
			{
				std::cout << "Please choose again." << std::endl;
				delete p1;
			}
			else
			{
				charChosen = true;
				delete p1;
			}
		}
		else if (playerClass == 6)
		{
			charChosen = true;
		}
	}

	return playerClass;
}

/***************************************************************************
**   Description: Display each character menu option to the console.
***************************************************************************/
void Game::displayChars()
{
	std::cout << "(1) " << "\033[1;31mBarbarian\033[0m" << std::endl;
	std::cout << "(2) " << "\033[1;35mVampire\033[0m " << std::endl;
	std::cout << "(3) " << "\033[1;96mBlue Men\033[0m " << std::endl;
	std::cout << "(4) " << "\033[1;32mMedusa\033[0m " << std::endl;
	std::cout << "(5) " << "\033[1;33mHarry Potter\033[0m " << std::endl;
	std::cout << "(6) Quit." << std::endl;
}

/***************************************************************************
**   Description: Give the user the choice to view the description of the
**				  character and keep it or pick a new one.
***************************************************************************/
int Game::menuViewStats(Character *inQuestion)
{
	int statsDecision = 0,
		classDecision = 0;
	InputValidate tester;

	std::cout << "You've chosen the " << inQuestion->getClass() << " Would you like to view its stats?" << std::endl;
	std::cout << "(1) Yes." << std::endl;
	std::cout << "(2) No." << std::endl;
	statsDecision = tester.intValidate(YESLIMITS, MINYN, MAXYN);

	if (statsDecision == 1)
	{
		inQuestion->showDescription();
		
		std::cout << "After viewing the stats, would you like to keep the " << inQuestion->getClass() << "?" << std::endl;
		std::cout << "(1) Yes." << std::endl;
		std::cout << "(2) No." << std::endl;
		classDecision = tester.intValidate(YESLIMITS, MINYN, MAXYN);
	}
	return classDecision;
}

/***************************************************************************
**   Description: Based on the user's picks, the new chacters are created.
***************************************************************************/
void Game::createClasses(int * players, int numPlayers)
{
	if (players[0] == 1)
	{
		p1 = new Barbarian();
		p1->setPlayerNum(1);
	}
	else if (players[0] == 2)
	{
		p1 = new Vampire();
		p1->setPlayerNum(1);
	}
	else if (players[0] == 3)
	{
		p1 = new BlueMen();
		p1->setPlayerNum(1);
	}
	else if (players[0] == 4)
	{
		p1 = new Medusa();
		p1->setPlayerNum(1);
	}
	else if (players[0] == 5)
	{
		p1 = new HarryPotter();
		p1->setPlayerNum(1);
	}
	else  //in case a value other than 1,2,3,4 or 5 makes its way through this function.
	{
		std::cout << "An error has occurred, no character created for p1." << std::endl;
	}
	

	if (players[1] == 1)
	{
		p2 = new Barbarian();
		p2->setPlayerNum(2);
	}
	else if (players[1] == 2)
	{
		p2 = new Vampire();
		p2->setPlayerNum(2);
	}
	else if (players[1] == 3)
	{
		p2 = new BlueMen();
		p2->setPlayerNum(2);
	}
	else if (players[1] == 4)
	{
		p2 = new Medusa();
		p2->setPlayerNum(2);
	}
	else if (players[1] == 5)
	{
		p2 = new HarryPotter();
		p2->setPlayerNum(2);
	}
	else
	{
		std::cout << "An error has occurred, no character created for p2." << std::endl;
	}

	std::cout << "Player 1 is a: " << p1->getClass() << "!" << std::endl;
	std::cout << "Player 2 is a: " << p2->getClass() << "!" << std::endl;
}

/***************************************************************************
**   Description: Performs column alignment and printing of the games round
**				  number and each characters strength and armor.
***************************************************************************/
void Game::printStats(int roundNum)
{
	for (unsigned int i = 0; i < COLS; i++)  //print top border
	{
		std::cout << "+";
	}
	std::cout << std::endl;

	//print player 1 line
	std::cout << "| Round: " << roundNum;
	
	//column alignment if-statements to add spaces depending on str and round number size
	if (roundNum < 10)
	{
		std::cout << " ";
	}
	if (roundNum < 100)
	{
		std::cout << " ";
	}
	std::cout << " Player 1: " << p1->getClass();
	for (unsigned int i = 0; i < (RIGHTCOLS - p1->getClass().length()); i++)
	{
		std::cout << " ";
	}
	std::cout << "----  Strength: " << p1->getStr();
	if (p1->getStr() < 10)
	{
		std::cout << " ";
	}
	std::cout << "  ----  Armor: " << p1->getArmor() << ".                            |" << std::endl;
	
	//print player 2 line
	std::cout << "|            Player 2: " << p2->getClass();
	for (unsigned int i = 0; i < (RIGHTCOLS - p2->getClass().length()); i++)
	{
		std::cout << " ";
	}
	std::cout << "----  Strength: " << p2->getStr();
	if (p2->getStr() < 10)
	{
		std::cout << " ";
	}
	std::cout << "  ----  Armor: " << p2->getArmor() << ".                            |" << std::endl;

	for (int i = 0; i < COLS; i++)  //print bottom border
	{
		std::cout << "+";
	}
	std::cout << std::endl;
}

/***************************************************************************
**   Description: Checks to see if both characters are alive.  If one is dead,
**				  a message is optionally displayed to the console.  This 
**				  function takes a bool to toggle displaying of the text to
**				  console.
***************************************************************************/
int Game::characterAlive(bool broadcast)
{
	int status = 0;
	
	if (!(p1->isAlive()))
	{
		if (broadcast == false)
		{
			status = status + 1;
		}
		else
		{
			std::cout << std::endl << "Player 1's " << p1->getClass() << " has " << "\033[1;97mdied\033[0m" << "." << std::endl << "Player 2 is the winner!" << std::endl;
			status = status + 1;
		}
	}
	if (!(p2->isAlive()))
	{
		if (broadcast == false)
		{
			status = status + 2;
		}
		else
		{
			std::cout << std::endl << "Player 2's " << p2->getClass() << " has " << "\033[1;97mdied\033[0m" << "." << std::endl << "Player 1 is the winner!" << std::endl;
			status = status + 2;
		}
	}

	return status;	
}

/***************************************************************************
**   Description: Randomly decides a player to start the combat and then each
**				  player makes their attacks and defenses.  Checks to see if
**				  a character has died after each attack.
***************************************************************************/
void Game::combat()
{
	std::random_device randStarter;
	std::mt19937 randSeed(randStarter());
	std::uniform_int_distribution<> randomStarter(1, 2);
	int roll = 0;
	
	roll = randomStarter(randSeed);

	//toss a coin to determine who attacks first in each round.  
	if (roll == 1)
	{
		std::cout << "Player 1 attacks first:" << std::endl;
		//perform attack and subsequent defense.
		p2->defend(p1->attack(p1), p2);
		if (characterAlive(false) == 0)
		{  //if still alive, other player performs their attack.
			std::cout << "Now Player 2 attacks: " << std::endl;
			p1->defend(p2->attack(p2), p1);
		}
	}
	if (roll == 2)
	{
		std::cout << "Player 2 attacks first:" << std::endl;
		
		p1->defend(p2->attack(p2), p1);
		if (characterAlive(false) == 0)
		{
			std::cout << "Now Player 1 attacks: " << std::endl;
			p2->defend(p1->attack(p1), p2);
		}
	}
}

/***************************************************************************
**   Description: Shows end of game statistics from a vector of doubles that 
**				  stores this data. A game has been played and has ended if
**				  this function is called, so at the end of the function
**				  the player characters are deleted to free memory.
***************************************************************************/
void Game::showStats()
{    //player 1
	std::cout << std::endl << "Player 1(" << p1->getClass() << "):" << std::endl;
	std::cout << "Attacks made:               " << p1->getLiveStats().at(0) << std::endl;
	std::cout << "Total damage done:          " << p1->getLiveStats().at(1) << std::endl;
	if (p1->getLiveStats().at(0) != 0)
	{
		std::cout << "Average damage per attack:  " << p1->getLiveStats().at(1) / p1->getLiveStats().at(0) << std::endl;
	}
	else
	{
		std::cout << "Average damage per attack:  0" << std::endl;
	}
	std::cout << "Defenses made:              " << p1->getLiveStats().at(2) << std::endl;
	std::cout << "Total damage mitigation:    " << p1->getLiveStats().at(3) + p1->getLiveStats().at(4) << std::endl;
	std::cout << "Total roll mitigation:      " << p1->getLiveStats().at(3) << std::endl;
	std::cout << "Total armor mitigation:     " << p1->getLiveStats().at(4) << std::endl;
	if (p1->getLiveStats().at(2) != 0)
	{
		std::cout << "Average mitigation / round: " << (p1->getLiveStats().at(3) + p1->getLiveStats().at(4)) / p1->getLiveStats().at(2) << std::endl;
	}
	else
	{
		std::cout << "Average mitigation / round: 0" << std::endl;
	}

	//player 2
	std::cout << std::endl << "Player 2(" << p2->getClass() << "):" << std::endl;
	std::cout << "Attacks made:               " << p2->getLiveStats().at(0) << std::endl;
	std::cout << "Total damage done:          " << p2->getLiveStats().at(1) << std::endl;
	if (p2->getLiveStats().at(0) != 0)
	{
		std::cout << "Average damage per attack:  " << p2->getLiveStats().at(1) / p2->getLiveStats().at(0) << std::endl;
	}
	else
	{
		std::cout << "Average damage per attack:  0" << std::endl;
	}
	std::cout << "Defenses made:              " << p2->getLiveStats().at(2) << std::endl;
	std::cout << "Total damage mitigation:    " << p2->getLiveStats().at(3) + p2->getLiveStats().at(4) << std::endl;
	std::cout << "Total roll mitigation:      " << p2->getLiveStats().at(3) << std::endl;
	std::cout << "Total armor mitigation:     " << p2->getLiveStats().at(4) << std::endl;
	if (p2->getLiveStats().at(2) != 0)
	{
		std::cout << "Average mitigation / round: " << (p2->getLiveStats().at(3) + p2->getLiveStats().at(4)) / p2->getLiveStats().at(2) << std::endl;
	}
	else
	{
		std::cout << "Average mitigation / round: 0" << std::endl;
	}
	
	//game has ended, so delete the dynamically allocated characters.
	delete p1;
	delete p2;
}

