/********************************************************************* 
** Author: Andrew Clos
** Date: 05/06/2019
** Description: Assignment 6a (Vase.hpp) This class 
**              declaration provides the framework for an object
**              respresenting a Vase.  Two data members include a 
**              HalfOpenCylinder and a cost-per-square-inch. It also 
**              contains a constructor to initialize the data menebers. 
**              It also contains a function to calculate total cost
**              and another to determine if the Vase the function is
**              called on costs more than Vase passed as a parameter.
*********************************************************************/ 

#ifndef VASE_HPP    //include guards
#define VASE_HPP

#include "HalfOpenCylinder.hpp"

//  Defines the interface of the Vase class
class Vase
{
   private:            //data members kept private
      HalfOpenCylinder vaseDims;
      double costPsi;
   public:            
      Vase(HalfOpenCylinder, double);  //constructor declared
      double totalCost();
      bool costsMoreThan(Vase);   //takes a Vase as paramenter to compare to method Vase.
};
#endif
