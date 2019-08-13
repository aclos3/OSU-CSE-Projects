/************************************************************************ 
** Author: Andrew Clos
** Date: 04/04/2019
** Description: Assignment 2b (tempConvert)
*************************************************************************/

/************************************************************************* 
** Description: This program asks the user to input a temperature in
** Celsius and computes then outputs the Fahrenheit equivalent.
*************************************************************************/

#include <iostream>    // included in order to use the input output streams
using std::cout;       // Avoiding the using namespace std and instead
using std::cin;        // defining cout, cin and endl individually.
using std::endl;


int main()
{
   double tempC, tempF; //define floating point variables for temperatures.
   
   cout << "Please enter a Celsius temperature." << endl;   //prompt user for Celsius temp 
   cin >> tempC;    //Prompts for user input of Celsius temperature 
   tempF = (9 * tempC / 5) + 32;  //tempF gets value as calculated from fromula and user entered tempC
   cout << "The equivalent Fahrenheit temperature is:" << endl;
   cout << tempF << endl;   //tempF is output to the console, line is ended.
   
   return 0;
} 
