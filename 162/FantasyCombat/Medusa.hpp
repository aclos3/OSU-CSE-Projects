/***************************************************************************
**   Program Name: Project 3 Fantasy Combat (Medusa.hpp)
**   Author: Andrew Clos
**   Date: 7/29/2019
**   Description: This class is a derived class of the abstract class:
**				  Character. The derived class redefines the show description,
**				  getClass, isAlive, attack and defend functions since these
**				  have elements that are specifc to each derived class.
****************************************************************************/

#ifndef MEDUSA_HPP   
#define MEDUSA_HPP

#include "Character.hpp"

class Medusa : public Character
{
private:           
	
public:
	Medusa();
	void showDescription();
	bool isAlive();
	int attack(Character*);
	void defend(int, Character*);
	int roll(int, int);
	~Medusa();
};
#endif

