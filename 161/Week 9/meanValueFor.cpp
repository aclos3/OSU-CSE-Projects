/**************************************************************************
** Author: Andrew Clos
** Date: 05/22/2019
** Description: Assignment 9 (meanValueFor.cpp) This function definition
**              takes a vector of pointers to Quadratics and a value to use
**              for x.  It returns the average of all of the Quadratics in
**              the vector.
**************************************************************************/

#include<vector>

#include "Quadratic.hpp"

/*********************************************************************
** Description: This function uses the vector of pointers to Quadratics
**              as well as the parameter for a value of x.  It uses a 
**              for-loop, bounded by the size of the vector to call the
**              valueFor function of the Quadratic class and sum each
**              of these vectors in the array.  Then it divides the sum
**			    by the size of the vector and returns this as the average.
*********************************************************************/

double meanValueFor(std::vector<Quadratic*> quads, double forX)
{
	double valFors = 0,
		   meanVal = 0;

	for (int i = 0; i < quads.size(); i++)  //uses vector size as upper bound
	{
		valFors += quads[i]->valueFor(forX);  //calls method from Quadratic, sums valueFor
	}
	meanVal = valFors / quads.size();  //computes average of valFors
	return meanVal;
}