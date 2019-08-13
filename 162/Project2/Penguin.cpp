/***************************************************************************
**   Program Name: Project 2 (Penguin.cpp)
**   Author: Andrew Clos
**   Date: 7/20/2019
**   Description:  The Penguin class contains private member variables for
**				   baseline parameters of a Penguin Object. It is a derived
**				   Class and inherits from the Animal class.
****************************************************************************/

#include "Penguin.hpp"

Penguin::Penguin()
{
	age = 0;
	cost = 1000;
	numberOfBabies = 5;
	baseFoodCost = 20;
	payoff = 0.1;
}
