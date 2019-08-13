/***************************************************************************
**   Program Name: Project 2 Zoo Tycoon (Zoo.cpp)
**   Author: Andrew Clos
**   Date: 7/20/2019
**   Description: This Class runs a game called Zoo Tycoon.  It begins with
**				  the main menu providing the user with a introduction and
**				  prompting them for input for the game's parameters. After
**				  initial data is collected, the game cycles through the turns
**				  call helper functions to carry out the flow of the game.
****************************************************************************/

#include<iostream>
#include<iomanip>
#include<random>
#include<string>
#include "Zoo.hpp"
#include "InputValidate.hpp"

//constants for min and max game parameters that aren't to be changed by the user.
const char YESLIMITS = 'y';
const int	MININITBUY = 1;
const int 	MAXINITBUY = 2;
const int	MAXANIMALNAME = 100;
const int	MINBABY = 1;
const int	MAXBABY = 10;
const int	MINPAY = 1;
const int	MAXPAY = 40;
const int	OFAGE = 3;
const int	INITARRAY = 10;
const double	MINCOST = 1.00;
const double	MAXCOST = 20000.00;
const double INITCASH = 100000.00;
const double	MINFOOD = 1.00;
const double	MAXFOOD = 100.00;

Zoo::Zoo()
{
	setCashOnHand(INITCASH);
	setTigs(0);
	setPengs(0);
	setTurts(0);
	setUserAn(0);
	setNumSpecies(3);
	setTigArray(INITARRAY);
	setPenArray(INITARRAY);
	setTurArray(INITARRAY);
	setUserAnArray(INITARRAY);
	tigArr = new Tiger*[INITARRAY];
	pengArr = new Penguin*[INITARRAY];
	turtArr = new Turtle*[INITARRAY];
	userAnArr = new NewAnimal*[INITARRAY];
}

/***************************************************************************
**   Description: This function welcomes the user and gives them the option
**                to begin the game or quit.  A while loop keeps the program
**				  running and the various menu options are presented to the
**				  user.  Game functions are called in order to cycle through
**				  the turns/days.
****************************************************************************/
int Zoo::mainMenu()
{
	int menuChoice = 0,
		randomEvent = 0,
		keepPlaying,
		tigs = 0,
		pengs = 0,
		turts = 0,
		userBabies = 0,
		userPayOff = 0,
		userAns = 0,
		foodQuality = 0,
		totAnimals = 0;
	double  userCost = 0.0,
			userBaseFoodCost = 0.0,
			boomBonus = 0.0,
			newAnCost = 0.0;
	InputValidate mainMenuCheck;
	bool active = true;

	std::cout << "Welcome to Zoo Tycoon!" << std::endl;
	std::cout << "Andrew Clos, CS162-400, Project 2." << std::endl;
	std::cout << "(1) Start Zoo Tycoon." << std::endl;
	std::cout << "(2) Quit." << std::endl;
	menuChoice = mainMenuCheck.intValidate(YESLIMITS, 1, 2);
		
	//starts a new game
	if (menuChoice == 1)  
	{	//user choices and initial game options are taken here.
		std::cout << "Zoo Tycoon Started!" << std::endl;
		std::cout << "***Extra Credit: Adding optional new animal class.***" << std::endl;
		std::cout << "***Extra Credit: Implementation of Feed Types ***" << std::endl;
		std::cout << "Would you like to add a new Animal Class?" << std::endl;
		std::cout << "(1) Yes." << std::endl;
		std::cout << "(2) No." << std::endl;
		
		if (mainMenuCheck.intValidate(YESLIMITS, MININITBUY, MAXINITBUY) == 1)
		{   //collect info about new animal
			std::cout << "Please enter the name of your new Animal type?" << std::endl;
			setUserAnimalName(mainMenuCheck.strValidate(true, MAXANIMALNAME));
			std::cout << "Please enter the cost of this animal (a number between " << MINCOST << " and " << MAXCOST << "): ";
			userCost = mainMenuCheck.doubleValidate(YESLIMITS, MINCOST, MAXCOST);
			std::cout << "Please enter the number of babies this animal will produce (an integer between " << MINBABY << " and " << MAXBABY << "): ";
			userBabies = mainMenuCheck.intValidate(YESLIMITS, MINBABY, MAXBABY);
			std::cout << "Please enter the base food cost for this animal (a number between " << MINFOOD << " and " << MAXFOOD << "): ";
			userBaseFoodCost = mainMenuCheck.doubleValidate(YESLIMITS, MINFOOD, MAXFOOD);
			std::cout << "Please enter the payoff (as an integer percentage of animal cost between " << MINPAY << "% and " << MAXPAY << "%): ";
			userPayOff = mainMenuCheck.intValidate(YESLIMITS, MINPAY, MAXPAY);
			setNumSpecies(4);
		}
		//user now specifies how many of each initial animal they'd like to buy
		std::cout << std::endl << "You have $" << std::fixed << std::setprecision(2) << getCashOnHand() << " to start off with. Spend it wisely." << std::endl;
		std::cout << "Please enter the number of Tigers you'd like to buy (an integer between " << MININITBUY << " and " << MAXINITBUY << "): ";
		tigs = mainMenuCheck.intValidate(YESLIMITS, MININITBUY, MAXINITBUY);
		std::cout << "Please enter the number of Penguins you'd like to buy (an integer between " << MININITBUY << " and " << MAXINITBUY << "): ";
		pengs = mainMenuCheck.intValidate(YESLIMITS, MININITBUY, MAXINITBUY);
		std::cout << "Please enter the number of Turtles you'd like to buy (an integer between " << MININITBUY << " and " << MAXINITBUY << "): ";
		turts = mainMenuCheck.intValidate(YESLIMITS, MININITBUY, MAXINITBUY);
		//optional new animal
		if (getNumSpecies() == 4)
		{
			std::cout << "Please enter the number of " << getUserAnimalName() << "'s you'd like to buy (an integer between " << MININITBUY << " and " << MAXINITBUY << "): ";
			userAns = mainMenuCheck.intValidate(YESLIMITS, MININITBUY, MAXINITBUY);
			int userAnimal[12] = { 0, 0, 0, 0, 0, 0, userAns, 1, userCost, userBabies, userBaseFoodCost, userPayOff };
			newAnimals(userAnimal);
		}
		//add initial Animals to their respective arrays.	
		int startAnimals[12] = { tigs, 1, pengs, 1, turts, 1, 0, 0, 0, 0, 0, 0 };
		newAnimals(startAnimals);
		
		//start a loop to cycle through the days (turns)
		while (active)
		{
			if (getCashOnHand() >= 1)  //if out of money, declare bankruptcy, end game
			{
				showParams();
				
				//***Extra credit for allowing different qualities of food.
				std::cout << "Please enter the feed type you'd like to use today." << std::endl;
				std::cout << "(1) Cheap food (half as expensive)." << std::endl;
				std::cout << "(2) Generic food (normal price)." << std::endl;
				std::cout << "(3) Premium food (twice as expensive)." << std::endl;
				foodQuality = mainMenuCheck.intValidate(YESLIMITS, 1, 3);
				
				//see reflection for why I used 140 as the range of random numbers
				//this section of if / else-if is used to determine the random event based
				//on the food type chosen.
				randomEvent = randomGen(1, 140);
				if (foodQuality == 1)
				{   // 56/140 = 40% chance of occurrance, while others have 20% chance
					if (randomEvent <= 56)
					{
						sickness();
					}
					else if (randomEvent <= 84)
					{
						boomBonus = 0;
						boomBonus = boomZoo();
					}
					else if (randomEvent <= 112)
					{
						babyBorn();
					}
					else
					{
						std::cout << "No random event occurred today." << std::endl;
					}
				}
				else if (foodQuality == 2)
				{   // 35/140 = 25% chance of occurrance, while others have 25% as well
					if (randomEvent <= 35)
					{
						sickness();
					}
					else if (randomEvent <= 70)
					{
						boomBonus = 0;
						boomBonus = boomZoo();
					}
					else if (randomEvent <= 105)
					{
						babyBorn();
					}
					else
					{
						std::cout << "No random event occurred today." << std::endl;
					}
				}
				else if (foodQuality == 3)
				{  // 20/140 = 14.28% chance of occurrance, while others have 28.57% chance
					if (randomEvent <= 20)
					{
						sickness();
					}
					else if (randomEvent <= 60)
					{
						boomBonus = 0;
						boomBonus = boomZoo();
					}
					else if (randomEvent <= 100)
					{
						babyBorn();
					}
					else
					{
						std::cout << "No random event occurred today." << std::endl;
					}
				}

				//call the next two methods to occur during the day.				
				feed(foodQuality);
				endDay(boomBonus);
			
				//finally, ask user if they'd like to buy an animal and add that animal to the 
				//array by calling the newAnimal function.
				std::cout << "Would you like to buy an adult animal?" << std::endl;
				std::cout << "(1) Yes." << std::endl;
				std::cout << "(2) No." << std::endl;
				menuChoice = mainMenuCheck.intValidate(YESLIMITS, 1, 2);

				if (menuChoice == 1)
				{
					std::cout << "Your total cash is: " << getCashOnHand() << std::endl;
					std::cout << "(1) Tiger (" << Tiger().getCost() << ")." << std::endl;
					std::cout << "(2) Penguin (" << Penguin().getCost() << ")." << std::endl;
					std::cout << "(3) Turtle (" << Turtle().getCost() << ")." << std::endl;
					if (getNumSpecies() == 4)
					{
						std::cout << "(4) " << getUserAnimalName() << " (" << newAnCost << ")." << std::endl;
						menuChoice = mainMenuCheck.intValidate(YESLIMITS, 1, 4);
					}
					else
					{
						menuChoice = mainMenuCheck.intValidate(YESLIMITS, 1, 3);
					}
					if (menuChoice == 1)
					{
						int animalData[12] = { 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
						newAnimals(animalData);
					}
					else if (menuChoice == 2)
					{
						int animalData[12] = { 0, 0, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0 };
						newAnimals(animalData);
					}
					else if (menuChoice == 3)
					{
						int animalData[12] = { 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 0 };
						newAnimals(animalData);
					}
					else if (menuChoice == 4)
					{
						int animalData[12] = { 0, 0, 0, 0, 0, 0, 1, 3, userCost, userBabies, userBaseFoodCost, userPayOff};
						newAnimals(animalData);
					}

				}
				//Design decision to end the current game if the user runs out of animals and has made the choice to not buy more
				totAnimals = getTigs() + getPengs() + getTurts() + getUserAn();
				if (totAnimals == 0)
				{
					std::cout << "You've run out of Animals and have elected not to buy any more." << std::endl;
					active = false;
				}
				else
				{
					std::cout << "(1) Keep playing (start another turn)." << std::endl;
					std::cout << "(2) Quit." << std::endl;
					keepPlaying = mainMenuCheck.intValidate(YESLIMITS, 1, 2);
					//optionally display the ages of all animals and keeping playing the game.
					if (keepPlaying == 2)
					{
						active = false;
					}
				}
			}
			else
			{   //end the game if the zoo runs out of money.
				std::cout << "Your zoo has gone bankrupt and your animals have been donated to other zoos." << std::endl;
				active = false;
			}
		}
	} 
	return totAnimals;
}
/***************************************************************************
**   Description: Each time a new animal needs to be created this function is
**				  called.  It is passed a pointer to a 12 element array that
**			      holds integers to represent the number of animals to be 
**				  created, the starting age of the animal, etc.  It also
**				  calls the checkArray function to make sure there is enough
**				  room in the arrays for the new animals.
****************************************************************************/
void Zoo::newAnimals(int *anData)
{   //anData:(0)tigNum, (1)tigAge, (2)pengNum, (3)pengAge, (4)turtNum, (5)turtAge, (6)newNum, (7)newAge, (8)newCost, (9)newBabies, (10)newFood, (11)newPayoff
	
	//update array counters
	setTigs(getTigs() + anData[0]);
	setPengs(getPengs() + anData[2]);
	setTurts(getTurts() + anData[4]);
	setUserAn(getUserAn() + anData[6]);
	//call function to increase size of arrays if needed.
	checkArrays();

	//make new animals.
	for (int i = 0; i < anData[0]; i++)
	{
		tigArr[getTigs() + i - anData[0]] = new Tiger();
		tigArr[getTigs() + i - anData[0]]->setAge(anData[1]);
		setCashOnHand(getCashOnHand() - Tiger().getCost());
	} 
	for (int i = 0; i < anData[2]; i++)
	{
		pengArr[getPengs() + i - anData[2]] = new Penguin();
		pengArr[getPengs() + i - anData[2]]->setAge(anData[3]);
		setCashOnHand(getCashOnHand() - Penguin().getCost());
	}
	for (int i = 0; i < anData[4]; i++)
	{
		turtArr[getTurts() + i - anData[4]] = new Turtle();
		turtArr[getTurts() + i - anData[4]]->setAge(anData[5]);
		setCashOnHand(getCashOnHand() - Turtle().getCost());
	}
	//New Animals - user specified
	for (int i = 0; i < anData[6]; i++)
	{
		userAnArr[getUserAn() + i - anData[6]] = new NewAnimal();
		userAnArr[getUserAn() + i - anData[6]]->setAge(anData[7]);
		userAnArr[getUserAn() + i - anData[6]]->setCost(anData[8]);
		userAnArr[getUserAn() + i - anData[6]]->setNumBabies(anData[9]);
		userAnArr[getUserAn() + i - anData[6]]->setFoodCost(anData[10]);
		userAnArr[getUserAn() + i - anData[6]]->setPayOff((anData[11] / 100.00));
		setCashOnHand(getCashOnHand() - userAnArr[i]->getCost());
	}
}
/***************************************************************************
**   Description: Displays the game parameter legend and prints this game's
**                user parameters to the console.  
****************************************************************************/
void Zoo::showParams()
{
	std::cout << "Game Parameter Definition: [Initial Cash, Cash-on-Hand, Tigers, Penguins, Turtles";
	if (getNumSpecies() == 3)
	{
		std::cout << "]" << std::endl;
	}
	else
	{
		std::cout << ", " << getUserAnimalName() << "]" << std::endl;
	}
	std::cout << "This game's parameters:    [ $" << INITCASH << ",  $" << getCashOnHand();
	std::cout << ",     " << getTigs() << ",       " << getPengs() << ",       " << getTurts();
	if (getNumSpecies() == 3)
	{
		std::cout << "   ]" << std::endl;
	}
	else
	{
		std::cout << ",       " << getUserAn() << "    ]" << std::endl;
	}
}

/******************************************************************************
**   Description: Called before each turn to check to see if any of the arrays  
**                are full of animals, and if so creates a new array that is 
**				  larger and then transfers the contents.
*******************************************************************************/
void Zoo::checkArrays()
{
	if (getTigs() >= getTigArraySize())
	{ //double size of the tiger array if next tiger addition would overfill the array, then add new tigers to array
		Tiger **newTigArr = new Tiger*[getTigArraySize() * 2];

		for (int i = 0; i < getTigArraySize(); i++)
		{
			newTigArr[i] = tigArr[i];
		}
		delete[] tigArr;
		tigArr = newTigArr;
		setTigArray(getTigArraySize() * 2);
	}	
	if (getPengs() >= getPengArraySize())
	{ //double size of the penguin array if next penguin addition would overfill the array
		Penguin **newPengArr = new Penguin*[getPengArraySize() * 2];

		for (int i = 0; i < getPengArraySize(); i++)
		{
			newPengArr[i] = pengArr[i];
		}
		delete[] pengArr;
		pengArr = newPengArr;
		setPenArray(getPengArraySize() * 2);
	}
	if (getTurts() >= getTurtArraySize())
	{ //double size of the turtle array if next turtle addition would overfill the array
		Turtle **newTurtArr = new Turtle*[getTurtArraySize() * 2];

		for (int i = 0; i < getTurtArraySize(); i++)
		{
			newTurtArr[i] = turtArr[i];
		}
		delete[] turtArr;
		turtArr = newTurtArr;
		setTurArray(getTurtArraySize() * 2);
	}
	if (getUserAn() >= getUserAnArraySize())
	{ //double size of the userAnimal array if next turtle addition would overfill the array
		NewAnimal **newUserAnArr = new NewAnimal*[getUserAnArraySize() * 2];

		for (int i = 0; i < getUserAnArraySize(); i++)
		{
			newUserAnArr[i] = userAnArr[i];
		}
		delete[] userAnArr;
		userAnArr = newUserAnArr;
		setUserAnArray(getUserAnArraySize() * 2);
	}
}
/***************************************************************************
**   Description: This class starts a turn by incrementing all animal ages,
**				  feeding all animals and deducting this cost from the user
**				  cash.  It recieves an integer to indicate the food quality
**				  chosen for that day, and adjusts the cost of feeding based
**				  on the food type.
****************************************************************************/
void Zoo::feed(int foodQ)
{
	double feedCost = 0;
	//ages and feeds all of the animals in the zoo.
	for (int i = 0; i < getTigs(); i++)
	{  
		tigArr[i]->setAge(((tigArr[i]->getAge()) + 1));
		feedCost = feedCost + tigArr[i]->getFoodCost();
	}
	for (int i = 0; i < getPengs(); i++)
	{
		pengArr[i]->setAge(((pengArr[i]->getAge()) + 1));
		feedCost = feedCost + pengArr[i]->getFoodCost();
	}
	for (int i = 0; i < getTurts(); i++)
	{
		turtArr[i]->setAge(((turtArr[i]->getAge()) + 1));
		feedCost = feedCost + turtArr[i]->getFoodCost();
	}
	if (getNumSpecies() == 4)
	{
		for (int i = 0; i < getUserAn(); i++)
		{
			userAnArr[i]->setAge(((userAnArr[i]->getAge()) + 1));
			feedCost = feedCost + userAnArr[i]->getFoodCost();
		}
	}
	if (foodQ == 1)
	{
		feedCost = feedCost / 2;
	}
	else if(foodQ == 3)
	{
		feedCost = feedCost * 2;
	}
	setCashOnHand(getCashOnHand() - feedCost);
	std::cout << "Today's Feed Cost: $" << feedCost << std::endl;
}
/***************************************************************************
**   Description: This function handles calculating the payoff of each animal
**				  and adding that to the amount of cash on hand. It recieves
**				  a double for the amount of bonus produced by the tigers.
**				  if there was no tiger bonus that day, bonus will be equal 
**				  to zero.
****************************************************************************/
void Zoo::endDay(double bonus)
{
	double dailyCash = 0.0;

	if (getTigs() > 0)
	{
		dailyCash = dailyCash + (Tiger().getPayoff() * Tiger().getCost() * getTigs());
	}
	if (getPengs() > 0)
	{
		dailyCash = dailyCash + (Penguin().getPayoff() * Penguin().getCost() * getPengs());
	}
	if (getTurts() > 0)
	{
		dailyCash = dailyCash + (Turtle().getPayoff() * Turtle().getCost() * getTurts());
	}
	if (getUserAn() > 0)
	{
		dailyCash = dailyCash + (userAnArr[0]->getPayoff() * userAnArr[0]->getCost() * getUserAn());
	}
	setCashOnHand(getCashOnHand() + dailyCash + bonus);
	std::cout << "The Animals Brought in: $" << dailyCash << std::endl;
}
/***************************************************************************
**   Description:  A random event function to choose a random animal to die.
**				   That animal is then deleted from memory and all other
**				   elements in the array shifted over to fill its place. 
****************************************************************************/
void Zoo::sickness()
{
	//random number between 0 and the total number of Animals in the zoo minus 1.
	int randAnimal = randomGen(0, (getTigs() + getPengs() + getTurts() + getUserAn() - 1));
	std::cout << "Random Animal Value: " << randAnimal << std::endl;
	std::cout << "A sickness has occurred in the Zoo.  Despite the caretaker's best efforts, ";
	
	if (randAnimal < getTigs())
	{
		std::cout << "tiger number "<< randAnimal << " has died."  << std::endl;
		
		delete tigArr[randAnimal];
		for (int i = randAnimal; i < getTigs() - 1; i++)
		{
			tigArr[i] = tigArr[i + 1];
		}
		tigArr[(getTigs() - 1)] = nullptr;
		setTigs(getTigs() - 1);
	}
	else if (randAnimal >= getTigs() && randAnimal < getTigs() + getPengs())
	{
		std::cout << "penguin number " << randAnimal - getTigs() << " has died." << std::endl;
		delete pengArr[(randAnimal - getTigs())];
		for (int i = randAnimal - getTigs(); i < getPengs() - 1; i++)
		{
			pengArr[i] = pengArr[i + 1];
		}
		pengArr[(getPengs() - 1)] = nullptr;
		setPengs(getPengs() - 1);
	}
	else if (randAnimal >= getTigs() + getPengs() && randAnimal < getTigs() + getPengs() + getTurts())
	{
		std::cout << "turtle number " << randAnimal - (getTigs() + getPengs()) << " has died." << std::endl;
		delete turtArr[(randAnimal - (getTigs() + getPengs()))];
		for (int i = randAnimal - (getTigs() + getPengs()); i < getTurts() - 1; i++)
		{
			turtArr[i] = turtArr[i + 1];
		}
		turtArr[(getTurts() - 1)] = nullptr;
		setTurts(getTurts() - 1);
	}
	else if (randAnimal >= (getTigs() + getPengs() + getTurts()) && randAnimal < (getTigs() + getPengs() + getTurts() + getUserAn()))
	{
		std::cout << getUserAnimalName() << " number " << randAnimal - (getTigs() + getPengs() + getTurts()) << " has died." << std::endl;
		delete userAnArr[(randAnimal - (getTigs() + getPengs() + getTurts()))];
		for (int i = randAnimal - (getTigs() + getPengs() + getTurts()); i < getUserAn() - 1; i++)
		{
			userAnArr[i] = userAnArr[i + 1];
		}
		userAnArr[(getUserAn() - 1)] = nullptr;
		setUserAn(getUserAn() - 1);
	}
}
/***************************************************************************
**   Description: A random event function that returns a cash bonus based on
**				  the number of tigers in the zoo.  
****************************************************************************/
double Zoo::boomZoo()
{
	int randomMoney = randomGen(250, 500);
	double bonus = 0;

	for (int i = 0; i < getTigs(); i++)
	{
		bonus = bonus + randomMoney;
	}
	std::cout << "Zoo attendence has been booming! You get a bonus of $" << bonus << std::endl;
	bonus = bonus * getTigs();
	return bonus;
}
/***************************************************************************
**   Description: One of the random events can trigger a baby to be born. 
**				  This function first searches through each of the animal 
**				  arrays and counts the number of animals that are at least
**				  3 days old.  If none exist, a message is output to the 
**				  and no baby is produced.  If there is at least one parent
**				  of-age, a while loop is entered and a random species is
**				  chosen until an of-Age parent is found and a baby is made.
****************************************************************************/
void Zoo::babyBorn()
{
	int ofAgeTigers = 0,
		ofAgePenguins = 0,
		ofAgeTurtles = 0,
		ofAgeUserAns = 0,
		parent = 0;
	bool ofAgeFound = false;

	//determine the number of potential parents
	for (int i = 0; i < getTigs(); i++)
	{
		if (tigArr[i]->getAge() >= OFAGE)
		{
			ofAgeTigers++;
		}
	}

	for (int i = 0; i < getPengs(); i++)
	{
		if (pengArr[i]->getAge() >= OFAGE)
		{
			ofAgePenguins++;
		}
	}

	for (int i = 0; i < getTurts(); i++)
	{
		if (turtArr[i]->getAge() >= OFAGE)
		{
			ofAgeTurtles++;
		}
	}

	for (int i = 0; i < getUserAn(); i++)
	{
		if (userAnArr[i]->getAge() >= OFAGE)
		{
			ofAgeUserAns++;
		}
	}
	
	//if none are of age, no babies are born and tell user.
	if (ofAgeTigers == 0 && ofAgePenguins == 0 && ofAgeTurtles == 0 && ofAgeUserAns == 0)
	{
		std::cout << "We tried to have a baby, but none of the animals are of age!" << std::endl;
	}
	
	else
	{   //enter a loop to indentify a species to have baby and then check to see if that species has any 
		//of-age members.  If so, call the newAnimals method to create the new babies.
		while (!ofAgeFound)
		{
			parent = randomGen(1, 4);
			if (parent == 1 && ofAgeTigers > 0)
			{
				std::cout << "A birth has occurred at the zoo! Say 'Hello World' to your new Tiger!" << std::endl;
				ofAgeFound = true;
				int createAn[12] = { (tigArr[0]->getNumBabies()), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
				newAnimals(createAn);
			}
			else if (parent == 2 && ofAgePenguins > 0)
			{
				std::cout << "A baby has been born at the zoo! Say 'Hello World' to your new Penguins!" << std::endl;
				ofAgeFound = true;
				int createAn[12] = { 0, 0, (pengArr[0]->getNumBabies()), 0, 0, 0, 0, 0, 0, 0, 0, 0 };
				newAnimals(createAn);
			}
			else if (parent == 3 && ofAgeTurtles > 0)
			{
				std::cout << "A baby has been born at the zoo! Say 'Hello World' to your new Turtles!" << std::endl;
				ofAgeFound = true;
				int createAn[12] = { 0, 0, 0, 0, (turtArr[0]->getNumBabies()), 0, 0, 0, 0, 0, 0, 0 };
				newAnimals(createAn);
			}
			else if (parent == 4 && ofAgeUserAns > 0)
			{
				std::cout << "A baby has been born at the zoo! Say 'Hello World' to your new " << userAnimalName << "!" << std::endl;
				ofAgeFound = true;
				int createAn[12] = { 0, 0, 0, 0, 0, 0, (userAnArr[0]->getNumBabies()), 0, (userAnArr[0]->getCost()),
					(userAnArr[0]->getNumBabies()), (userAnArr[0]->getFoodCost()), (userAnArr[0]->getPayoff()) };
				newAnimals(createAn);
			}
		}	 
	}
} 

/***************************************************************************
**   Description: This generates a random integer between two values provided
**				  by the caller.  It returns an integer within that range.
****************************************************************************/
int Zoo::randomGen(int lower, int upper)
{
	int result = 0;
	std::random_device randDev;
	std::mt19937 randSeed(randDev());
	std::uniform_int_distribution<> randomNum(lower, upper);
	
	result = randomNum(randSeed);
	return result;
}
/***************************************************************************
**   Description: Get and set methods to run the program.  I avoided using 
**				  explicit calls to private member variables by creating a 
**			      get or set method for each of the values.
****************************************************************************/
double Zoo::getCashOnHand()
{
	return cashOnHand;
}
int Zoo::getTigs()
{
	return totTigers;
}
int Zoo::getPengs()
{
	return totPenguins;
}
int Zoo::getTurts()
{
	return totTurtles;
}
int Zoo::getUserAn()
{
	return totUserAns;
}
std::string Zoo::getUserAnimalName()
{
	return userAnimalName;
}
int Zoo::getNumSpecies()
{
	return numSpecies;
}
int Zoo::getTigArraySize()
{
	return tigArraySize;
}
int Zoo::getPengArraySize()
{
	return penArraySize;
}
int Zoo::getTurtArraySize()
{
	return turArraySize;
}
int Zoo::getUserAnArraySize()
{
	return userAnArraySize;
}
void Zoo::setCashOnHand(double cash)
{
	cashOnHand = cash;
}
void Zoo::setTigs(int tigs)
{
	totTigers = tigs;
}
void Zoo::setPengs(int pengs)
{
	totPenguins = pengs;
}
void Zoo::setTurts(int turts)
{
	totTurtles = turts;
}
void Zoo::setUserAn(int userAns)
{
	totUserAns = userAns;
}
void Zoo::setUserAnimalName(std::string userName)
{
	userAnimalName = userName;
}
void Zoo::setNumSpecies(int numSpecs)
{
	numSpecies = numSpecs;
}
void Zoo::setTigArray(int size)
{
	tigArraySize = size;
}
void Zoo::setPenArray(int size)
{
	penArraySize = size;
}
void Zoo::setTurArray(int size)
{
	turArraySize = size;
}
void Zoo::setUserAnArray(int size)
{
	userAnArraySize = size;
}

/***************************************************************************
**   Description: destructor contains delete for dynamic arrays since they
**				  are initially created in the constructor. Since they are
**				  pointers to arrays, for loops are needed to free up the
**				  memory at each index.
***************************************************************************/
Zoo::~Zoo()
{
	for (int i = 0; i < getTigs(); i++)
	{
		delete[] tigArr[i];
	}
	delete[] tigArr;
	tigArr = nullptr;

	for (int i = 0; i < getPengs(); i++)
	{
		delete[] pengArr[i];
	}
	delete[] pengArr;
	pengArr = nullptr;
	for (int i = 0; i < getTurts(); i++)
	{
		delete[] turtArr[i];
	}
	delete[] turtArr;
	turtArr = nullptr;

	for (int i = 0; i < getUserAn(); i++)
	{
		delete[] userAnArr[i];
	}
	delete[] userAnArr;
	userAnArr = nullptr;
}