/***************************************************************************
**   Program Name: Lab 3 (LoadedDie.cpp)
**   Author: Andrew Clos
**   Date: 7/11/2019
**   Description:  The LoadedDie class represents an object of a dice, with a
**				   modification made to its rollDice function that returns 
**				   higher average results than that of a normal Die.  LoadedDie
**				   includes a default constructor that sets the number of sides
**				   to six.
****************************************************************************/

#include<iostream>
#include<random>
#include "LoadedDie.hpp"

LoadedDie::LoadedDie()
{
	diceSides = 6;
}
LoadedDie::LoadedDie(int sides) : Die(sides)
{
	diceSides = sides;
}
/***************************************************************************
**   Description:  rollDice function. Starts by rolling a random number 
**				   between 1 and the number of sides the dice has, just like
**				   the parent class "Die," however, there are two additional
**				   if-statements that let it roll again if the previous roll
**				   resulted in something half or less than the max value. For
**				   example, if a dice is six sided and the loaded dice rolls a
**				   2, it will reroll.  This allows the loaded dice to roll up
**				   to three times per turn and results in about 40% higher
**			       values than a roll from the normal Die class.					
****************************************************************************/
int LoadedDie::rollDice() 
{
	int dieValue = 0,
		sides = getDiceSides();
	//random int distribtion implementation
	std::random_device randDev;
	std::mt19937 randSeed(randDev());
	std::uniform_int_distribution<> randomDice(1, sides);

	dieValue = randomDice(randSeed);
	//simulate a dice being more heavily weighted to higher numbers
	//by letting it roll again if its first roll or two are below half of its
	//max possible roll.
	if (dieValue <= (sides / 2))
	{
		dieValue = randomDice(randSeed);
	}
	if (dieValue <= (sides / 2))
	{
		dieValue = randomDice(randSeed);
	}
	return dieValue;
}
