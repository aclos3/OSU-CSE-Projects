/***************************************************************************
**   Program Name: Lab 4 OSU Information System (Building.cpp)
**   Author: Andrew Clos
**   Date: 7/19/2019
**   Description: The Building classs contains default and regular constructors
**				  since I decided to instantiate objects in run time and this
**				  made it much simpler (as opposed to using a factory object).
****************************************************************************/

#include<string>
#include "Building.hpp"

Building::Building()
{
	name = "Name";
	size = 999;
	address = "Add";
}
/***************************************************************************
**   Description: Constructor taking const arguments since practicing with
**				  copy constructors.
****************************************************************************/
Building::Building(const std::string title, const int sqFt, const std::string add)
{
	name = title;
	size = sqFt;
	address = add;
}
/***************************************************************************
**   Description: The following seven functions are 'getters' and 'setters' to
**                return or set info about member variables.
****************************************************************************/
std::string Building::getName()
{
	return name;
}
int Building::getSize()
{
	return size;
}
std::string Building::getAddress()
{
	return address;
}
void Building::setTitle(std::string title)
{
	name = title;
}
void Building::setSize(int sqFt)
{
	size = sqFt;
}
void Building::setAddress(std::string add)
{
	address = add;
}

char Building::getType()
{
	return 'b';
}
