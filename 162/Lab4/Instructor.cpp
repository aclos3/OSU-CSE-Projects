/***************************************************************************
**   Program Name: Lab 4 OSU Information System (Instructor.cpp)
**   Author: Andrew Clos
**   Date: 7/19/2019
**   Description: The student class contains its own specific member variable
**				  for rating as well as the proper text outputand random
**				  number generation for grading papers.
****************************************************************************/

#include <iostream>
#include <iomanip>
#include <random>
#include "Instructor.hpp"

//defualt constructor and constructor since these would not be inherited 
//from the base class
Instructor::Instructor()
{
	name = "XXX";
	age = 99;
	rating = 9.9;
}
Instructor::Instructor(std::string insName, int insAge, double insRate)
{
	name = insName;
	age = insAge;
	rating = insRate;
}
/***************************************************************************
**   Description: Generates a random integer between 1 and 60 to represent the
**				  hours of paper grading an Instructor might do.
****************************************************************************/
void Instructor::doWork()
{
	std::random_device randDev;
	std::mt19937 randSeed(randDev());
	std::uniform_real_distribution<double> randomNum(1, 60);

	std::cout << "Instructor graded papers for " << std::fixed << std::setprecision(1) << randomNum(randSeed) << " hours." << std::endl;
}
/***************************************************************************
**   Description: The following two functios output or return information
**				  specific to an Instructor derived class.
****************************************************************************/
void Instructor::printGradeType()
{
	std::cout << "Rating: ";
}

char Instructor::getType()
{
	return 'i';
}
/***************************************************************************
**   Description: The following are set and get methods for instructor rating.
****************************************************************************/
double Instructor::getGrade()
{
	return rating;
}

void Instructor::setRate(double setRate)
{
	rating = setRate;
}

