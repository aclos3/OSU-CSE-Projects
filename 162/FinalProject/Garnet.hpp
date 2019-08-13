/***************************************************************************
**   Program Name: Final Project (Garnet.hpp)
**   Author: Andrew Clos
**   Date: 8/12/2019
**   Description: Header file for a Garnet with default constructor and
**				  overwritten functions 'playerEnters' and 'lookAround' from
**				  the parent class.
****************************************************************************/

#ifndef GARNET_HPP
#define GARNET_HPP

#include"Space.hpp"
#include"InputValidate.hpp"


class Garnet : public Space
{

public:
	Garnet();
	std::vector<int> playerEnters(int);
	void lookAround();
};

#endif