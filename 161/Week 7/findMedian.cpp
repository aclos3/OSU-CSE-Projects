/********************************************************************* 
** Author: Andrew Clos
** Date: 05/11/2019
** Description: Assignment 7a (findMedian.cpp) This function 
**              definition takes two parameters, one is an array of  
**              integers and the other is the size of the array. 
**              The function returns the median value of the array.
*********************************************************************/ 

#include<algorithm>

/********************************************************************
**
** Description:  This function takes an array of integers and size
**               of array.  It checks to see if the size is odd or 
**               even and then returns the median as a double.
********************************************************************/

double findMedian(int arrayOfInts[], int arraySize)
{
   std::sort(arrayOfInts, arrayOfInts + arraySize);  //sort function orders array in ascending order

   if (arraySize % 2 == 1)   //check if number of array elements is odd
   {
      return arrayOfInts[(arraySize / 2)];  //int division will truncate, return median value of array
   }   
   else              //if not odd, then number of array elements are even
   {
      //this will take the middle two intgers, add them, divide them by 2 as doubles and return it.
      return (static_cast<double>(arrayOfInts[arraySize / 2] + arrayOfInts[(arraySize / 2) - 1]) / 2);
   }
   
}

