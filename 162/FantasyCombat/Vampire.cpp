/***************************************************************************
**   Program Name: Project 3 Fantasy Combat (Vampire.cpp)
**   Author: Andrew Clos
**   Date: 7/31/2019
**   Description: A constructor for this derived class sets all initial
**				  private data members per the project specifications.
**				  Additonally, there are private data members for spareLives,
**				  number/sides count of attack and defense dice as well as
**				  a vector for stats tracking and the name of the class. The
**				  major member functions are to check if the character is
**				  alive, attack, defend and roll a dice. The Vampire contains
**				  special defensive ability where they are able to charm their
**				  attacker, negating the attack completely. 
****************************************************************************/

#include<iostream>
#include<random>
#include "Vampire.hpp"

Vampire::Vampire()
{
	this->armor = 1;
	this->strPts = 18;
	this->spareLives = 0;
	this->numDiceAtk = 1;
	this->numDiceSidesAtk = 12;
	this->numDiceDef = 1;
	this->numDiceSidesDef = 6;
	this->liveStats.push_back(0.0);
	this->liveStats.push_back(0.0);
	this->liveStats.push_back(0.0);
	this->liveStats.push_back(0.0);
	this->liveStats.push_back(0.0);
	this->className = "\033[1;35mVampire\033[0m";
}

/***************************************************************************
**   Description: Shows the class description in the console.
****************************************************************************/
void Vampire::showDescription()
{
	std::cout << "Suave, debonair, but vicious and surprisingly resilient." << std::endl;
	std::cout << "Strength: " << strPts << std::endl;
	std::cout << "Armor: " << armor << std::endl;
	std::cout << "Attack Roll: " << numDiceAtk << " dice, each with " << numDiceSidesAtk << " sides." << std::endl;
	std::cout << "Defense Roll: " << numDiceDef << " dice, each with " << numDiceSidesDef << " sides." << std::endl;
	std::cout << "\033[1;97mSpecial Abilitiy: \033[0m" << " Charm! Vampires can charm an opponent into not attacking. For a given attack there is a 50% chance that their opponent's attack is negated." << std::endl;
}

/***************************************************************************
**   Description: Checks to see if the character is alive and if any spare
**			      lives are available. Returns a bool (T = alive, F = dead).
****************************************************************************/
bool Vampire::isAlive()
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
int Vampire::attack(Character *attacker)
{
	int attackPts = 0;

	attackPts = attackPts + roll(getNumDiceAtk(), getNumDiceSidesAtk());

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
void Vampire::defend(int incDmg, Character *defender)
{
	int defPts = 0,
		effectiveDmg = 0;

	//increment number of defends made
	liveStats[2] = liveStats[2] + 1;

	//for vampire: 50% chance to neutralize attack.
	if (roll(1, 2) == 2)
	{
		//total damage mitigated via special roll
		liveStats[3] = liveStats[3] + defPts;
		std::cout << "Player " << defender->getPlayerNum() << "'s " << getClass() << "\033[1;97m Charm\033[0m" << " ability activated, opponent's attack of " << incDmg << " points was completely neutralized!" << std::endl;
	}
	else
	{
		defPts = roll(getNumDiceDef(), getNumDiceSidesDef());
		effectiveDmg = incDmg - defPts - getArmor();

		//make sure the attack cannot go negative.
		if (effectiveDmg < 0)
		{
			effectiveDmg = 0;
		}

		defender->setStr(defender->getStr() - effectiveDmg);

		//total damage mitigated via rolls
		liveStats[3] = liveStats[3] + defPts;
		//armor damage mitigation
		liveStats[4] = liveStats[4] + getArmor();

		std::cout << incDmg << "\033[1;97m attack points\033[0m" << ", mitigated by " << defPts << "\033[1;97m defense points \033[0m" << "and " << getArmor() << "\033[1;97m armor \033[0m" << "for " << effectiveDmg << " effective damage." << std::endl;
	}
}

/***************************************************************************
**   Description: Takes integers for the number of dice and number of dice
**				  sides and then performs a random function to return a value
**			      for the dice roll.
****************************************************************************/
int Vampire::roll(int numDice, int sidesDice)
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
Vampire::~Vampire()
{

}


