/***************************************************************************
**   Program Name: Lab 4 OSU Information System (University.hpp)
**   Author: Andrew Clos
**   Date:  7/19/2018
**   Description: This class header lays out a class of a University to 
**				  Oregon state.  The university contains two vectors of
**				  pointers to Persons and Buildings as well as print functions
**				  and methods to get and data and add new pointers to buildings
**				  and Person objects.
****************************************************************************/
#include<string>
#include<vector>
#include "Building.hpp"
#include "Person.hpp"

#ifndef UNIVERSITY_HPP   
#define UNIVERSITY_HPP

class University
{
private:           
	std::string name;
	std::vector<Building*> buildings;
	std::vector<Person*> people;
public:
	University();
	void printBuildings();
	void printPeople();
	void workPeople();
	std::string getName();
	int getNumPeople();
	int getNumBuilds();
	void addBuilding(Building*);
	void addPerson(Person*);
};
#endif

