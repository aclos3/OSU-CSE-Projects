/*************************************************************************** 
** Author: Andrew Clos
** Date: 04/30/2019
** Description: Assignment 5b (Taxicab.hpp) This class declaration provides 
**              the framework for an object called a Taxicab. Three data
**              members for X, Y and totalDistance are established. 
**              It also contains a declaration for a default constructor, 
**              3 'get' and 2 void (movement) functions
***************************************************************************/

#ifndef TAXICAB_HPP
#define TAXICAB_HPP

//  Defines the interface of the Taxicab class
class Taxicab
{
   private:            //data members kept private
      int xCoord;
      int yCoord;
      int totalDistance;
   public:            
      Taxicab();     //default constructor 
      Taxicab(int, int);  //constructor declared
      int getXCoord();
      int getYCoord();
      int getDistanceTraveled();
      void moveX(int);
      void moveY(int);
};
#endif

