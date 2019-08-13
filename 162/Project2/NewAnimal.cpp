/***************************************************************************
**   Program Name: Project 2 (NewAnimal.cpp)
**   Author: Andrew Clos
**   Date: 7/18/2019
**   Description: This is a Class of New Animal that the user can optionally 
**				  elect to create.  It inherits from the Animal class. 
**				  Compared to its other sibling classes, it has additional
**				  set methods since these parameters will be user defined.
****************************************************************************/

#include "NewAnimal.hpp"

//default constructor sets values to baseline amounts
NewAnimal::NewAnimal()
{
	age = 0;
	cost = 999;
	numberOfBabies = 1;
	baseFoodCost = 10;
	payoff = 0.1;
}
/***************************************************************************
**   Description: These four functions are set methods for the New Animal
**				  classes user defined parameters.
****************************************************************************/
void NewAnimal::setCost(double userCost)
{
	cost = userCost;
}

void NewAnimal::setNumBabies(int userBabies)
{
	numberOfBabies = userBabies;
}

void NewAnimal::setFoodCost(double userFoodCost)
{
	baseFoodCost = userFoodCost;
}

void NewAnimal::setPayOff(double userPayoff)
{
	payoff = userPayoff;
}