/***************************************************************************
**   Program Name: Lab 1 (readMatrix.cpp)
**   Author: Andrew Clos
**   Date: 06/28/2019
**   Description: This function takes a pointer to a 2d array and an integer
** 			      for the array's size. It displays instructions to the user 
**                via the console and uses nested for loops to take the 
**                appropriate number of integers for the matrix size.  Basic
**                input validation occurrs using a while loop and if 
**                statements.
**************************************************************************/

#include<iostream>
#include "readMatrix.hpp"

void readMatrix(int **pMat, int arrSize)
{
	std::cout << "Please enter " << arrSize * arrSize << " integers to fill your " << arrSize << " x " << arrSize << " matrix. One at a time and press enter after each entry." << std::endl;

	for(int i = 0; i < arrSize; i++)  //nested for loops to fill 2d array
	{
		for (int j = 0; j < arrSize; j++)
		{
			int condition = 0;

			while (condition == 0)  //input validation loop
			{
				std::cin >> pMat[i][j];
				
				if (std::cin.fail())  //same validation used in main, but with unrestricted integer choice.
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::cout << "Input invalid, please try again." << std::endl;
				}
				else
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					condition = 1;
				}
			}
		}
	}
}
