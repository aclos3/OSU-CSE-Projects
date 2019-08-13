/***************************************************************************
**   Program Name: Final Project (Opal.hpp)
**   Author: Andrew Clos
**   Date: 8/12/2019
**   Description: Header file for a Opal with default constructor and
**				  overwritten functions 'playerEnters' and 'lookAround' from
**				  the parent class.
****************************************************************************/

#ifndef OPAL_HPP
#define OPAL_HPP

#include"Space.hpp"
#include"InputValidate.hpp"


class Opal : public Space
{

public:
	Opal();
	std::vector<int> playerEnters(int);
	void lookAround();
};

#endif