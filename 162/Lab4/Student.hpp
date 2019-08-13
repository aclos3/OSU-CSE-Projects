/*************************************************************************** 
**   Program Name: Lab 4 OSU Information System (Student.hpp)
**   Author: Andrew Clos
**   Date: 7/19/2019
**   Description: The student class is a derived class of a Person and contains
**				  specific information (to a student), "grade point." A 
**				  default constructor and constructor are included because
**			      these would not be inherited from the base class.
****************************************************************************/
#include<string>
#include"Person.hpp"

#ifndef STUDENT_HPP
#define STUDENT_HPP

class Student : public Person
{
private: 
	double gradePoint;
public:
	Student();
	Student(const std::string, const int, const double);
	virtual void doWork();
	virtual double getGrade();
	void setGradePoint(double);
	void printGradeType();
	char getType();
};
#endif