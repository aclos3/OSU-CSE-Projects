/******************************************************************** 
** Author: Andrew Clos
** Date: 04/12/2019
** Description: Assignment 3a (minmax). This program will ask the
**              user to input a number of integers that they specify
**              The program will then determin which of these is the
**              highest and lowest and output those numbers.
********************************************************************/ 

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main () 
{
   int numberOfInts, currentInt, firstInt, minInt, maxInt;

   cout << "How many integers would you like to enter?" << endl;    //Get number of integers from user
   cin >> numberOfInts;
   cout << "Please enter " << numberOfInts << " integers." << endl; //Prompts for user chosen number of integers.
   cin >> firstInt;
   minInt = maxInt = firstInt;         //first integer outside loop to establish initial values of min and max
 
   for(int x = 0; x < (numberOfInts - 1); x++)  //loop to get remainder of user integers 
   {
      cin >> currentInt;                 //Two if statements to evaluate the input and update minInt and maxInt.
      if(currentInt < minInt) {
         minInt = currentInt;
      }
      if (currentInt > maxInt) {    
         maxInt = currentInt; 
      }
   }
   cout << "min: " << minInt << endl;   //Output min and max to console
   cout << "max: " << maxInt << endl;   
      
   return 0;
}
