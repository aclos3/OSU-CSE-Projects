/***************************************************************************
**   Program Name: Lab 1 (determinant.cpp)
**   Author: Andrew Clos
**   Date: 06/28/2019
**   Description: This function takes a pointer to a 2d array and an integer
**			      for the array's size.  An if statement allows the 2x2 or
**			      3x3 array's determinant to be calculated.  An integer
**		         value of the calculated determinant is returned to the 
**             caller.
**************************************************************************/

#include<iostream>
#include "determinant.hpp"

int determinant(int **pMat, int arrSize)
{
	int determinant = 0;

	if (arrSize == 2)
	{      //equation for 2x2 matrix determinant.
		determinant = (pMat[0][0] * pMat[1][1]) - (pMat[0][1] * pMat[1][0]);
	}
	else if (arrSize == 3)
	{     //equation for 3x3 matrix determinant, terms broken in to 3 parts for readability.
		int aTerm = pMat[0][0] * ((pMat[1][1] * pMat[2][2]) - (pMat[1][2] * pMat[2][1])),
			bTerm = pMat[1][0] * ((pMat[0][1] * pMat[2][2]) - (pMat[2][1] * pMat[0][2])),
			cTerm = pMat[2][0] * ((pMat[0][1] * pMat[1][2]) - (pMat[1][1] * pMat[0][2]));
		determinant =  aTerm - bTerm + cTerm;
	}
	else   //error checking to warn that an array not equal to 2x2 or 3x3 was passed.
	{
		std::cout << "Input validation failed! matrix size is not 2x2 or 3x3." << std::endl;
	}
	return determinant;
}
