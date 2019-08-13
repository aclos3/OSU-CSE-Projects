#include<iostream>
#include<vector>

#include "Quadratic.hpp"

double meanValueFor(std::vector<Quadratic*> quads, double forX);

int main()
{
	Quadratic test(2.1, 2.1, 2.1);
	std::cout << "Value For: " << test.valueFor(4) << std::endl;
	std::cout << "Discriminant: " << test.calcDiscriminant() << std::endl;

	Quadratic q1(2.1, 2.1, 2.1);
	Quadratic q2(2.1, 2.1, 2.1);
	std::vector<Quadratic*> vec;
	vec.push_back(&q1);
	vec.push_back(&q2);
	double result = meanValueFor(vec, 1.0);
	std::cout << "meanValueFor returned: " << result << std::endl;
}