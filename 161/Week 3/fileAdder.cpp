/******************************************************************** 
** Author: Andrew Clos
** Date: 04/12/2019
** Description: Assignment 3b (fileAdder). This program will prompt
**              the user to enter a filename and then to open that
**              file if it is present.  If present, it will read
**              integer values from the file, sum them and output
**              that sum in to a new file called sum.txt.
*********************************************************************/ 

#include <iostream>
#include <fstream>
#include <string>

using std::cout;             //using six different std names.
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

int main () 
{
   string userFileName;     //declare/initialize variables
   ifstream inputFile;
   ofstream outputFile;
   int fileInt = 0, sum = 0;

   cout << "Please enter your filename." << endl;
   cin >> userFileName;            //user specifies file
   inputFile.open(userFileName);   //opens file 
  
   if (inputFile)              //checks to see if file is available
   {
      while (inputFile >> fileInt)   //a loop will run each time a value is read.
      {
         sum = sum + fileInt;      //each new value read is added to sum. 
      }
      inputFile.close();     //close the inputFile
      outputFile.open("sum.txt");  //open a file called sum.txt
      outputFile << sum;      //sum (integer) is written to outputFile
      outputFile.close();   //close the outputFile
      cout << "result written to sum.txt" << endl; 
   }
   else               //if file not available, notify user 
   {
      cout << "could not access file" << endl;
   }
   return 0;
}
