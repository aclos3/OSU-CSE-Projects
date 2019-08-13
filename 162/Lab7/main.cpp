/***************************************************************************
**   Program Name: Lab 7 (main.cpp)
**   Author: Andrew Clos
**   Date: 8/4/2019
**   Description: The main method simply starts the Menu class which handles
**				  operating the simulation.
****************************************************************************/

#include<iostream>
#include "Menu.hpp"

int main()
{  
	bool playing = true;
	Menu start;

	while (playing)
	{
		playing = start.mainMenu();
	}
	
	return 0;
}


