/***************************************************************************
**   Program Name: Lab 3 (Die.cpp)
**   Author: Andrew Clos
**   Date:  7/11/2019
**   Description: The Die class is a parent class with a default constructor
**				  to set up a six sided Die, get and set methods and a rollDice
**				  function that returns a random integer to the caller that is
**				  between 1 and the number of sides the dice has. 
****************************************************************************/

#include<iostream>
#include<random>
#include "Die.hpp"

Die::Die()
{
	diceSides = 6;
}

Die::Die(int sides)
{
	diceSides = sides;
}
Die::~Die()
{
	
}

/***************************************************************************
**   Description:  Uses random number generation to roll a number between 1 
**			       and the number of sides the dice has. On a six sided Die,
**				   this results in average rolls of 3.5, which makes sense,
**				   because (1 + 6) / 2 = 3.5.
****************************************************************************/
int Die::rollDice()
{
	int dieValue = 0;
	std::random_device randDev;
	std::mt19937 randSeed(randDev());
	std::uniform_int_distribution<> randomDice(1, diceSides);

	dieValue = randomDice(randSeed);

	return dieValue;
}
//get method for getting the number of sides a dice has
int Die::getDiceSides()
{
	return diceSides;
}
//set method to establish the number of sides.
void Die::setSides(int sides)
{
	diceSides =  sides;
}