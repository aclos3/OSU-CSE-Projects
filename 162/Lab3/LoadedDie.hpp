/*************************************************************************** 
**   Program Name: Lab 3 (LoadedDie.hpp)
**   Author: Andrew Clos
**   Date: 7/11/2019
**   Description: This class header lays out a simple class called LoadedDie. 
**                It is a derived (child) class of the parent class "Die." 
**                The primary difference is its "rollDice" function that 
**				  tends to roll higher numbers than that of a normal Die.
****************************************************************************/
#include "Die.hpp"

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

class LoadedDie : public Die
{
private: 
	int diceSides;
public:
	LoadedDie();
	LoadedDie(int diceSides);
	int rollDice();
};
#endif