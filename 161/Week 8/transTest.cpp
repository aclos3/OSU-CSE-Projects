#include<iostream>
using std::cout;
using std::endl;

void transformArray(int* &arrayInts, int arraySize);

int main()
{

	int* myArray = new int[3];
	myArray[0] = 4;
	myArray[1] = 2;
	myArray[2] = 5;

	transformArray(myArray, 3);

	for (int i = 0; i < 6; i++)
	{
	   cout << myArray[i] << endl;
	}
	delete []myArray;
}