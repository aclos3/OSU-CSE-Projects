/************************************************************************** 
** Author: Andrew Clos
** Date: 05/22/2019
** Description: Assignment 9 (Quadratic.cpp) This function definition 
**              sets the default a, b and c values for a Quadratic 
**              to 1.0 and contains a constructor to initialize these data
**              members to parameters.  There are set methods for each  
**              coefficient and two other methods that calculate and return
**              parts of the quadratic formula.
**************************************************************************/

#include "Quadratic.hpp"

/********************************************************************* 
** Description: Default constructor sets all data members to 1.0.
*********************************************************************/
Quadratic::Quadratic()
{
   a = 1.0;
   b = 1.0; 
   c = 1.0; 
}

/********************************************************************* 
** Description: Constructor to initialize coefficients to parameter 
**              values by calling the "set" methods.  These params will
**              be doubles sent by the client/testing program. 
*********************************************************************/
Quadratic::Quadratic(double firstA, double firstB, double firstC)
{
	setA(firstA);
	setB(firstB); 
	setC(firstC);
}

void Quadratic::setA(double firstA)
{
	a = firstA;
}

void Quadratic::setB(double firstB)
{
	b = firstB;
}

void Quadratic::setC(double firstC)
{
	c = firstC;
}
/*********************************************************************  
** Description: This function recieves a value for 'x' from the calling
**              function and uses that value, along with the coefficients
**              a, b and c to caluclate and return "ax^2 + bx + c"
*********************************************************************/ 
double Quadratic::valueFor(double valueX)
{
	double quad = 0;
	quad = (a * valueX * valueX) + (b * valueX) + c;

	return quad;
}

/********************************************************************* 
** Description: This function recieves no value and returns the 
**              discriminant value based on the coefficients a, b and c.
**			    The equation for the discriminant is "b^2 - 4ac"
*********************************************************************/ 
double Quadratic::calcDiscriminant()
{
	double disc = 0;
	disc = (b * b) - (4 * a * c);

	return disc;
}
