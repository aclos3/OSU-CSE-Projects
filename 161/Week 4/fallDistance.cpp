/********************************************************************* 
** Author: Andrew Clos
** Date: 04/22/2019
** Description: Assignment 4a (fallDistance)
*********************************************************************/

#include<iostream>


const double GRAVITY = 9.8;    //global constant for accel of gravity

double fallDistance (double fallTime = 0); //function prototype, initialze fallTime

/*
int main()
{
   double fallTime = 3.2;
   cout << fallDistance(fallTime) << endl;
   
return 0;
}
*/

/********************************************************************* 
** Description: This program will determine how far an object will 
** fall in a given period of time based on gravity.
*********************************************************************/ 

double fallDistance(double fallTime) 
{
   return (0.5 * GRAVITY * fallTime * fallTime);  //Perform calculation and return it 
}



