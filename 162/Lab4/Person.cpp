/***************************************************************************
**   Program Name: Lab 4 OSU Information System (Person.cpp)
**   Author: Andrew Clos
**   Date:  7/19/2019
**   Description: The Person class contains several "warning" outputs that if
**				  called would indicate that something in this exercise went 
**				  wrong (that a base class exists instead of one of the derived
**				  classes.
****************************************************************************/

#include<iostream>
#include<random>
#include "Person.hpp"

/***************************************************************************
**   Description: Generates a random integer between 1 and 60 to represent the
**				  hours of work a Person might do.  
****************************************************************************/
void Person::doWork()
{
	std::random_device randDev;
	std::mt19937 randSeed(randDev());
	std::uniform_real_distribution<double> randomNum(1, 60);
	//Prints a base class dowork message in case the proper student or instructor message was not chosen.
	std::cout << "BASE CLASS did: " << randomNum(randSeed) << " hours of work." << std::endl;

}
//For this exercise, if Base: is ever output, it means a object of the base class Person
//exists instead of as an Instructor or Student. We don't want to see this happen.
void Person::printGradeType()
{
	std::cout << "Base: ";
}
char Person::getType()
{
	return 'p';
}
/***************************************************************************
**   Description: The following five functions are getters and setters for 
**				  setting and returning private member variable information
**				  to the caller.
****************************************************************************/
double Person::getGrade()
{   //this returns a nonsense value since all Objects should of instructor or student
	//type and not of the base Person class.  If 9.9 gets returned, something went wrong.
	return 9.9;
}
std::string Person::getName()
{
	return name;
}
int Person::getAge()
{
	return age;
}
void Person::setAge(int years)
{
	age = years;
}
void Person::setName(std::string pName)
{
	name = pName;
}
Person::~Person()
{
}
