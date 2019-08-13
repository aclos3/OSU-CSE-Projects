/***************************************************************************
**   Program Name: Lab 2 (InputValidate.cpp)
**   Author: Andrew Clos
**   Date: 7/2/2019
**   Description: This is the class that I am actively developing for CS162
**                to perform input validation on programming projects.  It
**                is designed around console input (cin) and currently has
**                public methods for integer and string validation.  
****************************************************************************/

#include<iostream>
#include<string>
#include<sstream>
#include "InputValidate.hpp"

const char YESLIMITS = 'y';
const char NOLIMITS = 'n';

/***************************************************************************
**   Description: Integer input validation. This function prompts the user to
**                enter data and takes that input as a string. It steps 
**                through the string to make sure each character is a valid 
**                digit 0 - 9. The first character is also allowed to be a '-'
**                symbol to indicate a negative number. If the characters are
**                found to be valid digits, the string is converted to an int
**                and if use-limits is flagged ('y') by the caller, the 
**                integer will be checked against the upper and lower limits.
**                The function returns an integer and takes a character and two
**                integers as arguements to perform optional limit checking.
****************************************************************************/
int InputValidate::intValidate(char useLimits, int lowerLimit, int upperLimit)
{
	bool intValid = false;
	int userInt = 0;
	std::string userEntry = "";

	while (!intValid)
	{
		int badCount = 0;

		std::cin >> userEntry;
		//step through the string and make sure each value is an integer.
		for (unsigned int i = 0; i < userEntry.length(); i++)
		{
			if (i == 0)
			{
				if (userEntry[i] != 45 && (userEntry[i] > 57 || userEntry[i] < 48))
				{
					std::cout << "'" << userEntry[i] << "' is not a valid digit, please try again." << std::endl;
					badCount++;
				}
				else if (userEntry[i] == 48)
				{
					std::cout << "Zero cannot be the first digit of an integer, please try again." << std::endl;
					badCount++;
				}
			}
			else if (userEntry[i] > 57 || userEntry[i] < 48)
			{
				std::cout << "'" << userEntry[i] << "' is not a valid digit, please try again." << std::endl;
				badCount++;
			}
		}
		if (badCount == 0) //if the string passes the digit check badCount will be 0.
		{
			std::istringstream(userEntry) >> userInt;
			intValid = true;
			
			if (useLimits == 'y') //perform optional size validation
			{
				intValid = false;

				if (userInt < lowerLimit)
				{
					std::cout << "Entry is below the lower limit, please try again." << std::endl;
				}
				else if (userInt > upperLimit)
				{
					std::cout << "Entry is above the upper limit, please try again." << std::endl;
				}
				else
				{
					intValid = true;
				}
			}
		}
		else
		{
			std::cout << "A total of " << badCount << " out of " << userEntry.length() << " characters entered were not valid integer elements." << std::endl;
		}
		std::cin.clear();
		std::cin.ignore(32767, '\n');
	}
	return userInt;
}

/***************************************************************************
**   Description: Simple string validation takes an int from the caller for 
**                max string length so that abnormally large strings are not
**                entered.  Optionally, we can declare that case is not 
**                sensitive and convert the entire string to lower case.
****************************************************************************/
std::string InputValidate::strValidate(bool caseSensitive, unsigned int maxStrLength)
{
	bool strValid = false;
	std::string userEntry = "";
	std::string scrubbedEntry = "";

	while (!strValid)
	{
		//std::cout << "Please enter your string: ";
		std::cin >> userEntry;
		
		if (userEntry.length() <= maxStrLength)
		{
			if (caseSensitive == false)
			{
				for (unsigned int i = 0; i < userEntry.length(); i++)
				{
					if (userEntry[i] >= 65 && userEntry[i] <= 90)  //converting to lowercase
					{
						userEntry[i] = userEntry[i] + 32;
					}
				}
			}
			strValid = true;
		}
		else
		{
			std::cout << "The maximum string length for this application is: " << maxStrLength << ". Please try again." << std::endl;
		}
	}
	return userEntry;
}
