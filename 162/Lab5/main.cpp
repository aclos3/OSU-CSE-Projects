/***************************************************************************
**   Program Name: Lab 5 (main.cpp)
**   Author: Andrew Clos
**   Date: 7/25/2019
**   Description: The main function introduces the program and then presents
**				  the menu options to the user. Input validation is performed
**				  on the menu choice and then the appropriate section is
**				  entered (if-statement block). From here additional data is
**				  collected from the user, validated and then the corresponding
**				  function is called. Functions for reversing a string, summing
**				  an array and computing the triangle value of a number are 
**				  included.
****************************************************************************/

#include<iostream>
#include<string>
#include<sstream>
#include "InputValidate.hpp"
#include "main.hpp"

int main()
{  
	InputValidate tester;
	bool playing = true;
	int menuChoice = 0,
		numInts = 0,
		triInt = 0;
	std::string intString = " ",
				testStr ="",
				stringToRev = " ";
	
	std::cout << "Welcome to a Recursive Demonstration!" << std::endl;
	std::cout << "Andrew Clos, CS162-400, Lab 5." << std::endl;

	while (playing)
	{		//main menu
		std::cout << "(1) Reverse a String." << std::endl;
		std::cout << "(2) Sum an Array of Integers." << std::endl;
		std::cout << "(3) Compute Triangle Number of an Integer." << std::endl;
		std::cout << "(4) Quit." << std::endl;
		menuChoice = tester.intValidate(YESLIMITS, MINMENU, MAXMENU);

		if (menuChoice == 1)  //reverse array
		{
			std::cout << "Please enter a string and I'll call a groovy function to reverse it." << std::endl;
			stringToRev = tester.strValidate(true, MAXSTR);
			reverseArray(stringToRev, stringToRev.length());

		}
		else if (menuChoice == 2)   //sum array
		{
			std::cout << "Please enter the number of integers that you'll put in your array." << std::endl;
			numInts = tester.intValidate(YESLIMITS, MININT, MAXINT);
			std::cout << "Please enter the integers that you'd like to put in your array, each separated by a space." << std::endl;
			testStr = tester.arrayIntVal(numInts);

			//declare dynamic array of integers
			int count = 0;
			int *userArray;
			userArray = new int[numInts];
			//string stream through the string, count 
			std::stringstream ss(testStr);

			//Found use of string stream helpful for extracting integers from a string and inserting them in to array elements.
			//https://stackoverflow.com/questions/41820639/c-extracting-the-integer-in-a-string-with-multiple-delimiters
			while (!ss.eof())
			{
				int fill = 0;
				if (ss.peek() != ' ' ) 
				{
					ss >> fill;
				}
				//protect from possible seg fault if input validation fails 
				if (count < numInts)
				{
					userArray[count] = fill;
					count++;
				}
				ss.get();
			}	
			//send userArray by reference to function
			sumArray(userArray, numInts);
			//free up the dynamically allocated memory
			delete[] userArray;
		}
		else if (menuChoice == 3)   //triangle value of array
		{
			int userSum = 0;

			std::cout << "Please enter the integer you'd like to see a triangle value for." << std::endl;
			triInt = tester.intValidate(YESLIMITS, MININT, TRIMAX);
			triangleNumber(triInt, userSum);
		}
		else if (menuChoice == 4)  //quit
		{
			playing = false;
		}
	}
	return 0;
}

/***************************************************************************
**   Description: The resverse string function simply begins reading a string,
**				  as if it were an array from the end (last index) to the
**				  beginning (zero index). It outputs these chracters to the
**				  console and they appear in reverse order from what the user
**				  typed in.
****************************************************************************/
void reverseArray(std::string userStr, int size)
{
	//recursive base case
	if (size < 1)
	{
		std::cout << std::endl << "String reversing complete, thank you." << std::endl;
	}
	//recursion
	else
	{  //array prints to console end to beginning.
		std::cout << userStr[size - 1]; 
		size--;
		reverseArray(userStr, size);
	}
}

/***************************************************************************
**   Description:  The concept here is that the number of addtions that need
**                 to occur is arrSize - 1.  So if three integers are incoming
**                 we just add the third element to the second element and 
**				   store the value in the second element.
****************************************************************************/
void sumArray(int* userArr, int arrSize)
{
	//base case, size is decremented to 1, display contents of first array element
	if (arrSize == 1)
	{
		std::cout << "The sum of the array integers is: " << userArr[0] << std::endl;
	}

	if (arrSize > 1)
	{
		userArr[arrSize - 2] = userArr[arrSize - 2] + userArr[arrSize - 1];
		sumArray(userArr, arrSize - 1);
	}
}
/***************************************************************************
**   Description:  Triangle calculation involves summing a counter variable
**				   "sum," that starts at 0 and adding the value in userNum
**				   to it.  This value starts with the user selected seed
**				   value and is decremented by 1 each time it is recursively
**				   called.  Once the base case is reached, the resulting sum
**				   is printed to the console.
****************************************************************************/
void triangleNumber(int userNum, int sum)
{
	if (userNum == 0)  
	{
		std::cout << "The Triangle is: " << sum << std::endl;
	}

	if (userNum > 0)
	{
		sum = sum + userNum;
		userNum--;
		triangleNumber(userNum, sum);
	}
}