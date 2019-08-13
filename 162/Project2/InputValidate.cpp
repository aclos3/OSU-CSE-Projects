/***************************************************************************
**   Program Name: Project 2(InputValidate.cpp)
**   Author: Andrew Clos
**   Date: 7/20/2019
**   Description: This is the class that I am actively developing for CS162
**                to perform input validation on programming projects.  It
**                is designed around console input (cin) and currently has
**                public methods for integer, string validation, bool and new
**				  for project 2 double data entry validation.  
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
	std::string userEntry = " ";

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
/***************************************************************************
**   Description: Bool validation. Takes user entry as a string, converts 
**				  string to lowercase, and tests for proper characters in
**				  position.  Can handle "Yes, yes, YES, Y, y, T, t, No,  no,
**				  NO,  N, n, F, f." Makes a call to separate helper function
**				  to print the acceptable list of entries when user entry is 
**				  invalid. 
****************************************************************************/
bool InputValidate::boolValidate()
{
	bool boolValid = false;  
	bool userBool = 0;
	std::string userEntry = "";

	while (!boolValid)
	{
		int badCount = 0;
		userEntry = "";

		std::cin >> userEntry;
	
		if (userEntry.length() > 3)
		{
			std::cout << "Entry too long, please try again." << std::endl;
			badCount++;
		}
		else
		{   //this loop makes sure each character is an upper or lower case member of the alphabet.
			for (unsigned int i = 0; i < userEntry.length(); i++)
			{
				if (userEntry[i] < 65 || userEntry[i] > 122 || (userEntry[i] < 97 && userEntry[i] > 90))
				{
					std::cout << "'" << userEntry[i] << "' is not a valid character, please try again." << std::endl;
					badCount++;
				}
				else
				{  //this statement converts any upper case characters to lowercase
					if (userEntry[i] >= 65 && userEntry[i] <= 90)  
					{
						userEntry[i] = userEntry[i] + 32;
					}
				}
			}  //string is now lower case and not longer than three characters. Next, check to see if answer matches 'yes' or 'no'
			if (badCount == 0)
			{
				if (userEntry.length() == 3 && userEntry[0] == 121 && userEntry[1] == 101 && userEntry[2] == 115)
				{
					userBool = true;
				}
				else if (userEntry.length() == 3)
				{
					badCount++;
				}
				else if (userEntry.length() == 2 && userEntry[0] == 110 && userEntry[1] == 111)
				{
					userBool = false;
				}
				else if (userEntry.length() == 2)
				{
					badCount++;
				}
				else if (userEntry.length() == 1 && (userEntry[0] == 116 || userEntry[0] == 121))
				{
					userBool = true;
				}
				else if (userEntry.length() == 1 && (userEntry[0] == 102 || userEntry[0] == 110))
				{
					userBool = false;
				}
				else
				{
					badCount++;
				}
			}
		}
		if (badCount == 0) //if the string passes the digit check badCount will be 0.
		{
			boolValid = true;
		}
		else
		{
			boolAcceptable();
		}
		std::cin.clear();
		std::cin.ignore(32767, '\n');
	}
	return userBool;
}
/***************************************************************************
**   Description: Similar to integer validation, but must handle a period.
**				  This class also allows a leading zero if followed immediately
**				  by a period (ex. 0.2), but won't allow a leading zero that is
**				  not (ex 02.0 not allowed). This also checks to make sure 
**				  there is not more than one period in any user's entry.
****************************************************************************/
double InputValidate::doubleValidate(char useLimits, double lowerLimit, double upperLimit)
{
	bool dblValid = false;
	double userDouble = 0.0;
	std::string userEntry = " ";

	while (!dblValid)
	{
		int badCount = 0,
			dotCount = 0;

		std::cin >> userEntry;
		//step through the string and make sure each value is an integer.
		for (unsigned int i = 0; i < userEntry.length(); i++)
		{
			if (i == 0)
			{
				if (userEntry[i] != 46 && userEntry[i] != 45 && (userEntry[i] > 57 || userEntry[i] < 48))
				{
					std::cout << "'" << userEntry[i] << "' is not a valid digit, please try again." << std::endl;
					badCount++;
				}
				
			}
			else if (userEntry[i] != 46 && (userEntry[i] > 57 || userEntry[i] < 48))
			{
				std::cout << "'" << userEntry[i] << "' is not a valid digit, please try again." << std::endl;
				badCount++;
			}
			if (userEntry[i] == 46)
			{
				dotCount++;
				if (dotCount > 1)
				{
					std::cout << "A real number cannot contain multiple '.' characters, please try again." << std::endl;
					badCount++;
				}
			}
		}
		if (userEntry.length() >= 2 && userEntry[0] == 48 && userEntry[1] != 46)
		{
			std::cout << "Leading zero is invalid, please try again." << std::endl;
			badCount++;
		}

		if (badCount == 0) //if the string passes the digit check badCount will be 0.
		{
			std::istringstream(userEntry) >> userDouble;
			dblValid = true;

			if (useLimits == 'y') //perform optional size validation
			{
				dblValid = false;

				if (userDouble < lowerLimit)
				{
					std::cout << "Entry is below the lower limit, please try again." << std::endl;
				}
				else if (userDouble > upperLimit)
				{
					std::cout << "Entry is above the upper limit, please try again." << std::endl;
				}
				else
				{
					dblValid = true;
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
	return userDouble;
}
/***************************************************************************
**   Description: Prints the acceptable entries for user boolean entry.
****************************************************************************/
void InputValidate::boolAcceptable()
{
	std::cout << "Acceptable entries for Yes/True are: Yes, yes, YES, Y, y, T, t" << std::endl;
	std::cout << "Acceptable entries for No/False are: No,  no,  NO,  N, n, F, f" << std::endl;
	std::cout << "Please try again: " << std::endl;
}