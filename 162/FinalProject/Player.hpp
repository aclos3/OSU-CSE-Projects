/***************************************************************************
**   Program Name: Final Project (Player.hpp)
**   Author: Andrew Clos
**   Date: 8/12/2019
**   Description: Header file for a Player class. This class keeps track of
**				  the Spaces the player is in and has been in, so it contains
**				  many private data members and functions related to this.
****************************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include<string>
#include<vector>
#include"Space.hpp"
#include"Sapphire.hpp"
#include"Agate.hpp"
#include"Ruby.hpp"
#include"Garnet.hpp"
#include"Diamond.hpp"
#include"Emerald.hpp"
#include"Aquamarine.hpp"
#include"Opal.hpp"

const int MAXINVENTORY = 450;
const std::string spaces[8] =  { "Sapphire", "Agate", "Ruby", "Garnet", "Diamond", "Emerald", "Aquamarine", "Opal" };

class Player
{
private:	
	Space* prev;
	Space* currentSpace;
	Sapphire* saph;
	Agate* aga;
	Ruby* ruby;
	Garnet* gar;
	Diamond* diam;
	Emerald* emer;
	Aquamarine* aqua;
	Opal* opal;

	std::string pName;
	std::vector<int> container;
	int inventory;
	int shovels;
	int points;
	int mapRow;
	int mapCol;


public:

	Player();
	Space* getCurrentSpace();
	void restorePrev();
	void addContainer(int);
	void removeGems(int);

	//"show" functions to display information to the console.
	void showValues();
	void showGems();
	void showPoints();
	
	//get methods
	std::string getPname();
	int getShovels();
	int getRow();
	int getCol();
	int getPoints();
	int getContainerSpace();
	
	//set methods
	void setupRooms();
	void setName(std::string);
	void setShovels(int);
	void setPoints(int);
	void setCurrentSpace(int);
	void setPosition(int, int);
	void setRow(int);
	void setCol(int);

	~Player();
};

#endif