/********************************************************************* 
** Author: Andrew Clos
** Date: 05/17/2019
** Description: Assignment 8a (smallSort.cpp) This function 
**              definition takes three parameters, the addresses of   
**              three int variables and sorts them in to ascending  
**              order. 
*********************************************************************/ 

#include<iostream>

/********************************************************************
** Description:  This function takes the addresses of three integers 
**               and sorts them in ascending order. It uses a series
**               of if-else statements and a temporary variable to
**               to evaulate each value in the address and perform
**               the sorting.  
********************************************************************/


void smallSort2(int *first, int *second, int *third)
{
   if(*first > *second)
   {
      if (*first > *third)    //true if *first is largest overall
      {        
         if (*second > *third)    //true if *third is smallest overall
         {    
            int temp = *third;
            *third = *first;
            *first = temp;
         }
         else                  //*second is smallest overall
         {
            int temp = *first; 
            *first = *second;
            *second = *third;
            *third = temp;
         }
      }
      else              //*first > *second, but *first < *third
      {                  
         int temp = *second;
         *second = *first;
         *first = temp;
      }
   }
   else if (*first > *third)   //*first > *third, but < *second
   {   
      int temp = *third;
      *third = *second;
      *second = *first;
      *first = temp;
   }
   else if (*second > *third)   //*first smallest, *second > *third
   { 
      int temp = *third;
      *third = *second;
      *second = temp;
   }
}     
