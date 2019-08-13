/************************************************************************** 
** Author: Andrew Clos
** Date: 05/11/2019
** Description: Assignment 7b (Person.cpp) This function definition 
**              contains a constructor that takes two values and initializes
**              the name and age data members.  It also has two get methods 
**              for name and age.
**************************************************************************/

#include "Person.hpp"
#include <iostream>
/********************************************************************* 
** Description: Default constructor since constructor is utilized for  
**              initialization.
*********************************************************************/
Person::Person()
{
   name = " ";
   age = 0;
}

/********************************************************************* 
** Description: Constructor to initialize the name and age data 
**              members.
*********************************************************************/
Person::Person(std::string initName, double initAge)
{
   name = initName;
   age = initAge;
}

std::string Person::getName()
{
   return name;
}

double Person::getAge()
{
   return age;
}
