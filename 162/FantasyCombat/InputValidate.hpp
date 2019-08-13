/*************************************************************************** 
**   Program Name: Project 3 (InputValidate.hpp)
**   Author: Andrew Clos
**   Date: 7/31/2019
**   Description: This is the class header for an Input Validation class
**                currently a work in progress, the class is being populated
**                with different types of validation functions as they are 
**                required and as skills are learned. For this assignment,
**				  no new methods were added, but additional cleanup was done
**				  to remove cin >> entry and use the getline() function instead.
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