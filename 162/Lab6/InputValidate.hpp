/*************************************************************************** 
**   Program Name: Lab 6 (InputValidate.hpp)
**   Author: Andrew Clos
**   Date: 7/30/2019
**   Description: This is the class header for an Input Validation class
**                currently a work in progress, the class is being populated
**                with different types of validation functions as they are 
**                required and as skills are learned. 
****************************************************************************/

#ifndef INPUTVALIDATE_HPP
#define INPUTVALIDATE_HPP

class InputValidate
{
private:
	void boolAcceptable();
public:
	int intValidate(char, int, int);
	std::string arrayIntVal(int);
	std::string strValidate(bool, unsigned int);
	bool boolValidate(); 
	double doubleValidate(char, double, double);
};
#endif