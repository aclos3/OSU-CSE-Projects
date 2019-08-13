/***************************************************************************
**   Program Name: Lab 4 OSU Information System (Building.hpp)
**   Author: Andrew Clos
**   Date:  7/19/2019
**   Description: This class header lays out a class for the Building object.
**				  In addition to the private member variables required by specs,
**				  there are public methods to get and set information about the
**				  object and a constructor that takes "const" parameters.
****************************************************************************/
#include<string>

#ifndef BUILDING_HPP   
#define BUILDING_HPP

class Building
{
private:           
	std::string name;
	int size;
	std::string address;
public:
	Building();
	Building(const std::string, const int, const std::string);
	std::string getName();
	int getSize();
	std::string getAddress();
	void setTitle(std::string);
	void setSize(int);
	void setAddress(std::string);
	char getType();
};
#endif

