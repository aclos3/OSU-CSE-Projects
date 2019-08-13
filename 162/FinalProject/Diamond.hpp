/***************************************************************************
**   Program Name: Final Project (Diamond.hpp)
**   Author: Andrew Clos
**   Date: 8/12/2019
**   Description: Header file for a Diamond with default constructor and
**				  overwritten functions 'playerEnters' and 'lookAround' from
**				  the parent class.
****************************************************************************/

#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include"Space.hpp"
#include"InputValidate.hpp"


class Diamond : public Space
{

public:
	Diamond();
	std::vector<int> playerEnters(int);
	void lookAround();
};

#endif