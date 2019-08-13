/*************************************************************************** 
**   Program Name: Project 1 (Menu.hpp)
**   Author: Andrew Clos
**   Date: 6/30/2019
**   Description: This class header lays out a simple class called Menu. 
**                There is a private function to perform integer input
**                validation as well as three public classes to print menu
**                options to the screen and get the game parameters from
**                the user.              
****************************************************************************/
#include<string>
#ifndef MENU_HPP
#define MENU_HPP

class Menu
{
private:
	int intValidate(char, int, int);
public:
	bool mainMenu();
	void paramMenu(int*);
	void gameParameters(int*);
	bool playAgain();
};
#endif