/***************************************************************************
**   Program Name: Project 3 Fantasy Combat (Medusa.cpp)
**   Author: Andrew Clos
**   Date: 7/31/2019
**   Description: A constructor for this derived class sets all initial 
**				  private data members per the project specifications. 
**				  Additonally, there are private data members for spareLives,
**				  number/sides count of attack and defense dice as well as 
**				  a vector for stats tracking and the name of the class. The
**				  major member functions are to check if the character is 
**				  alive, attack, defend and roll a dice. The Medusa includes
**				  a special ability during the attack sequence where if a 12
**				  is rolled, the defender instantly dies.
****************************************************************************/

#include<iostream>
#include<random>
#include "Medusa.hpp"

Medusa::Medusa()
{
	this->armor = 3;
	this->strPts = 8;
	this->spareLives = 0;
	this->numDiceAtk = 2;
	this->numDiceSidesAtk = 6;
	this->numDiceDef = 1;
	this->numDiceSidesDef = 6;
	this->liveStats.push_back(0.0);
	this->liveStats.push_back(0.0);
	this->liveStats.push_back(0.0);
	this->liveStats.push_back(0.0);
	this->liveStats.push_back(0.0);
	this->className = "\033[1;32mMedusa\033[0m";
}

/***************************************************************************
**   Description: Shows the class description in the console.
****************************************************************************/
void Medusa::showDescription()
{
	std::cout << "Scrawny lady with snakes for hair which help her during combat. Just don't look at her!" << std::endl;
	std::cout << "Strength: " << strPts << std::endl;
	std::cout << "Armor: " << armor << std::endl;
	std::cout << "Attack Roll: " << numDiceAtk << " dice, each with " << numDiceSidesAtk << " sides." << std::endl;
	std::cout << "Defense Roll: " << numDiceDef << " dice, each with " << numDiceSidesDef << " sides." << std::endl;
	std::cout << "\033[1;97mSpecial Abilitiy: \033[0m" << " Glare! If a Medusa rolls a 12 when attacking then the target instantly gets turned into stone and Medusa wins! If Medusa uses Glare on Harry Potter on his first life, then Harry Potter comes back to life." << std::endl;
}

/***************************************************************************
**   Description: Checks to see if the character is alive and if any spare
**			      lives are available. Returns a bool (T = alive, F = dead).
****************************************************************************/
bool Medusa::isAlive()
{
	if (getStr() <= 0)
	{
		if (getSpareLives() <= 0)
		{
			return false;
		}
		else
		{
			spareLives--;
			return true;
		}
	}
	else
	{
		return true;
	}
}

/***************************************************************************
**   Description: Performs the attack. Rolls appropriate number of dice and
**				  returns its attack value (after applying any special
**				  abilities) to be used by the defend function. Recieves a
**				  to the Character of the attacker in order to print the
**				  attacker's player number and class. Also updates the
**				  liveStats vector to keep track of combat statistics.
****************************************************************************/
int Medusa::attack(Character * attacker)
{
	int attackPts = 0;

	attackPts = roll(getNumDiceAtk(), getNumDiceSidesAtk());

	if (attackPts == 12)
	{
		std::cout << "Player " << attacker->getPlayerNum() << "'s " << attacker->getClass() << " casts Glare, look out!" << std::endl;
		attackPts = 9999;
	}

	//number of attacks made
	liveStats[0] = liveStats[0] + 1;
	//amount of damage done
	liveStats[1] = liveStats[1] + attackPts;
	return attackPts;
}

/***************************************************************************
**   Description: Performs the defense. Recieves the incoming attack as an
**				  integer and calculates the effective damage (after applying
**				  mitigation and special abilities. Updates the strength of
**				  the defender as well as defense statistics in the liveStats
**				  vector. Recieves a pointer to the character of the defender
**				  in order to display the defender's class and player number.
****************************************************************************/
void Medusa::defend(int incDmg, Character *defender)
{
	int defPts = 0,
		effectiveDmg = 0;

	defPts = roll(getNumDiceDef(), getNumDiceSidesDef());
	effectiveDmg = incDmg - defPts - getArmor();
	
	//make sure the attack cannot go negative.
	if (effectiveDmg < 0)
	{
		effectiveDmg = 0;
	}

	defender->setStr(defender->getStr() - effectiveDmg);

	//number of defends made
	liveStats[2] = liveStats[2] + 1;
	//total damage mitigated via rolls
	liveStats[3] = liveStats[3] + defPts;
	//armor damage mitigation
	liveStats[4] = liveStats[4] + getArmor();

	std::cout << incDmg << "\033[1;97m attack points\033[0m" << ", mitigated by " << defPts << "\033[1;97m defense points \033[0m" << "and " <<  getArmor() << "\033[1;97m armor \033[0m" << "for " << effectiveDmg << " effective damage." << std::endl;

	
}

/***************************************************************************
**   Description: Takes integers for the number of dice and number of dice
**				  sides and then performs a random function to return a value
**			      for the dice roll.
****************************************************************************/
int Medusa::roll(int numDice, int sidesDice)
{
	std::random_device randDev;
	std::mt19937 randSeed(randDev());
	std::uniform_int_distribution<> randomDice(1, sidesDice);
	int roll = 0;

	for (int i = 1; i <= numDice; i++)
	{
		roll = roll + randomDice(randSeed);
	}

	return roll;
}

//default destructor
Medusa::~Medusa()
{

}


