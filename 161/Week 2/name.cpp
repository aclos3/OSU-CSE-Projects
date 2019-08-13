//************************************************************************
//**   Just some book practice to get muscle memory down.
//**********************************************************************\\

#include <iostream>
#include <string>
using std::cout;  //using these individual functions within namespace
using std::endl;
using std::string;


int main()
{
   int age = 33;                    //Initializes age as 33
   double weight = 210.245;         //Initializes weight as 210.245
   string name = "My name is Andrew Clos",  //Initializes name 
   address = "522 SW Smith Ct, Newport, OR, 97365", 
   phoneNumber = "360-909-7767";
   int result;
   int a = 5, b = 12;
   double x = 3.4, z = 9.1;

   cout << name << endl;              //outputs name to console
   cout << address  << endl;           //outputs address to console
   cout << phoneNumber << endl;
   cout << "My age is " << age << " and my weight is: " << weight << endl;
 
   cout << b / a << endl;
   cout << x * a << endl;
   cout << static_cast<double>(b / a) << endl;
   cout << static_cast<double>(b) / a << endl;



   return 0;
}
