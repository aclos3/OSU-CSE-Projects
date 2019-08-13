/***************************************************************************
**   Program Name: Project 3 Fantasy Combat (Vampire.hpp)
**   Author: Andrew Clos
**   Date: 7/29/2019
**   Description: This class is a derived class of the abstract class:
**				  Character. The derived class redefines the show description,
**				  getClass, isAlive, attack and defend functions since these
**				  have elements that are specifc to each derived class.
****************************************************************************/

#ifndef VAMPIRE_HPP   
#define VAMPIRE_HPP

#include "Character.hpp"

class Vampire : public Character
{
private:           
	
public:
	Vampire();
	void showDescription();
	bool isAlive();
	int attack(Character*);
	void defend(int, Character*);
	int roll(int, int);
	~Vampire();
};
#endif

