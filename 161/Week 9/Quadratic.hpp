/*************************************************************************** 
** Author: Andrew Clos
** Date: 05/22/2019
** Description: Assignment 9 (Quadratic.hpp) This class declaration provides 
**              the framework for an object called a Quadratic. Three double
**              data members for a, b and c are established. It also contains 
**              a default constructor to initialize each coefficent to 1.0. 
**              and a constructor that initializes data members by parameter.
**              Additionally, it include set methods for the coefficients, 
**			    and two methods to calculate and return portions of the 
**              quadratic equation.
***************************************************************************/

#ifndef QUADRATIC_HPP
#define QUADRATIC_HPP

//  Defines the interface of the Quadratic class
class Quadratic
{
   private:            //data members kept private
      double a;
	  double b;
	  double c;
   public:            
      Quadratic();     //default constructor 
      Quadratic(double firstA, double firstB, double firstC);  //constructor declared
      void setA(double);
	  void setB(double);
	  void setC(double);
      double valueFor(double);
      double calcDiscriminant();
};
#endif

