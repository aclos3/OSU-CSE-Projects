/********************************************************************* 
** Author: Andrew Clos
** Date: 05/06/2019
** Description: Assignment 6a (Vase.cpp) This function definition sets
**           the parameters for a Vase, which include dimensions of
**          a half open cylinder and cost per square inch. It 
**          contains a function that returns the total cost of 
**          the vase and another that determines if this vase 
**          costs more than than the vase that was passed as a 
**          parameter.
*********************************************************************/ 

#include <iostream>
#include "Vase.hpp"
#include "HalfOpenCylinder.hpp"

/********************************************************************* 
** Description: Constructor for HalfOpenCylinder and cost per square 
**              inch.
*********************************************************************/

Vase::Vase(HalfOpenCylinder cylinderIn, double costIn)
{
   vaseDims = cylinderIn;
   costPsi = costIn;
}

/********************************************************************* 
** Description: Calculates the total cost of the cylinder and returns it.
*********************************************************************/ 

double Vase::totalCost()
{
   return ((vaseDims.surfaceArea()) * costPsi);
}

/*********************************************************************
** Description: Returns true if the vase the method is called on costs 
**             more than the one passed as a parameter.
*********************************************************************/

bool Vase::costsMoreThan(Vase vase2)
{
   

   if(totalCost() > vase2.totalCost())
   {
      return true;
   }
   else
   {
      return false;
   }
}
