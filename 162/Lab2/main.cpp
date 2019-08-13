/***************************************************************************
**   Program Name: Lab 2 (main.cpp)
**   Author: Andrew Clos
**   Date: 7/2/2019
**   Description: This program illustrates use of the file input and output.
**                First, the user is prompted to enter a file name (in this 
**                the default "file_fun.txt" was used. Using ifstream and
**                ofstream variables, the file is opened and lines are read
**                using the getline command.  A function called count_letters
**                reads the line in to a string and then steps through that
**                string to make a count of the occurance of each letter a-z.
**                These occurances are stored in an array of integers that is
**                pointed to by this function.  Finally, a second function 
**                called output_letters asks the user to enter a file name
**                and then saves the occurance array to this new file.  Input
**                validation on file name and string size is utilized.
****************************************************************************/

#include<iostream>
#include<string>
#include<fstream>

#include "InputValidate.hpp"

const int MAXFILENAME = 500;   //maximum file name length.
const int ALPHABETSIZE = 26;

void count_letters(std::ifstream&, int*);
void output_letters(std::ofstream&, int*);

int main()
{
	int letters[26] = { 0 },
		loopCounter = 0;
	
	InputValidate tester1;
	std::ifstream ifs;
	std::ofstream ofs;

	do  //do-while used to stay in loop if user entry of file name fails.
	{
		std::cout << "Please enter your input file name: ";
		// new string initialized with a call to Input Validation
		std::string inputFileName = tester1.strValidate(true, MAXFILENAME);
		ifs.open(inputFileName);
		if (ifs.fail()) //if an invalid filename is entered, the user is asked to try the entry again.
		{ 
			std::cout << "File opening failed, retry." << std::endl;
		}
	} while (ifs.fail());
	
	while (!ifs.eof())
	{
		loopCounter++;  //loop counter so the user/tester knows how many paragraphs are found.
		count_letters(ifs, letters); 
		std::cout << "Output File #" << loopCounter << "." << std::endl;
		output_letters(ofs, letters);
	}
	ifs.close();  //close file when finished with it.
    return 0;
}
/***************************************************************************
**   Description: This function reads a "paragraph" from the file it is 
**                passed.  It defines the end of a paragraph as reaching a
**                '/n' character.  The file then stores this paragraph in a
**                string and converts any uppercase characters to lower case.
**                Then, the pointer to array of integers is populated with the
**                frequency of occurance of each letter character.
****************************************************************************/
void count_letters(std::ifstream& inputFile, int* letterFreq)
{
	std::string read = " ";

	std::getline(inputFile, read, '\n'); //read the line until a '\n' is found.

	for (unsigned int i = 0; i < read.length(); i++)  //step through each character in the string.
	{
		if (read[i] >= 65 && read[i] <= 90)  //convert upper to lower case.
		{
			read[i] = read[i] + 32;  //Ascii code difference between upper and lower case
		}
		if (read[i] >= 97 && read[i] <= 122)  //only count lower case alphabetic characters
		{
			letterFreq[read[i] - 97] = letterFreq[read[i] - 97] + 1;
		}	
	}
}
/***************************************************************************
**   Description: This function prompts the user to enter the name of the
**                output file, performs a call to Input Validation.  It makes
**                use of a while loop to prompt for re-entry if the file
**                fails to open.  The function steps through the array of 
**                integers that it points to and streams these values to the
**                user specified file. The file is closed when finishd.
****************************************************************************/
void output_letters(std::ofstream& outputFile, int* letterFreq)
{
	InputValidate tester2;
	char filler = ' ';

	std::cout << "Please enter the output filename: ";
	std::string outputFileName = tester2.strValidate(true, MAXFILENAME);

	outputFile.open(outputFileName);
	//make sure the new file has opened successfully. 
	while (outputFile.fail())
	{
		std::cout << "File opening failed, please enter your filename again:";
		outputFileName = tester2.strValidate(true, MAXFILENAME);
		outputFile.open(outputFileName);
	}
	//populate the file with values from the array of integers
	for (int i = 0; i < ALPHABETSIZE; i++)
	{
		filler = i + 97;  //97 is the ASCII code for 'a'
		outputFile << filler << ": " << letterFreq[i] << '\n';
		letterFreq[i] = 0;
	}
	outputFile.close();
}
