/********************************************************************* 
** Author: Andrew Clos
** Date: 04/23/2019
** Description: Assignment 4c (hailstone)
*********************************************************************/

#include<iostream>

int hailstone(int startVal); 
/*
int main()
{
   int firs = 249943423;
   int stepss;
   stepss = hailstone(firs);
   cout << stepss << endl;       
   
   return 0;
}
*/

/********************************************************************* 
** Description: This function performs a hailstone sequence where the   
** a starting integer is divided by two.  If it is odd, you multiply
** it by three and add one to get the next integer and keep applying
** the same rules until you get to the value of one. The number of
** steps it takes will be counted and returned.
*********************************************************************/ 

int hailstone(int startVal) 
{
   int steps = 0,
       currentVal = 0;

   if (startVal != 1)   //only perform 'math' if not equal to one 
   {
      currentVal = startVal; //new variable, avoids modifying startVal
      do 
      {
         if (currentVal % 2 == 0)   //the check for even
            currentVal = currentVal / 2;            
         else                       //otherwise it is odd
            currentVal = (currentVal * 3) + 1; 
            
         steps++;                   //increment step counter
      }
      while(currentVal != 1);    //only stop once value reaches one
   }
   return steps;  
}   
   


