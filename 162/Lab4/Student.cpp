/***************************************************************************
**   Program Name: Lab 4 OSU Information System (Student.cpp)
**   Author: Andrew Clos
**   Date: 7/19/2019
**   Description: The student class contains its own specific member variable
**				  for grade point average as well as the proper text output
**			      and random number generation for homework.  
****************************************************************************/
#include<iostream>
#include<iomanip>
#include<random>
#include "Student.hpp"

//defualt constructor and constructor since these would not be inherited 
//from the base class
Student::Student()
{
	name = "XXX";
	age = 99;
	gradePoint = 9.9;
}
Student::Student(std::string stuName, int stuAge, double stuGrade)
{
	name = stuName;
	age = stuAge;
	gradePoint = stuGrade;
}
/***************************************************************************
**   Description: Generates a random integer between 1 and 60 to represent the
**				  hours of homework a Student might do.
****************************************************************************/
void Student::doWork()
{
	std::random_device randDev;
	std::mt19937 randSeed(randDev());
	std::uniform_real_distribution<double> randomNum(1, 60);

	std::cout << "Student did " << std::fixed << std::setprecision(1) << randomNum(randSeed) << " hours of homework." << std::endl;
}
/***************************************************************************
**   Description: The following two functios output or return information
**				  specific to a student derived class.
****************************************************************************/
void Student::printGradeType()
{
	std::cout << "GPA: ";
}

char Student::getType()
{
	return 's';
}
/***************************************************************************
**   Description: The following are set and get methods for student GPA.
****************************************************************************/
double Student::getGrade()
{
	return gradePoint;
}

void Student::setGradePoint(double grade)
{
	gradePoint = grade;
}


