/*************************************************************************** 
**   Program Name: Lab 2 (InputValidate.hpp)
**   Author: Andrew Clos
**   Date: 7/2/2019
**   Description: This is the class header for an Input Validation class
**                Currently a work in progress, the class is being populated
**                with different types of validation functions as they are 
**                required and as skills are learned. So far, integer and
**                string validation have been created.
****************************************************************************/

#ifndef INPUTVALIDATE_HPP
#define INPUTVALIDATE_HPP

class InputValidate
{
private:
	
public:
	int intValidate(char, int, int);
	std::string strValidate(bool, unsigned int);
};
#endif