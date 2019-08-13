/*************************************************************************** 
**   Program Name: Final Project (Menu.hpp)
**   Author: Andrew Clos
**   Date: 8/12/2019
**   Description: The haeder file for the menu class contains many constants
**				  used throughout the class for min and max menu entries and
**				  parameters used to control the map and digging functions
**				  The Menu controls map updates and displays as well as 
**				  presenting options for the user via the console.  
****************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include"Player.hpp"

const int MINMENU = 1;
const int MAXMENU = 2;
const int MINMOVE = 1;
const int MAXMOVE = 9;
const int MAPROWS = 25;
const int MAPCOLS = 75;
const int MAXNAME = 30;
const int STRAIGHTDIG = 8;
const int DIAGONALDIG = 23;
const int ROOMROWS = 5; 
const int ROOMCOLS = 15;
const char YESLIMITS = 'y';
const char PLAYERSYMBOL = '@';
const char EMPTYSYMBOL = 'o';


class Menu
{
private:
	int numRows;
	int numCols;
	
public:
	Menu();
	int mainMenu(Player*);
	char** buildMap(Player*);
	void displayMap(char**);
	void displayInstructions(Player*);
	int movePlayer(char**, Player*, int);
	void removeBoard(char**);
	void digPath(char**, int);
	void setRows(int);
	void setCols(int);

	~Menu();
	
};
#endif