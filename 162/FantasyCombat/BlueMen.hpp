/***************************************************************************
**   Program Name: Project 3 Fantasy Combat (BlueMen.hpp)
**   Author: Andrew Clos
**   Date: 7/31/2019
**   Description: This class is a derived class of the abstract class:
**				  Character. The derived class redefines the show description,
**				  getClass, isAlive, attack and defend functions since these
**				  have elements that are specifc to each derived class.
****************************************************************************/
#ifndef BLUEMEN_HPP   
#define BLUEMEN_HPP

#include "Character.hpp"

class BlueMen : public Character
{
private:           
	
public:
	BlueMen();
	void showDescription();
	bool isAlive();
	int attack(Character*);
	void defend(int, Character*);
	int roll(int, int);
	~BlueMen();
};
#endif

