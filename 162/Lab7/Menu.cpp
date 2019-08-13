/***************************************************************************
**   Program Name: Lab 7 (Menu.cpp)
**   Author: Andrew Clos
**   Date: 8/4/2019
**   Description: The Menu class is what first greets the user and from this
**                class, menu options are presented. There are two main 
**				  private functions, 'runQueue' demonstrates the queue STL 
**				  function and 'palindrone' demonstrates the stack STL
**				  function.  Finally, there is a random number function that
**				  generates a random integer between a min and max range.
****************************************************************************/

#include<iostream>
#include<string>
#include<random>
#include<queue>
#include<stack>
#include "Menu.hpp"
#include "InputValidate.hpp"


/*******************************************************************************
**   Description: This function welcomes the user and gives them the option
**                to begin the simulation or quit.  This portion was kept 
**                separate from the paramMenu user data collection so that it
**                can be called once when the program is started, but doesn't
**                need to be repeated if the user elects to play again.  The
**                function returns a bool to the caller true=begin, false=quit.
*******************************************************************************/
bool Menu::mainMenu()
{
	int menuChoice = 0,
		userRounds = 0,
		addPercent = 0,
		removePercent = 0;
	std::string userStr = " ";
	bool active = true;
	InputValidate tester;

	//new object of DoubleLinkedList created and used throughout the program.
	//DoubleLinkedList* userList = new DoubleLinkedList;

	std::cout << "Welcome to a Double Linked List!" << std::endl;
	std::cout << "Andrew Clos, CS162-400, Lab 7." << std::endl << std::endl;

	while (active)
	{
		std::cout << "Please Make Your Choice From the Options Below:" << std::endl;
		std::cout << "(1) Test the Buffer (Queue)" << std::endl;
		std::cout << "(2) Create a Palindrone." << std::endl;
		std::cout << "(3) Quit." << std::endl;

		menuChoice = tester.intValidate(YESLIMITS, MINMENU, MAXMENU);

		//buffer
		if (menuChoice == 1)
		{
			//start a new queue
		

			//collect user data
			std::cout << "Please enter the number of rounds you'd like to see simulated (integer between " << MINROUNDS << " and " << MAXROUNDS << "): ";
			userRounds = tester.intValidate(YESLIMITS, MINROUNDS, MAXROUNDS);
			std::cout << "Please enter the percent chance for a random number to be added to the end of the buffer, " << std::endl << "an (integer between " << MINPERCENT << " and " << MAXPERCENT << ") : ";
			addPercent = tester.intValidate(YESLIMITS, MINPERCENT, MAXPERCENT);
			std::cout << "Please enter the percent chance for a random number to removed from the front of the buffer, " << std::endl << "an (integer between " << MINPERCENT << " and " << MAXPERCENT << "): ";
			removePercent = tester.intValidate(YESLIMITS, MINPERCENT, MAXPERCENT);
			runQueue(userRounds, addPercent, removePercent);
		}
		//palindrone
		else if (menuChoice == 2)
		{
			std::cout << "Please enter a string and i'll turn it in to a palindrone: ";
			userStr = tester.strValidate(true, MAXSTRLEN);
			palindrome(userStr);
		}

		//quit
		else if (menuChoice == 3)
		{
			active = false;
		}
	}
	return active;
}

/*******************************************************************************
**   Description: This function utilizes the queue function from STL, and 
**				  demonstrates its push, pop, and front functions by adding and
**				  removing random integers from it.  The contents of the queue
**				  are displayed each round, along with the length and average 
**				  length of the queue. This function actually creates a second
**				  identical queue in order to restore the original queue after
**				  printing the values, since values are removed from the queue
**				  when printed.
**				  source cited for help with this section: https://www.geeksforgeeks.org/queue-cpp-stl/
*******************************************************************************/
void Menu::runQueue(int rds, int addPer, int remPer)
{
	//the queue we'll use to display
	std::queue<int> usrQueue;

	//a temp holder queue for copying the contents before and after printing
	std::queue<int> tempQueue;
	int N = 0,
		randAdd = 0,
		randRem = 0,
		queueSize = 0,
		queueSum = 0;
	double queueAvg[2] = { 0, 0 };

	//***Begin a round
	for (int roundNum = 1; roundNum <= rds; roundNum++)
	{
//1. Generate random numbers (1-1000 and 1-100)

		N = getRandom(MINPERCENT, APPENDNUM);
		randAdd = getRandom(MINPERCENT, PERRAND);
		randRem = getRandom(MINPERCENT, PERRAND);

		//make space between rounds, announce round number
		std::cout << std::endl << "Round Number " << roundNum << " results: " << std::endl;

//2. Append number 

		if (addPer >= randAdd)
		{
			usrQueue.push(N);
			tempQueue.push(N);
			std::cout << "Number added to end of buffer." << std::endl;
		}
		
//3. Remove number

		if (remPer >= randRem)
		{
			if (usrQueue.empty())
			{
				std::cout << "We tried to remove a number from the queue, but there are none to remove." << std::endl;
			}
			else
			{
				usrQueue.front();
				usrQueue.pop();
				tempQueue.front();
				tempQueue.pop();
				std::cout << "Number removed from front of buffer." << std::endl;
			}
		}
		//set queueSize after add and remove phases have completed.
		queueSize = usrQueue.size();
		
//4. Output values in the buffer, then length

		std::cout << "Here is the queue: " << std::endl;

		for(int i = 0; i < queueSize; i++)
		{
			//display the value in the queue
			std::cout << usrQueue.front() << " ";

			//add extra spaces depending on number of digits in N (for column alignment)
			if (usrQueue.front() < 1000)
			{
				std::wcout << " ";
			}
			if (usrQueue.front() < 100)
			{
				std::wcout << " ";
			}
			if (usrQueue.front() < 10)
			{
				std::wcout << " ";
			}
			
			//add return line every 10 numbers
			if ((i + 1) % 10 == 0)
			{
				std::cout << std::endl;
			}

			//add it to the sum
			queueSum = queueSum + usrQueue.front();

			//move current value to the temp queue
			tempQueue.push(usrQueue.front());
			//remove it from the queue
			usrQueue.pop();
		}
		std::cout << std::endl;
		std::cout << "The length of the buffer is: " << queueSize << std::endl;

		//restore the usrQueue with values from tempQueue
		for (int i = 0; i < queueSize; i++)
		{
			usrQueue.push(tempQueue.front());

			tempQueue.pop();
		}

//5. Output the average buffer length
		//first round: set average length to the size after the first round
		if (roundNum == 1)
		{
			queueAvg[1] = queueSize;
			std::cout << "The average queue length is: " << queueAvg[1] << std::endl;
		}
		else
		{
			//calculate average using an array to store ALi and ALi-1
			queueAvg[1] = (queueAvg[0] * (roundNum - 1) + queueSize) / static_cast<double>(roundNum);

			std::cout << "The average queue length is: " << queueAvg[1] << std::endl;

			//increment ALi to ALi-1
			queueAvg[0] = queueAvg[1];
		}
	}
}

/*******************************************************************************
**   Description: This function takes a string from the caller and turns it in to
**				  a palindrone by printing the string, then the string (minus the
**				  last character in reverse order. 
**				  Ex. "Andrew" => "AndrewerdnA"
**				  source cited for help with this portion: https://www.geeksforgeeks.org/stack-in-cpp-stl/
*******************************************************************************/
void Menu::palindrome(std::string usrStr)
{
	std::stack<char> usrStack;
	int stackSize = 0;

	//first repeat the original string
	std::cout << "Your string was: " << usrStr << std::endl;
	std::cout << "Now Palindronize!" << std::endl;

	//pull a character off the string one at a time and push it to the user stack.
	//then print that character (forward print)
	for (unsigned int i = 0; i < usrStr.length(); i++)
	{
		usrStack.push(usrStr[i]);
		std::cout << usrStack.top();
	}

	//store original stack size
	stackSize = usrStack.size();
	//now cycle through, deleting the top char of the stack and then print the new top (reverse print).
	for (int i = 0; i < stackSize; i++)
	{	
		//print the new top character
		std::cout << usrStack.top();
		//remove top character
		usrStack.pop();
	}
	std::cout << std::endl;
}

/*******************************************************************************
**   Description: This function returns a random integer between two integers
**			      passed by the caller.  The first integer represents the lower
**				  limit and the second integer represents the upper limit.
*******************************************************************************/
int Menu::getRandom(int min, int outOf)
{
	if (outOf < min)
	{
		std::cout << "Error! Upper range limit is below the lower range limit. " << std::endl;
		return -9999;
	}
	else
	{
		std::random_device randDev;
		std::mt19937 randSeed(randDev());
		std::uniform_int_distribution<> randomNum(min, outOf);
		return randomNum(randSeed);
	}
}

