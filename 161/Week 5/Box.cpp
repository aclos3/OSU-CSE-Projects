/********************************************************************* 
** Author: Andrew Clos
** Date: 04/30/2019
** Description: Assignment 5a (Box.cpp) This function definition 
**              sets the default dimensions for a Box and then sets
**              the dimensions to specified values if provided. There
**              are two additional functions that return double values 
**              for the surface area and volume of the Box.
*********************************************************************/ 

#include <iostream>
#include "Box.hpp"

/********************************************************************* 
** Description: Default constructor sets initial dimensions to 1.
*********************************************************************/

Box::Box()
{
   setHeight(1);
   setWidth(1);
   setLength(1);
}

/********************************************************************* 
** Description: Constructor for height, width, and lengths as doubles.
*********************************************************************/
Box::Box(double heightIn, double widthIn, double lengthIn)
{
   setHeight(heightIn);
   setWidth(widthIn);
   setLength(lengthIn);
}

/********************************************************************* 
** Description: Sets height of Box object.
*********************************************************************/

void Box::setHeight(double heightIn)
{
   height = heightIn;
}

/********************************************************************* 
** Description: Sets width of Box object.
*********************************************************************/

void Box::setWidth(double widthIn)
{
   width = widthIn;
}

/********************************************************************* 
** Description: Sets length of Box object.
*********************************************************************/

void Box::setLength(double lengthIn)
{
   length = lengthIn;
}

/********************************************************************* 
** Description: Calculates volume of Box object and returns it.
*********************************************************************/ 

double Box::calcVolume()
{
   return height * width * length;
}

/********************************************************************* 
** Description: Calculates surface area of Box object and returns it.
*********************************************************************/ 

double Box::calcSurfaceArea()
{
   return (height * length * 2) + (height * width * 2) + (length * width * 2);
}

