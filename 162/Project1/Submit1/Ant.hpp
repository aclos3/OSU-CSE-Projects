/***************************************************************************
**   Program Name: Project 1 (Ant.hpp)
**   Author: Andrew Clos
**   Date:
**   Description:  This is the class header for the Ant.  The ant has 6 
**                 private data members to hold the simulation parameters as
**                 well as two private helper functions used during a "step."
**                 In addition to set methods for simulation parameters, there 
**                 are three public functions that are called to make a board, 
**                 print the board and have the Ant take a step. 
****************************************************************************/

#ifndef ANT_HPP   
#define ANT_HPP

class Ant
{
private:           
	int rows,
		cols,
		steps,
		antRow,
		antCol,
		antDir;
	void turnTheAnt(char**);
	void toggleColor(char**);
		
public:
	Ant();      
	Ant(int*);
	void makeBoard(char**);
	void printBoard(char**);
	void takeStep(char**);
	void setRows(int);
	void setCols(int);
	void setSteps(int);
	void setAntRow(int);
	void setAntCol(int);
	void setDir(int);
};

#endif

