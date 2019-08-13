/********************************************************************* 
** Author: Andrew Clos
** Date: 05/06/2019
** Description: Assignment 6b (multiply.cpp) This function definition 
**              performs multiplcation operations on two positive 
**              intgers, recursively.  
*********************************************************************/ 


/********************************************************************* 
** Description: Calculates product of two integers via recursive
**              addition and returns it.
*********************************************************************/ 

int multiply(int var1, int var2)
{
   if (var2 == 0)     //to get out of recursive loop and check for 0 multiplcation
   {
      return 0;
   }
   else
   {
      return (var1 + multiply(var1, var2 - 1)); //decrement var2, then run function again
   }
}
