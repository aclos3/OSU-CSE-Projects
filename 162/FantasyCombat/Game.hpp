/*************************************************************************** 
**   Program Name: Project 3 (Game.hpp)
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

#ifndef GAME_HPP
#define GAME_HPP

#include "InputValidate.hpp"
#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

//constants for upper and lower limits of user choices.
const int MINCLASS = 1;
const int MAXCLASS = 6;
const int MINYN = 1;
const int MAXYN = 2;
const int NUMCLASSES = 5;
const int COLS = 100;
const int RIGHTCOLS = 24;
const char YESLIMITS = 'y';


class Game
{
private:
	
	Character * p1;
	Character * p2;
	int menuViewStats(Character*);

public:
	Game();
	int initMenu(int);
	int chooseChar();
	void displayChars();
	void createClasses(int*, int);
	void printStats(int);
	int characterAlive(bool);
	void combat();
	void showStats();
};
#endif