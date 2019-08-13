/***************************************************************************
**   Program Name: Final Project (Agate.hpp)
**   Author: Andrew Clos
**   Date: 8/12/2019
**   Description: Header file for a Agate with default constructor and
**				  overwritten functions 'playerEnters' and 'lookAround' from
**				  the parent class.
****************************************************************************/

#ifndef AGATE_HPP
#define AGATE_HPP

#include"Space.hpp"
#include"InputValidate.hpp"


class Agate : public Space
{

public:
	Agate();
	std::vector<int> playerEnters(int);
	void lookAround();
};

#endif