/*************************************************************************** 
**   Program Name: Lab 3 (Game.hpp)
**   Author: Andrew Clos
**   Date: 7/11/2019
**   Description: This class header lays out a class called Game. The Wargame
**			      runs almost entirely within this class. It contains member
**				  variables for each player for dice sides, score, rounds and
**				  loaded status.  There are public set methods for these members
**				  It also declares pointers to Die objects. Additionally, there
**				  is a public mainMenu function where the game "lives" and this
**				  function calls private helper functions: printDice, paramMenu,
**				  showParams, beginGame, and endGame.
****************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Die.hpp"
#include "LoadedDie.hpp"

class Game
{
private:
	
	Die* dieP1;
	Die* dieP2;
	bool p1Loaded;
	bool p2Loaded;
	int rounds;
	int p1Sides;
	int p2Sides;
	int p1Score;
	int p2Score;
	void printDice();
	void paramMenu();
	void showParams();
	void beginGame();
	void endGame(int, int);

public:
	Game();
	void mainMenu();
	void setRounds(int);
	void setP1Sides(int);
	void setP2Sides(int);
	void setP1Score(int);
	void setP2Score(int);
	void setP1Loaded(bool);
	void setP2Loaded(bool);
	~Game();
};
#endif