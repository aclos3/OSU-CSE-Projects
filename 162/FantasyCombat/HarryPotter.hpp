/***************************************************************************
**   Program Name: Project 3 Fantasy Combat (HarryPotter.hpp)
**   Author: Andrew Clos
**   Date: 7/29/2019
**   Description: This class is a derived class of the abstract class:
**				  Character. The derived class redefines the show description,
**				  getClass, isAlive, attack and defend functions since these
**				  have elements that are specifc to each derived class.
****************************************************************************/

#ifndef HARRYPOTTER_HPP   
#define HARRYPOTTER_HPP

#include "Character.hpp"

const int NEWLIFE = 20;

class HarryPotter : public Character
{
private:           
	
public:
	HarryPotter();
	void showDescription();
	bool isAlive();
	int attack(Character*);
	void defend(int, Character*);
	int roll(int, int);
	~HarryPotter();
};
#endif

