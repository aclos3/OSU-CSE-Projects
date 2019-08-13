/***************************************************************************
**   Program Name: Final Project (Ruby.hpp)
**   Author: Andrew Clos
**   Date: 8/12/2019
**   Description: Header file for a Ruby with default constructor and
**				  overwritten functions 'playerEnters' and 'lookAround' from
**				  the parent class.
****************************************************************************/

#ifndef RUBY_HPP
#define RUBY_HPP

#include"Space.hpp"
#include"InputValidate.hpp"


class Ruby : public Space
{

public:
	Ruby();
	std::vector<int> playerEnters(int);
	void lookAround();
};

#endif