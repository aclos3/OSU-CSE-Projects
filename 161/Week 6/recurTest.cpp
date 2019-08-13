

#include <iostream>



int main()
{
	int x = 3,
		y = 4;
	std::cout << multiply(x, y) << std::endl;
	return 0;
}

int multiply(int var1, int var2)
{
	if (var2 == 0)
	{
		return 0;
	}
	else
	{
		return (var1 + multiply(var2 - 1));
	}
}

