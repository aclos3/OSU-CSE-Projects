/***************************************************************************
**   Program Name: Project 2 Zoo Tycoon (NewAnimal.hpp)
**   Author: Andrew Clos
**   Date: 7/20/2019
**   Description: Header for a New Animal class. This is a derived class of
**				  the Animal class, but it contains a few additional set
**				  methods since these values will be user defined instead of
**				  specifically adhering to project specifications.
****************************************************************************/
#include "Animal.hpp"

#ifndef NEWANIMAL_HPP
#define NEWANIMAL_HPP

class NewAnimal : public Animal
{
private:
	
public:
	NewAnimal();
	void setCost(double);
	void setNumBabies(int);
	void setFoodCost(double);
	void setPayOff(double);
};
#endif