/***************************************************************************
**   Program Name: Lab 4 OSU Information System (University.cpp)
**   Author: Andrew Clos
**   Date: 7/19/2019
**   Description: This class contains the print methods to output personnel 
**				  and building information.  It also contains the do_work
**				  function that calls the appropriate person to put in a
**				  random number of hours of work.  
****************************************************************************/

#include<iostream>
#include<iomanip>

#include "University.hpp"
#include "Person.hpp"
#include "InputValidate.hpp"

const char YESLIMITS = 'y';

/***************************************************************************
**   Description: Constructor sets name to "Oregon State University."  
****************************************************************************/
University::University()
{
	name = "Oregon State University";
}
/***************************************************************************
**   Description: This function takes a vector of Buildings and uses a 
**                for-loop and vector size function to step through and 
**			      output each building's information to the console.
****************************************************************************/
void University::printBuildings()
{
	for (unsigned int i = 0; i < buildings.size(); i++)
	{
		std::cout << std::endl;
		std::cout << "Building " << i + 1 << ": " << std::endl;
		std::cout << "Name: " << buildings[i]->getName() << ",  Size: " << buildings[i]->getSize() << "sqft,  Address: " << buildings[i]->getAddress() << std::endl;
	}
	std::cout << std::endl;
}
/***************************************************************************
**   Description: This functions takes a vector of Persons and uses a
**                for-loop and vector size function to step through and
**			      output each Person's information to the console.
****************************************************************************/
void University::printPeople()
{
	for (unsigned int i = 0; i < people.size(); i++)
	{
		
		std::cout << std::endl;
		std::cout << "Person " << i + 1 << ": " << std::endl;
		std::cout << "Name: " << people[i]->getName() << ", Age: " << people[i]->getAge() << " years, ";
		people[i]->printGradeType();  //makes call to appropriate function within Student or Instructor to print the right type.
		std::cout << std::fixed << std::setprecision(1) << people[i]->getGrade() << std::endl;
	}
	std::cout << std::endl;
}
/***************************************************************************
**   Description: Do work steps through the vector of Persons and prints their
**				  names to the console to let the user decide who they'd like
**				  to work.  Then it makes a call to that Person's doWork function.
****************************************************************************/
void University::workPeople()
{
	InputValidate workerValidate;
	int userChoice = 0;
	for (unsigned int i = 0; i < people.size(); i++)
	{
		std::cout << "(" << i + 1 << ") " << people[i]->getName() << "." << std::endl;
	}
	userChoice = workerValidate.intValidate(YESLIMITS, 1, people.size());
	people[userChoice - 1]->doWork();
}
/***************************************************************************
**   Description: The following 5 functions get information about the name
**				  of the university, or number of people or buildings it 
**			      contains.  There are also two add functions that utilize
**				  a vector's push.back feature to add a new Building or Person
**				  pointer to the end of the vector.
****************************************************************************/
std::string University::getName()
{
	return std::string(name);
}

int University::getNumPeople()
{
	return people.size();
}

int University::getNumBuilds()
{
	return buildings.size();
}

void University::addBuilding(Building* builds)
{
	buildings.push_back(builds);
}

void University::addPerson(Person* pers)
{
	people.push_back(pers);
}
