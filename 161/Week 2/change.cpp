/*****************************************************************************
** Author: Andrew Clos
** Date: 04/06/2019
** Description: Assignment 2c (change): This program asks the user to input
**              a value of change (integer between 0-99) and then uses integer
**              division and the modulus operator to determine the least
**              number of coins needed to make the change.
*****************************************************************************/

#include <iostream>    // included to use input output streams
using std::cout;       // using cout, cin and endl from the std namespace
using std::cin;        
using std::endl;


int main()
{
   const int VALUE_Q = 25, VALUE_D = 10, VALUE_N = 5;  //set constants for values of Quarter, Dime, Nickle.
   int cents, remainder, quarters, dimes, nickles, pennies; //integer variables defined

   cout << "Please enter an amount in cents less than a dollar." << endl;   //displayes text to console
   cin >> cents;    //User enters cents from console
   quarters = cents / VALUE_Q;  //integer division calculates quarters. 
   remainder = cents % VALUE_Q; //remainder of cents after quarters are removed.
   dimes = remainder / VALUE_D; //integer division calculates dimes
   remainder %= VALUE_D;        //remainder after dimes are removed. 
   nickles = remainder / VALUE_N;
   remainder %= VALUE_N;
   pennies = remainder;   //pennies left over after nickles are removed.
   cout << "Your change will be: " << endl;  //Outputs all values.  Each on own line for clarity of reading.
   cout << "Q: " << quarters << endl;
   cout << "D: " << dimes << endl;
   cout << "N: " << nickles << endl;
   cout << "P: " << pennies << endl;
   return 0;
}
