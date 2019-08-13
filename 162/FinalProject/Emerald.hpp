/***************************************************************************
**   Program Name: Final Project (Emerald.hpp)
**   Author: Andrew Clos
**   Date: 8/12/2019
**   Description: Header file for a Emerald with default constructor and
**				  overwritten functions 'playerEnters' and 'lookAround' from
**				  the parent class.
****************************************************************************/

#ifndef EMERALD_HPP
#define EMERALD_HPP

#include"Space.hpp"
#include"InputValidate.hpp"


class Emerald : public Space
{

public:
	Emerald();
	std::vector<int> playerEnters(int);
	void lookAround();
};

#endif