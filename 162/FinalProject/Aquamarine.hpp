/***************************************************************************
**   Program Name: Final Project (Aquamarine.hpp)
**   Author: Andrew Clos
**   Date: 8/12/2019
**   Description: Header file for a Aquamarine with default constructor and
**				  overwritten functions 'playerEnters' and 'lookAround' from
**				  the parent class.
****************************************************************************/

#ifndef AQUAMARINE_HPP
#define AQUAMARINE_HPP

#include"Space.hpp"
#include"InputValidate.hpp"


class Aquamarine : public Space
{

public:
	Aquamarine();
	std::vector<int> playerEnters(int);
	void lookAround();
};

#endif