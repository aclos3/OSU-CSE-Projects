/***************************************************************************
**   Program Name: Project 3 Fantasy Combat (BlueMen.cpp)
**   Author: Andrew Clos
**   Date: 7/31/2019
**   Description: A constructor for this derived class sets all initial
**				  private data members per the project specifications.
**				  Additonally, there are private data members for spareLives,
**				  number/sides count of attack and defense dice as well as
**				  a vector for stats tracking and the name of the class. The
**				  major member functions are to check if the character is
**				  alive, attack, defend and roll a dice. The BlueMen have a 
**				  special ability during the defense phase, where they will
**				  lose a defending dice for each four strength they lose.
****************************************************************************/

#include<iostream>
#include<random>
#include "BlueMen.hpp"

BlueMen::BlueMen()
{
	this->armor = 3;
	this->strPts = 12;
	this->spareLives = 0;
	this->numDiceAtk = 2;
	this->numDiceSidesAtk = 10;
	this->numDiceDef = 3;
	this->numDiceSidesDef = 6;
	this->liveStats.push_back(0.0);
	this->liveStats.push_back(0.0);
	this->liveStats.push_back(0.0);
	this->liveStats.push_back(0.0);
	this->liveStats.push_back(0.0);
	this->className = "\033[1;96mBlueMen\033[0m";
}

/***************************************************************************
**   Description: Shows the class description in the console.
****************************************************************************/
void BlueMen::showDescription()
{
	std::cout << "They are small, 6 inches tall, but fast and tough.  They are hard to hit so they can take some damage. They can also do a LOT of damage when they crawl inside enemies' armor or clothing." << std::endl;
	std::cout << "Strength: " << strPts << std::endl;
	std::cout << "Armor: " << armor << std::endl;
	std::cout << "Attack Roll: " << numDiceAtk << " dice, each with " << numDiceSidesAtk << " sides." << std::endl;
	std::cout << "Defense Roll: " << numDiceDef << " dice, each with " << numDiceSidesDef << " sides." << std::endl;
	std::cout << "\033[1;97mSpecial Abilitiy: \033[0m" << " Mob! Blue Men are actually a swarm of small individuals and they defend much better when they're stronger! For every 4 points of damage, they lose one defense die." << std::endl;
}

/***************************************************************************
**   Description: Checks to see if the character is alive and if any spare
**			      lives are available. Returns a bool (T = alive, F = dead).
****************************************************************************/
bool BlueMen::isAlive()
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
int BlueMen::attack(Character *attacker)
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
void BlueMen::defend(int incDmg, Character *defender)
{
	int defPts = 0,
		effectiveDmg = 0,
		updateDiceNum = 0;

	if (defender->getStr() >= 9)
	{
		updateDiceNum = BlueMen().getStr() / 4;
		
	}
	else if (defender->getStr() >= 5 && defender->getStr() < 9)
	{
		updateDiceNum = (BlueMen().getStr() / 4) - 1;
	}
	else if (defender->getStr() >= 1 && defender->getStr() < 5)
	{
		updateDiceNum = (BlueMen().getStr() / 4) - 2;
	}
	std::cout << "Player " << defender->getPlayerNum() << "'s " << defender->getClass() << " Mob are defending with " << updateDiceNum << " dice." << std::endl;

	defPts = roll(updateDiceNum, getNumDiceSidesDef());
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
int BlueMen::roll(int numDice, int sidesDice)
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
BlueMen::~BlueMen()
{

}


