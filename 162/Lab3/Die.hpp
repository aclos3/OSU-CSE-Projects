/***************************************************************************
**   Program Name: Die.hpp
**   Author: Andrew Clos
**   Date:  7/11/2019
**   Description: This class header lays out a simple class called "Die." It 
**				  is a parent class to the LoadedDie class, and so it has a
**				  virtual destructor and virtual rollDice function. There are
**				  the usual set/get methods, and default constructors.
****************************************************************************/

#ifndef DIE_HPP   
#define DIE_HPP

class Die
{
private:           
	int diceSides;
public:
	Die();      
	Die(int);
	virtual ~Die();
	int getDiceSides();
	void setSides(int);
	virtual int rollDice();
};
#endif

