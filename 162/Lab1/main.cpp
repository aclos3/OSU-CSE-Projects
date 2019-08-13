/***************************************************************************
**   Program Name: Lab 1 (main.cpp)
**   Author: Andrew Clos
**   Date: 06/28/2019
**   Description: This program displays a menu to the user providing options
**                to choose a 2x2 or 3x3 matrix, or to quit. The program
**                then dynamically allocates a 2d matrix and then calls two
**                functions (pass a pointer to the matrix and matrix size)
**                to ask the user to fill the matrix with integers and to
**                calculate the determinant. Then, the matrix and deterinant
**                are printed to the console and the user is asked if they'd
**                like to 'play' again.               
**************************************************************************/

#include<iostream>
#include<string>
#include<iomanip>
#include "determinant.hpp"
#include "readMatrix.hpp"

/***************************************************************************
**   Description: (greeting) This simple function is called to display the
**                greeting and menu option to the users.  This was separated
**                from the main method in order to reduce duplicate text.
**************************************************************************/
void greeting()
{
	std::cout << "Please choose from the options below by entering the corresponding number and pressing 'Enter.'" << std::endl;
	std::cout << "(2) 2x2 matrix." << std::endl << "(3) 3x3 matrix." << std::endl << "(4) Exit." << std::endl;
}

/***************************************************************************
**  Description: This function performs basic input validation for menu
**               entry by making sure the value is an integer, cin extraction
**               passes and that the choice is a valid menu option.  It then
**               returns the integer value of the menu choice to the caller.                
**************************************************************************/
int validInt()
{
	int userInt,
		condition = 0;

	while (condition == 0)
	{
		std::cin >> userInt;
		//Perform detection of bad cin entry to avoid errors, infinite loops, etc.
		//Source cited for proper cin.fail() usage: https://stackoverflow.com/questions/17928865/correct-way-to-use-cin-fail
		if (std::cin.fail())
		{      //if the cin extraction failed, clear the buffer, ignore extraneous input, warn user.
			std::cin.clear();   
			std::cin.ignore(32767, '\n');
			std::cout << "Input invalid, please try again." << std::endl;
		}
		//If cin did not fail, check to see if entry is out of range of menu choices.
		else if (userInt != 2 && userInt != 3 && userInt != 4)
		{
			std::cout << "That was not a valid menu choice. Please try again." << std::endl;
		}
		//The passing condition! Clear the buffer and then set 'condition' to get out while loop.
		else
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			condition = 1;
		}
	}
	return userInt;
}
/***************************************************************************
**  Description: This function validates the yes or no 'y', 'n', 'Y', 'N'
**               input from the user and returns that value as a string to
**               the caller.
**************************************************************************/
std::string again()
{
	int condString = 0;
	std::string userInput = " ";

	std::cout << "Please enter 'y' for yes or 'n' for no. " << std::endl;

	while (condString == 0)
	{
		std::cin >> userInput;
		if (userInput.length() == 1)  //checks to see if more than one character entered.
		{
			if (userInput[0] == 'y' || userInput[0] == 'n' || userInput[0] == 'N' || userInput[0] == 'Y')
			{  //if appropriate character was entered, set condition to exit loop, return the string to caller.
				condString = 1;
				return userInput;
			}
			else   //Explain to user that the wrong character was entered, try again.
			{
				std::cout << "Please try again.  Enter the character 'y' or 'n' " << std::endl;
			}
		}
		else
		{
			std::cout << "Please try again. Enter only a single character. " << std::endl;
		}
	}
	return 0;
}
/***************************************************************************
**  Description: The main method initializes variables, displays the menu 
**               and then gets user's initial menu choice before entering a 
**               while loop where the main program runs. Within the while
**               loop, a dynamic 2d array is initialized, the readArray and
**               determinant functions are called and the matrix and 
**               determinant values are displayed to the console.  The 
**               dynamic array is deleted, and the user is asked if they
**               want to 'play' again.
**************************************************************************/
int main()
{
	int userChoice = 0;
	std::string playAgain = " ";
	
	greeting();  //display the greeting and menu options
	userChoice = validInt();  //use function to get user input and perform validation

	while (userChoice != 4 && playAgain[0] != 'n')
	{
		int **dynArray = new int*[userChoice];  //delcare an array of pointers to arrays

		for (int i = 0; i < userChoice; i++)  //initialize array: follows logic of a 2d array being thought of as a 1d array of 1d arrays.
		{
			dynArray[i] = new int[userChoice];
		}
		//call function, pass pointer to dynamically allocated array and array size
		readMatrix(dynArray, userChoice);
		//initialize variable for determinant value, call function to calculate that value.
		int userDet = determinant(dynArray, userChoice);

		//print the user's matrix
		std::cout << "Here is your matrix:" << std::endl;
		for (int i = 0; i < userChoice; i++)
		{
			for (int j = 0; j < userChoice; j++)
			{
				std::cout << std::setw(8) << dynArray[i][j] << " "; 
			}
			std::cout << std::endl;
		}
		std::cout << "The determinant is: " << userDet << std::endl;
		//free up the memory used by the dynamically allocated 2 array.
		for (int i = 0; i < userChoice; i++)
		{
			delete[] dynArray[i];
		}
		delete[] dynArray;

		//prompt user to play again, validate their input choice by calling 'again' function.
		std::cout << std::endl << "Would you like to play again? " << std::endl;
		playAgain = again();

		if (playAgain[0] == 'y' || playAgain[0] == 'Y')
		{
			greeting();
			userChoice = validInt();
		}
	}
    return 0;
}
