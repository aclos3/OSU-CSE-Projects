/***************************************************************************
**   Program Name: Project 2 Zoo Tycoon (Animal.cpp)
**   Author: Andrew Clos
**   Date: 7/20/2019
**   Description: The animal class contains several get and set methods as 
**				  well as an empty default constructor (base class).
****************************************************************************/

#include "Animal.hpp"

Animal::Animal()
{

}

/***************************************************************************
**   Description: The following six functions are get and set methods for the
**				  Animal classes member variables.
****************************************************************************/
int Animal::getAge()
{
	return age;
}
double Animal::getCost()
{
	return cost;
}
int Animal::getNumBabies()
{
	return numberOfBabies;
}
double Animal::getFoodCost()
{
	return baseFoodCost;
}
double Animal::getPayoff()
{
	return payoff;
}
void Animal::setAge(int newAge)
{
	age = newAge;
}