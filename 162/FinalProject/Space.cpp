/***************************************************************************
**   Program Name: Final Project (Space.cpp)
**   Author: Andrew Clos
**   Date: 8/12/2019
**   Description: This is the parent class for a Space.  It contains two pure
**				  virtual functions that are used by each space to create a
**				  unique experience for the user. It also establishes many
**				  private variables for the parameters of each unique Space.
**				  There are also get and set methods for each of these member
**				  variables that are intended to be common among each class
**				  including those of the linked data structure.
****************************************************************************/

#include "Space.hpp"


Space::Space()
{
	this->top = nullptr;
	this->bottom = nullptr;
	this->left = nullptr;
	this->right = nullptr;
	this->roomName = "Space";
	this->beenVisited = false;
	this->encountered = false;
	this->numDigSites = 0;
	this->minGems = 0;
	this->maxGems = 0;
	this->numDigSites = 0;
	this->odds = 100;
	this->ptsPerGem = 0;
	this->costPerDig = 0;
}

/***************************************************************************
**   Description: A unique description of the room and instructions to the
**				  user will occur when the player enters the room.
****************************************************************************/
std::vector<int> Space::playerEnters(int shovels)
{
	std::vector<int> ptsShov;
	ptsShov.push_back(999);
	ptsShov.push_back(999);

	return ptsShov;
}

/***************************************************************************
**   Description: Pure virtual function that each derived class over writes
**				  to make unique experience for the user.
****************************************************************************/
void Space::lookAround()
{

}

/***************************************************************************
**   Description: 11 get methods for member variables. The Space get functions
**				  check to make sure they are not checking something that is
**				  equal to null before attempting to return it.
****************************************************************************/
Space* Space::getTop()
{
	if (this->top != nullptr)
	{
		return this->top;
	}
	else
	{
		return nullptr;
	}
}

Space* Space::getBottom()
{
	if (this->bottom != nullptr)
	{
		return this->bottom;
	}
	else
	{
		return nullptr;
	}
}

Space* Space::getLeft()
{
	if (this->left != nullptr)
	{
		return this->left;
	}
	else
	{
		return nullptr;
	}
}

Space* Space::getRight()
{
	if (this->right != nullptr)
	{
		return this->right;
	}
	else
	{
		return nullptr;
	}
}

//returns a random integer between two values provided by the caller.
int Space::getRandom(int low, int high)
{
	std::random_device randDev;
	std::mt19937 randSeed(randDev());
	std::uniform_int_distribution<> randomNum(low, high);

	return randomNum(randSeed);
}

int Space::getPtsPerGem()
{
	return ptsPerGem;
}

int Space::getShovCost()
{
	return costPerDig;
}

int Space::getOdds()
{
	return odds;
}

int Space::getNumDigSites()
{
	return numDigSites;
}

std::string Space::getName()
{
	return roomName;
}

bool Space::getVisted()
{
	return beenVisited;
}

/***************************************************************************
**   Description: 2 set methods for member variables.
****************************************************************************/
void Space::setNeighbors(Space* newTop, Space* newBottom, Space* newLeft, Space* newRight)
{
	top = newTop;
	bottom = newBottom;
	left = newLeft;
	right = newRight;
}

void Space::setBeenVisited(bool visited)
{
	beenVisited = visited;
}

//virtual destructor
Space::~Space()
{

}

