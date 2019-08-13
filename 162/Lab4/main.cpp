/***************************************************************************
**   Program Name: Lab 4 (main.cpp)
**   Author: Andrew Clos
**   Date: 7/19/2019
**   Description: This is the main method where the new objects for University
**				  Buildings and People are created.  The main menu is present
**				  and vectors are filled with with pointers to Person or 
**				  Building objects.  I have implmented the extra credit and 
**				  have included a file called "in2.txt" that works for menu
**				  option 5 (to read from a saved file).
****************************************************************************/

#include<iostream>
#include<vector>
#include <string>
#include<fstream>
#include <sstream>
#include "InputValidate.hpp"
#include "Person.hpp"
#include "Instructor.hpp"
#include "Student.hpp"
#include "Building.hpp"
#include "University.hpp"

const char YESLIMITS = 'y';

int main()
{   
	University OregonState;
	std::vector<Person*> people;
	std::vector<Building*> buildings;

	int menuChoice = 0;
	InputValidate mainMenuCheck,
				  subMenu;

	//manually instantiate and add to vector: 2 students, 1 instructor and 3 buildings
	people.push_back(new Student("Andrew", 34, 3.6));
	people.push_back(new Student("Jenna", 29, 4.0));
	people.push_back(new Instructor("Bob", 32, 2.6));
	buildings.push_back(new Building("Reser Stadium", 1000000, "700 SW 26th St."));
	buildings.push_back(new Building("Memorial Union", 22500, "2501 SW Jefferson Way"));
	buildings.push_back(new Building("Physical Plant Heating Plant", 4451, "501 Benton Pl."));

	//add manually instantiated buildings and people to the University
	for (unsigned int i = 0; i < people.size(); i++)
	{
		OregonState.addPerson(people[i]);
	}
	for (unsigned int i = 0; i < buildings.size(); i++)
	{
		OregonState.addBuilding(buildings[i]);
	}
	//greet user
	std::cout << "Welcome to the OSU Information System." << std::endl;
	std::cout << "Andrew Clos, CS162-400, Lab 4." << std::endl;
	
	//display menu options
	//I elected to attempt the extra credit and have therefore added menu options 4, 5, and 6
	//which (4) save a file with the building and personnel information, (5) open a file which
	//contains personnel and building information and add that data to the vectors. (6) add a
	//person in run-time.  
	//NOTE: I have included a text file called in2.txt that functions for file reading (5).
	while (menuChoice != 7)
	{
		std::cout << "(1) Print information about all buildings." << std::endl;
		std::cout << "(2) Print information on all people at the University." << std::endl;
		std::cout << "(3) Choose a person to do work." << std::endl;
		std::cout << "(4) Save Building and Personnel Info to File." << std::endl;
		std::cout << "(5) Read a saved Building and Personnel File." << std::endl;
		std::cout << "(6) Add a person to the university." << std::endl;
		std::cout << "(7) Exit." << std::endl;
		menuChoice = mainMenuCheck.intValidate(YESLIMITS, 1, 7);

		if (menuChoice == 1)
		{
			std::cout << OregonState.getName() << std::endl;
			OregonState.printBuildings();
			std::cout << "Total Number of Buildings: " << OregonState.getNumBuilds() << std::endl << std::endl;

		}
		else if (menuChoice == 2)
		{
			std::cout << OregonState.getName() << std::endl;
			OregonState.printPeople();
			std::cout << "Total Number of People: " << OregonState.getNumPeople() << std::endl << std::endl;
		}
		else if (menuChoice == 3)
		{
			std::cout << "Please enter the number that corresponds to the person you'd like to have work." << std::endl;
			OregonState.workPeople();
		}
		else if (menuChoice == 4)
		{
			InputValidate fileTest;
			std::ofstream ofs;

			std::cout << "Please enter the output filename: ";
			std::string outputFileName = fileTest.strValidate(true, 100);
			ofs.open(outputFileName);

			while (ofs.fail())
			{
				std::cout << "File opening failed, please enter your filename again:";
				outputFileName = fileTest.strValidate(true, 100);
				ofs.open(outputFileName);
			}

			for (unsigned int i = 0; i < people.size(); i++)
			{  //each value on its own line
				ofs << people[i]->getType() << std::endl << people[i]->getName() << std::endl << people[i]->getAge() << std::endl << people[i]->getGrade() << '\n';
			}
			for (unsigned int i = 0; i < buildings.size(); i++)
			{  //comma delimited (name,age,grade) on one line
				ofs << buildings[i]->getType() << std::endl << buildings[i]->getName() << std::endl << buildings[i]->getSize() << std::endl << buildings[i]->getAddress() << '\n';
			}
			ofs.close();
		}  //EXTRA CREDIT ATTEMPT: in2.txt file is included and works for file reading.
		else if (menuChoice == 5)
		{
			InputValidate inTest;
			std::ifstream ifs;
			std::string read = " ",
						snippet = " ";

			do  //do-while used to stay in loop if user entry of file name fails.
			{
				std::cout << "Please enter your input file name: ";
				std::string inputFileName = inTest.strValidate(true, 300);
				ifs.open(inputFileName);
				if (ifs.fail()) //if an invalid filename is entered, the user is asked to try the entry again.
				{
					std::cout << "File opening failed, retry." << std::endl;
				}
			} while (ifs.fail());

			while (!ifs.eof())
			{
				std::string type = " ",
							name = " ",
							address = " ";
				int ageOrSqFt = 0;
				double grade = 0.0;

				//each object is four lines of the file
				for (int i = 0; i < 4; i++)
				{
					std::getline(ifs, read, '\n');

					if (i == 0)
					{
						type = read;
					}
					else if (i == 1)
					{
						name = read;
					}
					else if (i == 2)
					{
						std::istringstream iss(read);
						iss >> ageOrSqFt;
					}  //I used ASCII codes b, s, i to indicate what type of information was being
					   //read by the file (building, student or instructor).
					else if (i == 3 && type[0] == 98)
					{
						address = read;
						buildings.push_back(new Building(name, ageOrSqFt, address));
						OregonState.addBuilding(buildings[buildings.size() - 1]);
					}
					else if (i == 3 && (type[0] == 105 || type[0] == 115))
					{
						std::istringstream iss(read);
						iss >> grade;
						if (type[0] == 115)
						{
							people.push_back(new Student(name, ageOrSqFt, grade));
							OregonState.addPerson(people[people.size() - 1]);
						}
						else if (type[0] == 105)
						{
							people.push_back(new Instructor(name, ageOrSqFt, grade));
							OregonState.addPerson(people[people.size() - 1]);
						}
					}
				}
			}
			ifs.close();
		}  //Extra credit attempt: to add instructors or students in real time.  
		else if (menuChoice == 6)
		{
			int choice = 0,
				newAge = 0;
			double newGrade = 0.0;
			std::string newName = " ";
			
			std::cout << "(1) Add Instructor." << std::endl;
			std::cout << "(2) Add Student." << std::endl;
			choice = subMenu.intValidate(YESLIMITS, 1, 2);
			if (choice == 1)
			{
				std::cout << "Please enter the name for your instructor: ";
				newName = subMenu.strValidate(true, 100);
				std::cout << std::endl << "Please enter the age of your instructor (integer years): ";
				newAge = subMenu.intValidate(YESLIMITS, 0, 150);
				std::cout << std::endl << "Please enter the rating for your instructor (0.0 to 5.0): ";
				newGrade = subMenu.doubleValidate(YESLIMITS, 0.0, 5.0);
				people.push_back(new Instructor(newName, newAge, newGrade));
				OregonState.addPerson(people[people.size() - 1]);

			}
			else if (choice == 2)
			{
				std::cout << "Please enter the name for your student: ";
				newName = subMenu.strValidate(true, 100);
				std::cout << std::endl << "Please enter the age of your student (integer years): ";
				newAge = subMenu.intValidate(YESLIMITS, 0, 150);
				std::cout << std::endl << "Please enter the GPA for your student (0.0 to 4.0): ";
				newGrade = subMenu.doubleValidate(YESLIMITS, 0.0, 4.0);
				people.push_back(new Student(newName, newAge, newGrade));
				OregonState.addPerson(people[people.size() - 1]);

			}
		}
	}
	//delete the hard coded buildings and persons
	for (unsigned int i = 0; i < people.size(); i++)
	{
		delete people[i];
	}
	for (unsigned int i = 0; i < buildings.size(); i++)
	{
		delete buildings[i];
	}
	return 0;
}
