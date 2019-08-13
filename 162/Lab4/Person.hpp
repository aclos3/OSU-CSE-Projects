/***************************************************************************
**   Program Name: Lab 4 OSU Information System (Person.hpp)
**   Author: Andrew Clos
**   Date: 7/19/2019
**   Description: This class header defines the Person class which is a parent
**				  class to Instructors and Students.  Therefore, it uses several
**				  virtual public functions since these are "rewritten" by the 
**				  derived classes.
****************************************************************************/
#include<string>

#ifndef PERSON_HPP   
#define PERSON_HPP

class Person
{
protected:           
	std::string name;
	int age;
public:
	virtual void doWork();
	virtual double getGrade();
	std::string getName();
	int getAge();
	void setName(std::string);
	void setAge(int);
	virtual void printGradeType();
	virtual char getType();
	virtual ~Person();
};
#endif

