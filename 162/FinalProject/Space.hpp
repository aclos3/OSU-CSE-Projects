/***************************************************************************
**   Program Name: Final Project (Space.hpp)
**   Author: Andrew Clos
**   Date: 8/12/2019
**   Description: Class header for the parent class "Space." Protected data
**			      members are overwritten by the derived classes.
****************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include<string>
#include<random>
#include<chrono>
#include<thread>



class Space
{
protected:
	Space* top;
	Space* bottom;
	Space* left;
	Space* right;
	std::string roomName;
	int minGems;
	int maxGems;
	int costPerDig;
	int odds;
	int ptsPerGem;
	int numDigSites;
	bool beenVisited;
	bool encountered;


public:
	Space();
	//pure virtual functions
	virtual std::vector<int> playerEnters(int);
	virtual void lookAround();
	
	//get and set methods
	Space* getTop();
	Space* getBottom();
	Space* getLeft();
	Space* getRight();
	int getRandom(int, int);
	int getPtsPerGem();
	int getShovCost();
	int getOdds();
	int getNumDigSites();
	std::string getName();
	bool getVisted();
	void setBeenVisited(bool);
	void setNeighbors(Space*, Space*, Space*, Space*);

	virtual ~Space();
};

#endif