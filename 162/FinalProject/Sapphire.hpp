/***************************************************************************
**   Program Name: Final Project (Sapphire.hpp)
**   Author: Andrew Clos
**   Date: 8/12/2019
**   Description: Header file for a Sapphire with default constructor and
**				  overwritten functions 'playerEnters' and 'lookAround' from
**				  the parent class.
****************************************************************************/

#ifndef SAPPHIRE_HPP
#define SAPPHIRE_HPP

#include"Space.hpp"
#include"InputValidate.hpp"


class Sapphire : public Space
{

public:
	Sapphire();
	std::vector<int> playerEnters(int);
	void lookAround();
};

#endif