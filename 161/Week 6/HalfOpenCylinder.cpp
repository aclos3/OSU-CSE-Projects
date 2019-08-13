/********************************************************************* 
** Author: Andrew Clos
** Date: 05/06/2019
** Description: Assignment 6a (HalfOpenCylinder.cpp) This function 
**              definition sets the default dimensions for a 
**              HalfOpenCylinder and then sets the dimensions to 
**              specified values if provided. There is one additional 
**              function that returns a double value for the surface
**              area of the cylinder.
*********************************************************************/ 

#include <iostream>
#include "HalfOpenCylinder.hpp"

const double PI = 3.14159;

/********************************************************************* 
** Description: Default constructor sets initial height to 10 and 
**              radius to 2.
*********************************************************************/

HalfOpenCylinder::HalfOpenCylinder()
{
   setHeight(10);
   setRadius(2);
}

/********************************************************************* 
** Description: Constructor for height and radius as doubles.
*********************************************************************/
HalfOpenCylinder::HalfOpenCylinder(double heightIn, double radiusIn)
{
   setHeight(heightIn);
   setRadius(radiusIn);
}

void HalfOpenCylinder::setHeight(double heightIn)
{
   height = heightIn;
}

void HalfOpenCylinder::setRadius(double radiusIn)
{
   radius = radiusIn;
}

/********************************************************************* 
** Description: Calculates surface area of open cylinder and returns it.
*********************************************************************/ 

double HalfOpenCylinder::surfaceArea()
{
   return ((2 * height * radius * PI) + (radius * radius * PI));
}
