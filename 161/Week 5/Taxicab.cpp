/************************************************************************** 
** Author: Andrew Clos
** Date: 04/30/2019
** Description: Assignment 5b (Taxicab.cpp) This function definition 
**              sets the default X, Y and distance values for a Taxicab 
**              to zero and contains a constructor for alternate starting
**              X and Y values (but initial distance is still set to 0) 
**              There are functions to get the X and Y coordinates as well
**              as total distance traveled.  There are two additional 
**    functions that handle movement of the taxi and count 
**    its distance traveled.
**************************************************************************/


#include <iostream>
#include "Taxicab.hpp"

/********************************************************************* 
** Description: Default constructor sets data members to 0.
*********************************************************************/
Taxicab::Taxicab()
{
   xCoord = 0;
   yCoord = 0;
   totalDistance = 0;
}

/********************************************************************* 
** Description: Constructor to initialize total distance to 0 and 
**              set start coordinates to values (provided).
*********************************************************************/
Taxicab::Taxicab(int startingX, int startingY)
{
   xCoord = startingX;
   yCoord = startingY;
   totalDistance = 0;
}


/********************************************************************* 
** Description: Gets the X coordinate.
*********************************************************************/
int Taxicab::getXCoord()
{
   return xCoord;
}

/********************************************************************* 
** Description: Gets the Y coordinate.
*********************************************************************/
int Taxicab::getYCoord()
{
   return yCoord;
}

/********************************************************************* 
** Description: gets distance traveled.
*********************************************************************/
int Taxicab::getDistanceTraveled()
{
   return totalDistance;
}

/*********************************************************************  
** Description: Moves the cab in the X direction, counts distance.
**              If-else statement is to make sure totalDistance goes
**              up no matter which direction the cab moved.
*********************************************************************/ 
void Taxicab::moveX(int travelX)
{
   int tempX = 0;
   xCoord = xCoord + travelX;
   if(travelX < 0)
   {
      totalDistance = totalDistance + (travelX * -1);
   }
   else
   {  
      totalDistance = totalDistance + travelX;
   }
}

/********************************************************************* 
** Description: Moves the cab in the Y direction, counts distance.
**              If-else statement is to make sure totalDistance goes
**              up no matter which direction the cab moved.
*********************************************************************/ 
void Taxicab::moveY(int travelY)
{
   int tempY = 0;
   yCoord = yCoord + travelY;
   if(travelY < 0)
   {
      totalDistance = totalDistance + (travelY * -1);
   }
   else
   {  
      totalDistance = totalDistance + travelY;
   }
}
