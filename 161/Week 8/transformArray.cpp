/*********************************************************************
 * ** Author: Andrew Clos
 * ** Date: 05/17/2019
 * ** Description: Assignment 8b (transformArray.cpp) This function
 * **              definition takes two parameters, a reference to a 
 * **              pointer to a dynamically allocated array of ints and 
 * **              the size of the that array.  
 * *********************************************************************/

#include<iostream>
#include<cstdlib>   //for use of NULL

/********************************************************************
 * ** Description:  The function dynamically allocates an array that is 
 * **           twice as long as the original and fills with the 
 * **           original values followed by twice those values.
 * ********************************************************************/

void transformArray(int* &arrayInts, int arraySize)
{
   int* twiceArray = new int[arraySize * 2];   //new dynam alloc array

   for (int i = 0; i < arraySize; i++)  //copy original values into 
   {                                    //first half of new array.
      twiceArray[i] = arrayInts[i];
   }
   for (int i = 0; i < arraySize; i++)  //second half of new array gets
   {                            //double the values in original.
      twiceArray[i + arraySize] = arrayInts[i] * 2;
   }
               
   delete[] arrayInts;   //free memory
   arrayInts = NULL;     //remove dangling pointer
                  //assign the original array the values of the new one
   arrayInts = twiceArray;  
}
