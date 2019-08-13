/*************************************************************************** 
**   Program Name: Project 2 Zoo Tycoon (Zoo.hpp)
**   Author: Andrew Clos
**   Date: 7/20/2019
**   Description: This class header lays out a class called Zoo.  The bulk of
**				  the program operates here and begins with a public call to
**				  the main menu.  From there, user data is collected and the
**				  events of a day or turn are executed in sequence.
****************************************************************************/

#ifndef ZOO_HPP
#define ZOO_HPP

#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "NewAnimal.hpp"

class Zoo
{
private:
	//member variables
	Tiger** tigArr;
	Penguin** pengArr;
	Turtle** turtArr;
	NewAnimal** userAnArr;
	double cashOnHand;
	int totTigers;
	int totPenguins;
	int totTurtles;
	int totUserAns;
	int numSpecies;
	int tigArraySize;
	int penArraySize;
	int turArraySize;
	int userAnArraySize;
	std::string userAnimalName;
	
	//private helper functions
	void showParams();
	void newAnimals(int *);
	void checkArrays();
	void feed(int);
	void sickness();
	double boomZoo();
	void babyBorn();
	void endDay(double);
	int randomGen(int, int);

public:
	Zoo();
	int mainMenu();
	
	//get methods
	int getTigs();
	int getPengs();
	int getTurts();
	int getUserAn();
	int getNumSpecies();
	std::string getUserAnimalName();
	double getCashOnHand();
	int getTigArraySize();
	int getPengArraySize();
	int getTurtArraySize();
	int getUserAnArraySize();

	//set methods
	void setCashOnHand(double);
	void setTigs(int);
	void setPengs(int);
	void setTurts(int);
	void setUserAn(int);
	void setNumSpecies(int);
	void setUserAnimalName(std::string);
	void setTigArray(int);
	void setPenArray(int);
	void setTurArray(int);
	void setUserAnArray(int);

	//an explicit destructor was important for this program due to the use of double pointer
	//dynamic arrays.
	~Zoo();
};
#endif