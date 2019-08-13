#include<iostream>
#include "HalfOpenCylinder.hpp"


int main()
{
	HalfOpenCylinder hoc1;
	//Vase vase1(hoc1, 0.12);
	//cout << vase1.totalCost() << endl;
	HalfOpenCylinder hoc2(80.4, 13);
	std::cout << "The surface area of the default is: " << hoc1.surfaceArea << std::endl;
	std::cout << "The surface area of hoc2 is: " << hoc2.surfaceArea << std::endl;
	//Vase vase2(hoc2, 0.2);
	// std::boolalpha prints Boolean values as "true" or "false" instead of an integer value
	//cout << std::boolalpha << vase1.costsMoreThan(vase2) << endl;
   
   return 0;

}
