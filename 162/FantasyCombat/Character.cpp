/***************************************************************************
**   Program Name: Project 3 Fantasy Combat (Character.cpp)
**   Author: Andrew Clos
**   Date: 7/31/2019
**   Description: This is an abstract class for a Character of the fantasy
**				  combat game. Virtual functions are left largely empty since
**				  these are completely rewritten by each derived class, 
**				  including the constructor. There are additional private 
**				  data members (with get and set methods) including a vector
**				  for combat statistics, one to hold the player number, and
**			      number of lives a given class has.
****************************************************************************/

#include<iostream>
#include "Character.hpp"

//empty default constructor
Character::Character()
{

}

/***************************************************************************
**   Description: Shows the class description.
****************************************************************************/
void Character::showDescription()
{


}

/***************************************************************************
**   Description: Checks to see if the character is alive and if any spare
**			      lives are available. Returns a bool (T = alive, F = dead).
****************************************************************************/
bool Character::isAlive()
{
	return false;
}

/***************************************************************************
**   Description: Performs the attack. Rolls appropriate number of dice and
**				  returns its attack value (after applying any special 
**				  abilities) to be used by the defend function. Recieves a
**				  to the Character of the attacker in order to print the 
**				  attacker's player number and class. Also updates the 
**				  liveStats vector to keep track of combat statistics.
****************************************************************************/
int Character::attack(Character*)
{
	return 0;
}

/***************************************************************************
**   Description: Performs the defense. Recieves the incoming attack as an
**				  integer and calculates the effective damage (after applying
**				  mitigation and special abilities. Updates the strength of 
**				  the defender as well as defense statistics in the liveStats
**				  vector. Recieves a pointer to the character of the defender
**				  in order to display the defender's class and player number.
****************************************************************************/
void Character::defend(int, Character*)
{

}

/***************************************************************************
**   Description: Takes integers for the number of dice and number of dice
**				  sides and then performs a random function to return a value
**			      for the dice roll.
****************************************************************************/
int Character::roll(int, int)
{
	return 0;
}

/***************************************************************************
**   Description: The following 12 functions are get/set methods for various
**				  member variables.
****************************************************************************/
std::string Character::getClass()
{
	return className;
}
int Character::getArmor()
{
	return armor;
}

int Character::getStr()
{
	return strPts;
}

int Character::getSpareLives()
{
	return spareLives;
}

int Character::getNumDiceAtk()
{
	return numDiceAtk;
}

int Character::getNumDiceSidesAtk()
{
	return numDiceSidesAtk;
}

int Character::getNumDiceDef()
{
	return numDiceDef;
}

int Character::getNumDiceSidesDef()
{
	return numDiceSidesDef;
}

int Character::getPlayerNum()
{
	return playerNum;
}

std::vector<double> Character::getLiveStats()
{
	return liveStats;
}

void Character::setStr(int newStr)
{
	strPts = newStr;
}

void Character::setPlayerNum(int num)
{
	playerNum = num;
}

//default destructor.
Character::~Character()
{

}


