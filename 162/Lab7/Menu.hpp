/*************************************************************************** 
**   Program Name: Lab 7 (Menu.hpp)
**   Author: Andrew Clos
**   Date: 8/4/2019
**   Description: Class header for the Menu.  A public function is called 
**			      to get the program started and returns a value of true or
**				  false to the caller based on whether the user wants to keep
**				  playing. Also contained here are the constants used by the
**				  program
****************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP


const int MINMENU = 1;
const int MAXMENU = 3;
const int MINROUNDS = 1;
const int MAXROUNDS = 500;
const int MINPERCENT = 1;
const int MAXPERCENT = 100;
const int MAXSTRLEN = 500;
const int APPENDNUM = 1000;
const int PERRAND = 100;
const char YESLIMITS = 'y';

class Menu
{
private:
	void runQueue(int, int, int);
	void palindrome(std::string);
	int getRandom(int, int);
	
public:
	bool mainMenu();
	
};
#endif