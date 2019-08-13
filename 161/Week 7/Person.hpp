/********************************************************************* 
** Author: Andrew Clos
** Date: 05/11/2019
** Description: Assignment 7b (Person.hpp) This class 
**              declaration provides the framework for an object
**              respresenting a Person.  It contains a string variable
**              for name and a double variable for age. It has get 
**              methods for both data members and a constructor that  
**              takes two values to initialize the data members. 
*********************************************************************/ 

#ifndef PERSON_HPP    //include guards
#define PERSON_HPP

#include<string>

//  Defines the interface of the Person class
class Person
{
   private:            //data members kept private
      std::string name;
      double age;
   public:            
      Person();       //Default constructor 
      Person(std::string, double);  //constructor declared
      std::string getName();
      double getAge();
};
#endif
