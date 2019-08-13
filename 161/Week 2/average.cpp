/*************************************************************************** 
** Author: Andrew Clos
** Date: 04/04/2019
** Description: Assignment 2a (Average) This program takes the 
**              average of five floating point (double) values 
**              that the user enters from the console.
***************************************************************************/

#include <iostream>    // included to use input/output streams
using std::cout;       // using three names from std namespace
using std::cin;        
using std::endl;


int main()
{
   double num1, num2, num3, num4, num5, avg; //define six double variables.
   
   cout << "Please enter five numbers." << endl;  //displays to console 
   cin >> num1;     //Next five lines receive the entry of each number 
   cin >> num2;     //in the console from the user. 
   cin >> num3;
   cin >> num4;
   cin >> num5;
   avg = (num1 + num2 + num3 + num4 + num5) / 5; //the average is computed
   cout << "The average of those numbers is:" << endl << avg << endl; //value of avg is outputted to the console
   
   return 0;
} 
