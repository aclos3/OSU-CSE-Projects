/********************************************************************* 
** Author: Andrew Clos
** Date: 05/06/2019
** Description: Assignment 6a (HalfOpenCylinder.hpp) This class 
**              declaration provides the framework for an object
**              respresenting a half open cylinder.  Two data
**              members for height and radius are established. 
**              It also contains a default constructor plus a function 
**              to return the surface area of the cylinder.
*********************************************************************/ 


#ifndef HALFOPENCYLINDER_HPP    //include guards
#define HALFOPENCYLINDER_HPP

//  Defines the interface of the HalfOpenCylinder class
 class HalfOpenCylinder
{
   private:            //data members kept private
      double height;
      double radius;
   public:            
      HalfOpenCylinder();     //default constructor 
      HalfOpenCylinder(double, double);  //constructor declared
      void setHeight(double);
      void setRadius(double);
      double surfaceArea();
};
#endif
