/***************************************************************************
**   Program Name: Project 2 Zoo Tycoon (Animal.hpp)
**   Author: Andrew Clos
**   Date: 7/20/2019
**   Description: This class header lays out a class called animal.  It 
**				  is the parent class to several classes of animals, so it 
**			      contains protected member variables as well as get and set
**				  methods.
****************************************************************************/

#ifndef ANIMAL_HPP   
#define ANIMAL_HPP

class Animal
{
protected:           
	int age;
	double cost;
	int	numberOfBabies;
	double baseFoodCost;
	double payoff;
public:
	Animal();
	int getAge();
	double getCost();
	int	getNumBabies();
	double getFoodCost();
	double getPayoff();
	void setAge(int);
};
#endif

