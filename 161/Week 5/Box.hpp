
/********************************************************************* 
** Author: Andrew Clos
** Date: 04/30/2019
** Description: Assignment 5a (Box.hpp) This class declaration provides 
**              the framework for an object called a Box.  Three data
**              members for height, width and length are established. 
**              It also contains a default constructor plus 3 'set' 
**              and 2 'calc' functions (Surface area and volume).
*********************************************************************/ 


#ifndef BOX_HPP    //include guards
#define BOX_HPP

//  Defines the interface of the Box class
class Box
{
   private:            //data members kept private
      double height;
      double width;
      double length;
   public:            
      Box();     //default constructor 
      Box(double, double, double);  //constructor declared
      void setHeight(double);
      void setWidth(double);
      void setLength(double);
      double calcVolume();
      double calcSurfaceArea();
};
#endif

