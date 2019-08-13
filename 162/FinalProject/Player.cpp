/***************************************************************************
**   Program Name: Final Project (Player.cpp)
**   Author: Andrew Clos
**   Date: 8/12/2019
**   Description: The player class instantiates all spaces via its constructor
**				  and updates player location as well as stores the previous
**				  player location in case it needs to be restored.  It also
**				  keeps track of the player's inventory and will require a
**				  user to modify the inventory if it gets full.
****************************************************************************/

#include<iostream>
#include "Player.hpp"

Player::Player()
{
	prev = nullptr;
	currentSpace = nullptr;
	pName = " ";
	shovels = 200;
	points = 0;
	mapRow = 0;
	mapCol = 0;
	container = { 0, 0, 0, 0, 0, 0, 0, 0};

	saph = new Sapphire();
	aga = new Agate();
	ruby = new Ruby();
	gar = new Garnet();
	diam = new Diamond();
	emer = new Emerald();
	aqua = new Aquamarine();
	opal = new Opal();
}


/***************************************************************************
**   Description: Places the player in the room that they were previously in.
****************************************************************************/
void Player::restorePrev()
{
	if (prev != nullptr)
	{
		currentSpace = prev;
	}
	else
	{
		std::cout << "Prev was NULL! Operation not complete. " << std::endl;
	}
}

/******************************************************************************
**   Description: This function sets up the rooms (Spaces) as a linked data
**				  structure by making each one aware of its immediate neighbors
**				  in a circular type orientation.  Each space always has two
**				  neighbors and two nulls, but these can be top, bottom, left 
**				  or right.
*******************************************************************************/
void Player::setupRooms()
{
	//set up the linked structure (each room aware of its immediate neighbors
	// order is: top, bottom, left, right
	saph->setNeighbors(nullptr, gar, nullptr, aga);
	aga->setNeighbors(nullptr, nullptr, saph, ruby);
	ruby->setNeighbors(nullptr, diam, aga, nullptr);
	gar->setNeighbors(saph, emer, nullptr, nullptr);
	diam->setNeighbors(ruby, opal, nullptr, nullptr);
	emer->setNeighbors(gar, nullptr, nullptr, aqua);
	aqua->setNeighbors(nullptr, nullptr, emer, opal);
	opal->setNeighbors(diam, nullptr, aqua, nullptr);
}

/******************************************************************************
**   Description: After a room visit, this function is called to add the gems
**				  that were collected to the player's inventory.  If the max 
**				  inventory would be exceeded by this action, the removeGems
**				  function is called.
*******************************************************************************/
void Player::addContainer(int discovery)
{
	int totalGems = 0,
		newTotal = 0,
		removeChoice = 0;
	InputValidate gemRemove;

	//calculate total gems in inventory already
	for (unsigned int i = 0; i < spaces->length(); i++)
	{
		totalGems = totalGems + container.at(i);
	}

	//check if there is room for all incoming gems
	if (totalGems + discovery > MAXINVENTORY)
	{
		std::cout << "You return from the " << currentSpace->getName() << " room, but find there is not enough room in your inventory all of these gems." << std::endl;
		std::cout << "You have to discard " << (totalGems + discovery) - MAXINVENTORY << " gems. ";
		std::cout << "Do you wish to discard " << (totalGems + discovery) - MAXINVENTORY << " of the gems you just collected or choose others from your inventory?" << std::endl;
		std::cout << "(1) Discard the recent gems." << std::endl;
		std::cout << "(2) Discard others already in the inventory." << std::endl;
		removeChoice = gemRemove.intValidate('y', 1, 2);

		if (removeChoice == 1)
		{
			discovery = MAXINVENTORY - totalGems;
		}
		else if (removeChoice == 2)
		{
			removeGems((totalGems + discovery) - MAXINVENTORY);
		}
	}

    //add gems to correct slot in inventory based on their type.
	if (currentSpace->getName() == "\033[1;94mSapphire\033[0m")
	{
		container.at(0) = container.at(0) + discovery;
	}
	else if (currentSpace->getName() == "\033[1;93mAgate\033[0m")
	{
		container.at(1) = container.at(1) + discovery;
	}
	else if (currentSpace->getName() == "\033[1;91mRuby\033[0m")
	{
		container.at(2) = container.at(2) + discovery;
	}
	else if (currentSpace->getName() == "\033[3;100;30mGarnet\033[0m")
	{
		container.at(3) = container.at(3) + discovery;
	}
	else if (currentSpace->getName() == "\033[1;97mDiamond\033[0m")
	{
		container.at(4) = container.at(4) + discovery;
	}
	else if (currentSpace->getName() == "\033[1;92mEmerald\033[0m")
	{
		container.at(5) = container.at(5) + discovery;
	}
	else if (currentSpace->getName() == "\033[1;96mAquamarine\033[0m")
	{
		container.at(6) = container.at(6) + discovery;
	}
	else if (currentSpace->getName() == "\033[1;95mOpal\033[0m")
	{
		container.at(7) = container.at(7) + discovery;
	}

	//output updated inventory total
	for (unsigned int i = 0; i < spaces->length(); i++)
	{
		newTotal = newTotal + container.at(i);
	}
	std::cout << "\033[1;97mInventory\033[0m" << ": " << newTotal << " / " << MAXINVENTORY << std::endl;
}

/******************************************************************************
**   Description: Gives the user the option to decide which gem (and how many)
**				  they'd like to remove.  Keeps user in a loop until the correct
**				  number of gems has been removed. 
*******************************************************************************/
void Player::removeGems(int toRemove)
{
	int gemChoice = 0,
		numRemove = 0,
		maxRemove = 0;
	InputValidate chooseGem;

	while (toRemove > 0)
	{  //select which gem to remove.
		std::cout << "Please select a gem type to remove." << std::endl;
		std::cout << "(1) Sapphire(" << container.at(0) << ")" << std::endl;
		std::cout << "(2) Agate(" << container.at(1) << ")" << std::endl;
		std::cout << "(3) Ruby(" << container.at(2) << ")" << std::endl;
		std::cout << "(4) Garnet(" << container.at(3) << ")" << std::endl;
		std::cout << "(5) Diamond(" << container.at(4) << ")" << std::endl;
		std::cout << "(6) Emerald(" << container.at(5) << ")" << std::endl;
		std::cout << "(7) Aquamarine(" << container.at(6) << ")" << std::endl;
		std::cout << "(8) Opal(" << container.at(7) << ")" << std::endl;
		
		gemChoice = chooseGem.intValidate('y', 1, 8);

		if (container.at(gemChoice - 1) < 1)
		{
			std::cout << "You do not have any gems of this type. Please choose again." << std::endl;
		}
		else
		{   //the max they can remove is either equal to the number of gems of that type or
			//the max total that they must remove, whichever is less.
			if (container.at(gemChoice - 1) > toRemove)
			{
				maxRemove = toRemove;
			}
			else
			{
				maxRemove = container.at(gemChoice - 1);
			}

			std::cout << "Enter the number of " << spaces[gemChoice - 1] << "s you'd like to remove(max: " << maxRemove << "): ";
			numRemove = chooseGem.intValidate('y', 1, maxRemove);
			
			//remove from container
			container.at(gemChoice - 1) = container.at(gemChoice - 1) - numRemove;
			toRemove = toRemove - numRemove;
		}
		//display message with new total they must remove, and repeat the loop.
		if (toRemove > 0)
		{
			std::cout << "You now have " << toRemove << " gems to remove." << std::endl;
		}
	}
}

/******************************************************************************
**   Description: Display the points per gem, odds of success and cost per dig
**				  along with some explanation text to the console.
*******************************************************************************/
void Player::showValues()
{
	std::cout << "The gems here are worth: $" << currentSpace->getPtsPerGem() << " each and take " << currentSpace->getShovCost() << " shovels per attempt. ";
	std::cout << "There is a " << currentSpace->getOdds() << "% chance of a successful dig." << std::endl;
}

/******************************************************************************
**   Description: Display the quantity of each gem that the user has collected.
*******************************************************************************/
void Player::showGems()
{
	for (unsigned int i = 0; i < container.size(); i++)
	{
		if (i == 0)
		{
			std::cout << "\033[1;94mSapphires\033[0m";
		}
		else if (i == 1)
		{
			std::cout << "\033[1;93mAgates\033[0m";
		}
		else if (i == 2)
		{
			std::cout << "\033[1;91mRubies\033[0m";
		}
		else if (i == 3)
		{
			std::cout << "\033[3;100;30mGarnets\033[0m";
		}
		else if (i == 4)
		{
			std::cout << "\033[1;97mDiamonds\033[0m";
		}
		else if (i == 5)
		{
			std::cout << "\033[1;92mEmeralds\033[0m";
		}
		else if (i == 6)
		{
			std::cout << "\033[1;96mAquamarines\033[0m";
		}
		else if (i == 7)
		{
			std::cout << "\033[1;95mOpals\033[0m";
		}

		std::cout << ": " << container.at(i);
		if (i == container.size() - 1)
		{
			std::cout << "." << std::endl;
		}
		else
		{
			std::cout << ", ";
		}
	}
}

/*****************************************************************************
**   Description: Display final message and point total to the console.
******************************************************************************/
void Player::showPoints()
{
	std::cout << "Game Over!" << std::endl << "Final Score: " << std::endl;
	showGems();
	std::cout << "\033[1;97mPoints: \033[0m" << points << std::endl;
}

/*****************************************************************************
**   Description: The following 7 functions are 'Get' methods.
******************************************************************************/
std::string Player::getPname()
{
	return pName;
}

int Player::getShovels()
{
	return shovels;
}

int Player::getRow()
{
	return mapRow;
}

int Player::getCol()
{
	return mapCol;
}

int Player::getPoints()
{
	return points;
}

int Player::getContainerSpace()
{
	return MAXINVENTORY;
}

Space* Player::getCurrentSpace()
{
	return currentSpace;
}

/*****************************************************************************
**   Description: The following 7 functions are 'Set' methods.
******************************************************************************/
void Player::setName(std::string ourName)
{
	pName = ourName;
}

void Player::setShovels(int shovs)
{
	shovels = shovs;
}

void Player::setPoints(int pts)
{
	points = pts;
}

void Player::setCurrentSpace(int space)
{
	// set previous space
	prev = currentSpace;
	if (space == 1)
	{
		currentSpace = saph;
	}
	else if (space == 2)
	{
		currentSpace = aga;
	}
	else if (space == 3)
	{
		currentSpace = ruby;
	}
	else if (space == 4)
	{
		currentSpace = gar;
	}
	else if (space == 5)
	{
		currentSpace = diam;
	}
	else if (space == 6)
	{
		currentSpace = emer;
	}
	else if (space == 7)
	{
		currentSpace = aqua;
	}
	else if (space == 8)
	{
		currentSpace = opal;
	}
}

void Player::setPosition(int playerRow, int playerCol)
{
	mapRow = playerRow;
	mapCol = playerCol;
}

void Player::setRow(int row)
{
	mapRow = row;
}

void Player::setCol(int col)
{
	mapCol = col;
}

/***************************************************************************
**   Description: Destructor to remove each of the dynamically allocated
**				  spaces after a game has ended and the "Player" object is 
**				  destroyed.
****************************************************************************/
Player::~Player()
{
	delete saph;
	delete aga;
	delete ruby;
	delete gar;
	delete diam;
	delete emer;
	delete aqua;
	delete opal;
}

