/********************************************************************* 
** Author: Andrew Clos
** Date: 05/11/2019
** Description: Assignment 7b (stdDev.cpp) This function definition
**              sets the parameters for a stdDev method which includes
**              an array of Person objects and the size of the array. 
**              The function returns the standard deviation of the ages 
**              the Person objects. 
*********************************************************************/ 

#include <iostream>
#include <cmath>
#include "Person.hpp"

/**********************************************************************
**
** Description: Two loops and some algebra are used to sum the ages of
**              all Person objects in the array, compute the mean age
**              subtract the mean age from each Person's age and then 
**              square these differences.  Finally, sum of squared 
**              differences is divided by the array size, square rooted
**              and returned.
**********************************************************************/

double stdDev(Person thePersons[], int arraySize)
{
   int i;
   double meanAge = 0,
          sumAge = 0,
          sqSumDiff = 0;

   for (i = 0; i < arraySize; i++)  //loop to calc mean age
   {
      sumAge = sumAge + thePersons[i].getAge();
   }
   meanAge = sumAge / arraySize;
   
   for (i = 0; i < arraySize; i++)  //loop to sum square differences from mean
   {
      sqSumDiff = sqSumDiff + pow(thePersons[i].getAge() - meanAge, 2);
   }
   
   return sqrt(sqSumDiff / arraySize); //square root of the squared difference sums / array size returned.
}
