/***************************************************************************
**   Program Name: Lab 5 (main.hpp)
**   Author: Andrew Clos
**   Date: 7/25/2019
**   Description: Header file for the main method. A number of constants are
**				  established here that are mostly used for menu limits and
**				  sent to input validation.  Also, the function definitions
**				  for the program's three functions are here.
****************************************************************************/

#ifndef MAIN_HPP
#define MAIN_HPP

#include<string>

//constants for upper and lower limits of user choices.
const int MAXSTR = 500;
const int MININT = 1;
const int MAXINT = 50;
const int TRIMAX = 1000;
const int MINMENU = 1;
const int MAXMENU = 4;
const char YESLIMITS = 'y';

void reverseArray(std::string, int);
void sumArray(int*, int);
void triangleNumber(int, int);

#endif