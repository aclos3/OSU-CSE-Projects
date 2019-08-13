/***************************************************************************
**   Program Name: Project 3 Fantasy Combat (Character.hpp)
**   Author: Andrew Clos
**   Date: 7/31/2019
**   Description: This is an abstract class for a Character of the fantasy
**				  combat game. Included are six virtual functions that control
**				  elements that are specific to each derived class.  There are
**				  a total of 12 get and set methods to retrieve and alter
**				  data members.
****************************************************************************/

#ifndef CHARACTER_HPP   
#define CHARACTER_HPP

#include<string>
#include<vector>

class Character
{
protected:           

	int armor;
	int strPts;
	int spareLives;
	int numDiceAtk;
	int numDiceSidesAtk;
	int numDiceDef;
	int numDiceSidesDef;
	int playerNum;
	std::vector<double> liveStats;
	std::string className;

public:
	Character();
	virtual void showDescription();
	virtual bool isAlive();
	virtual int attack(Character*);
	virtual void defend(int, Character*);
	virtual int roll(int, int);
	std::string getClass();
	int getArmor();
	int getStr();
	int getSpareLives();
	int getNumDiceAtk();
	int getNumDiceSidesAtk();
	int getNumDiceDef();
	int getNumDiceSidesDef();
	int getPlayerNum();
	std::vector<double> getLiveStats();
	void setStr(int);
	void setPlayerNum(int);
	virtual ~Character();
};
#endif

