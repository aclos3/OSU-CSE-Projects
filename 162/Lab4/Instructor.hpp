/***************************************************************************
**   Program Name: Lab 4 OSU Information System (Instructor.hpp)
**   Author: Andrew Clos
**   Date: 7/19/2019
**   Description: The Instructor class is a derived class of a Person and contains
**				  specific information to an instructor: "rating." A
**				  default constructor and constructor are included because
**			      these would not be inherited from the base class.
****************************************************************************/
#include "Person.hpp"

#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

class Instructor : public Person
{
private: 
	double rating;
public:
	Instructor();
	Instructor(const std::string, const int, const double);
	virtual void doWork();
	virtual double getGrade();
	void setRate(double);
	void printGradeType();
	char getType();
	
};
#endif