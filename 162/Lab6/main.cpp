/***************************************************************************
**   Program Name: Lab 6 (main.cpp)
**   Author: Andrew Clos
**   Date: 7/30/2019
**   Description: The main method includes 10 menu options to perform each
**				  function per the project specs, including both extra
**				  credit attempts and the option to quit. User menu selection
**				  is gathered here and calls are made to Input Validate's 
**			      integer validation function.  The menu stays 'alive' via
**				  a while-loop and is exited when the user enters a 0.
****************************************************************************/

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include "InputValidate.hpp"
#include "Node.hpp"
#include "DoubleLinkedList.hpp"

const int MINMENU = 0;
const int MAXMENU = 9;
const int MINUSERINT = -32768;
const int MAXUSERINT = 32767;
const char YESLIMITS = 'y';
const std::string FILENAME = "in.txt";

int main()
{  
	int menuChoice = 0,
		userInt = 0;
	bool active = true;
	InputValidate tester;
	//new object of DoubleLinkedList created and used throughout the program.
	DoubleLinkedList* userList = new DoubleLinkedList;

	std::cout << "Welcome to a Double Linked List!" << std::endl;
	std::cout << "Andrew Clos, CS162-400, Lab 6." << std::endl << std::endl;
	std::cout << "***EC1: I attempted the extra credit by adding options to return the head or tail value (see menu 7 and 8)." << std::endl;
	std::cout << "***EC2: I attempted the file read extra credit and have included a file named 'in.txt' that contains 10 space-delimited integers." << std::endl;

	while (active)
	{
		std::cout << "Here are some functions for working with a Double Linked List." << std::endl;
		std::cout << "(1) Add new Node to head." << std::endl;
		std::cout << "(2) Add new Node to tail." << std::endl;
		std::cout << "(3) Delete the first Node from the list." << std::endl;
		std::cout << "(4) Delete the last Node from the list." << std::endl;
		std::cout << "(5) Traverse (print) the list recursively (in reverse)." << std::endl;
		std::cout << "(6) Traverse (print) the list normally." << std::endl;
		std::cout << "(7) EC1*** Print the value of the Node the head is poiting to." << std::endl;
		std::cout << "(8) EC1*** Print the value of the Node the tail is poiting to." << std::endl;
		std::cout << "(9) EC2*** Read values from a file (in.txt is automatically read)." << std::endl;
		std::cout << "(0) Quit." << std::endl;
		menuChoice = tester.intValidate(YESLIMITS, MINMENU, MAXMENU);

		//add at head
		if (menuChoice == 1)
		{
			std::cout << "Please enter an integer that you'd like to add to the head of the list: ";
			userInt = tester.intValidate(YESLIMITS, MINUSERINT, MAXUSERINT);
			userList->addHead(userInt);
			userList->printForward();
		}
		//add at tail
		else if (menuChoice == 2)
		{
			std::cout << "Please enter an integer that you'd like to add to the tail of the list: ";
			userInt = tester.intValidate(YESLIMITS, MINUSERINT, MAXUSERINT);
			userList->addTail(userInt);
			userList->printForward();
		}
		//delete from Head
		else if (menuChoice == 3)
		{
			if (userList->checkForNulls() == 0)
			{
				userList->deleteFirst();
				userList->printForward();
			}
			else if (userList->checkForNulls() == 3)
			{
				std::cout << "Head and Tail are set to null, there is nothing to delete." << std::endl;
			}
			else if (userList->checkForNulls() == 1 || userList->checkForNulls() == 2)
			{
				std::cout << "An error has occurred. Head and Tail have null mismatch." << std::endl;
			}
		}
		//delete from Tail
		else if (menuChoice == 4)
		{
			if (userList->checkForNulls() == 0)
			{
				userList->deleteLast();
				userList->printForward();
			}
			else if (userList->checkForNulls() == 3)
			{
				std::cout << "Head and Tail are set to null, there is nothing to delete." << std::endl;
			}
			else if (userList->checkForNulls() == 1 || userList->checkForNulls() == 2)
			{
				std::cout << "An error has occurred. Head and Tail have null mismatch." << std::endl;
			}
		}
		//Print in reverse
		else if (menuChoice == 5)
		{
			userList->printReverse();
		}
		//Print forward
		else if (menuChoice == 6)
		{
			userList->printForward();
		}
		//print the head node value
		else if (menuChoice == 7)
		{
			userList->printHeadVal();
		}
		//print the tail node value
		else if (menuChoice == 8)
		{
			userList->printTailVal();
		}
		else if (menuChoice == 9)
		{
			std::ifstream ifs;
			std::string fileNum = " ";
			int valToEnter = 0;

			std::cout << "Now reading text file(" << FILENAME << ")..." << std::endl;
			//open in.txt
			ifs.open(FILENAME);
			
			if (ifs.fail())  //warn if there is a failure
			{
				std::cout << "File opening failed, abort." << std::endl;
			}
			else
			{  //in loop until end of file
				while (!ifs.eof())
				{   //getline with ' ' (space) delimiter
					std::getline(ifs, fileNum, ' ');
					//string stream in to integers
					std::istringstream(fileNum) >> valToEnter;

					//place integer in to head Node of list
					userList->addHead(valToEnter);
				}
				userList->printForward();
			}
		}
		//quit
		else if (menuChoice == 0)
		{
			active = false;
		}
	}

	delete userList;

	return 0;
}


