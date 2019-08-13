/***************************************************************************
**   Program Name: Final Project (Diamond.cpp)
**   Author: Andrew Clos
**   Date: 8/12/2019
**   Description: Derived class of the abstract base class (Space). The player
**				  enters this space and is greeted with a number of options to
**				  dig or look around.  Looking around demonstrates a linked
**				  structure, showing that this space is aware of its neighbors
**				  and displaying them to the console.
****************************************************************************/

#include<iostream>
#include "Diamond.hpp"

//default constructor to establish this space's 'vital statistics'
Diamond::Diamond()
{
	roomName = "\033[1;97mDiamond\033[0m";
	numDigSites = 12;
	costPerDig = 2;
	odds = 65;
	ptsPerGem = 35;
	minGems = 3;
	maxGems = 6;
	encountered = false;
}

/********************************************************************************
**   Description: A unique description of the room descirbing the characteristics
**				  and difficulty of dig sites. Provides menu choices for the user
**				  asking them what they'd like to do after they enter.
********************************************************************************/
std::vector<int> Diamond::playerEnters(int shovels)
{
	InputValidate tester;
	int menuChoice = 0,
		subMenu = 0,
		rewards = 0,
		randomObject = 0,
		encounter = 0;
	std::vector<int> gemsShovs;
	gemsShovs.push_back(0);
	gemsShovs.push_back(0);

	//greet user with explanation of room, toggle the visited status so that the room may not be re-entered.
	std::cout << "You've discovered the " << roomName << " Room!" << std::endl;
	std::cout << "This room contains numerous small gems that are easy to dig. " << std::endl;
	std::cout << "\033[1;97mDigsites: \033[0m" << numDigSites << ".  " << "\033[1;97mShovels/Dig: \033[0m" << costPerDig << ", " << "\033[1;97mPoints Per Gem: \033[0m" << ptsPerGem << ", " << "\033[1;97mShovels: \033[0m" << shovels << "." << std::endl;
	beenVisited = true;

	//remain in loop until users chooses the leave option.
	while (menuChoice != 3)
	{
		std::cout << "What would you like to do next? " << std::endl;
		std::cout << "(1) Dig for gems. " << std::endl;
		std::cout << "(2) Look Around. " << std::endl;
		std::cout << "(3) Leave, but remember that the mine shaft will become unstable and you'll be unable to return." << std::endl;

		menuChoice = tester.intValidate('y', 1, 3);

		if (menuChoice == 2)
		{
			lookAround();

			if (subMenu != 1)
			{  //the option to interact with the object in the room is presented.
				std::cout << "You also notice a tightly sealed bottle in corner." << std::endl;
				std::cout << "(1) Attempt to open the bottle." << std::endl;
				std::cout << "(2) Leave it alone. " << std::endl;
				subMenu = tester.intValidate('y', 1, 2);

				if (subMenu == 1)
				{   //if user chooses to interact, there is an equal chance that something good, neutral or bad will happpen.
					randomObject = getRandom(1, 3);

					std::cout << "You carefully cut the wax seal around the bottle's cap..." << std::endl;
					//good fortune
					if (randomObject == 1)
					{
						encounter = getRandom(2, 5);
						std::cout << "Inside, you uncover a trove of " << roomName << " gems, stashed here by an ancient miner!" << std::endl;
						std::cout << encounter << " " << roomName << " gems have been added to your collection." << std::endl;
						gemsShovs.at(0) = gemsShovs.at(0) + encounter;
					}
					//neutral 
					else if (randomObject == 2)
					{
						std::cout << "Nothing but some old whiskey is present here, yum." << std::endl;
					}
					//bad fortune
					else if (randomObject == 3)
					{
						encounter = getRandom(2, 6);
						if (encounter > shovels)
						{
							encounter = shovels;
						}

						std::cout << "Oh no, a " << roomName << " whiskey worm jumps up and steals " << encounter << " of your shovels, that scoundrel!" << std::endl;
						gemsShovs.at(1) = gemsShovs.at(1) + encounter;
						shovels = shovels - encounter;
						std::cout << "\033[1;97mShovels: \033[0m" << shovels << "." << std::endl;
					}
				}
			}
			else
			{   //if the object has been interacted with on an earlier call to look around, it cannot be interacted with again.
				std::cout << "...And the broken bottle." << std::endl;
			}
		}
		else if (menuChoice == 1)   //user chooses to dig.
		{
			if (numDigSites < 1)   //if all dig sites have been dug.
			{
				std::cout << "There are no more available dig site in this room." << std::endl;
			}
			else if (shovels < costPerDig)  //if not enough shovels to dig
			{
				std::cout << "Sorry, you don't have enough shovels to dig here." << std::endl;
			}
			else
			{   //dig! give a random amount of gems (or no gems) for each dig attempt.
				//decrease shovel count, decrease the number of digSites remaining
				shovels = shovels - costPerDig;
				numDigSites--;

				gemsShovs.at(1) = gemsShovs.at(1) + costPerDig;
				std::cout << "You dig through the earth...." << std::endl;
				std::cout << "You seem to be reaching something firmer..." << std::endl;
				if (getRandom(1, 100) <= odds)
				{
					rewards = getRandom(minGems, maxGems);
					std::cout << "Yes! You've found it, something hard and valuable has been unearthed!" << std::endl;
					std::cout << "You've been rewarded with " << rewards << " " << roomName << " gems!" << std::endl;
					gemsShovs.at(0) = gemsShovs.at(0) + rewards;
				}
				else
				{
					std::cout << "No, no that is not it. Shoot darn diggity, this hole is a no go!" << std::endl << " No luck this time." << std::endl;
				}
				//display remaining dig-sites and shovels in this Space.
				std::cout << "\033[1;97mDigsites: \033[0m" << numDigSites << ", " << "\033[1;97mShovels: \033[0m" << shovels << "." << std::endl;
			}
		}   //display gem count of this session.
		std::cout << roomName << " gems so far: " << gemsShovs.at(0) << "." << std::endl;
	}
	return gemsShovs;
}

/***************************************************************************
**   Description: Shows unique ASCII art for each room and also demonstrates
**				  the linked structure by showing the neighbors of each room
**			      to the user.
**				  Source Cited for ASCII art generation: https://manytools.org/hacker-tools/convert-images-to-ascii-art/
****************************************************************************/
void Diamond::lookAround()
{
	//print ASCII art unique to each room. 
	//diamond

	std::cout << "\033[1;97m                        ****////////////////////(#(///////////////#%#//////,     \033[0m" << std::endl;
	std::cout << "\033[1;97m                    .(   *(.     ,        ,/,        ./*         /      ,(*. /*                    \033[0m" << std::endl;
	std::cout << "\033[1;97m                  (**/.           /  .(*                  ./*  *.            .//(*                 \033[0m" << std::endl;
	std::cout << "\033[1;97m               //                */(**                       /*(/,                ##.              \033[0m" << std::endl;
	std::cout << "\033[1;97m            (#  .            /*   /    **                 /,    /   ,/.           /  //*           \033[0m" << std::endl;
	std::cout << "\033[1;97m         *//    .        ,(      /        **           /,        /      ,/.       /    *./,        \033[0m" << std::endl;
	std::cout << "\033[1;97m      /.,*      ,    **         /            **     /,            *          */.  /      ./ ,/     \033[0m" << std::endl;
	std::cout << "\033[1;97m   ** *,        **/.           /.               *(*               *(.           ./%,       *%,.%   \033[0m" << std::endl;
	std::cout << "\033[1;97m  #*//,*////*/, * *.,,***,, ,  *  ,.******,.. ,  *  . .  .  , .    * . ..,,,,.* , . .,//*(/*/*(#   \033[0m" << std::endl;
	std::cout << "\033[1;97m  *, .(        ,%.           .,%,               .#.               *.             */        /  (    \033[0m" << std::endl;
	std::cout << "\033[1;97m    .*  /.       /(             /                (                ,            .%.       /  /      \033[0m" << std::endl;
	std::cout << "\033[1;97m      ./  /        #/            .              .*               /           .(/       / ./        \033[0m" << std::endl;
	std::cout << "\033[1;97m         ,/ *,      .**          ,,             / *             /           (/      ./ *.          \033[0m" << std::endl;
	std::cout << "\033[1;97m           ,/ ,*      /,*         ,.            ( /            /          /./      / /.            \033[0m" << std::endl;
	std::cout << "\033[1;97m              /.*,     /.*,        *.           * *           *         *..*     /./               \033[0m" << std::endl;
	std::cout << "\033[1;97m                ,*./     / *,       ,,         ,.  ,         *        ,* /    ,***                 \033[0m" << std::endl;
	std::cout << "\033[1;97m                   /.(    ,  /.      ,         /   (         .      ./  ,   .*/.                   \033[0m" << std::endl;
	std::cout << "\033[1;97m                     .,/.   /  ,*     /        /   *        /     ,*  /   **/                      \033[0m" << std::endl;
	std::cout << "\033[1;97m                       .//,  *,  /.    /      .,   .,      (     /  .*  */*                        \033[0m" << std::endl;
	std::cout << "\033[1;97m                          /(.  /   /    (     *     /     /    /.  /. ,(,                          \033[0m" << std::endl;
	std::cout << "\033[1;97m                            ,(/ ..   /   /    /     /    /   /    , (#                             \033[0m" << std::endl;
	std::cout << "\033[1;97m                               (( /    /  /   /     ,,  /  ,*   ,,((                               \033[0m" << std::endl;
	std::cout << "\033[1;97m                                 (/*.   ./ / ..      * *../    //(                                 \033[0m" << std::endl;
	std::cout << "\033[1;97m                                   .%#     //*       / **    *%.                                   \033[0m" << std::endl;
	std::cout << "\033[1;97m                                      %.    ,%       ,%     (                                      \033[0m" << std::endl;
	std::cout << "\033[1;97m                                        *,   .*      /   ./                                        \033[0m" << std::endl;
	std::cout << "\033[1;97m                                           /   /    /  /.                                          \033[0m" << std::endl;
	std::cout << "\033[1;97m                                             /. /  ( /,                                            \033[0m" << std::endl;
	std::cout << "\033[1;97m                                               ,/.((       \033[0m" << std::endl;



	//each Space is linked to its neighbors and depending on its geometric orientation, its neighbors may be
	//to its top, bottom, left or right.
	if (top != nullptr)
	{
		std::cout << "To the top, you see the " << top->getName() << " room." << std::endl;
	}
	if (bottom != nullptr)
	{
		std::cout << "To the bottom, you see the " << bottom->getName() << " room." << std::endl;
	}
	if (left != nullptr)
	{
		std::cout << "To the left, you see the " << left->getName() << " room." << std::endl;
	}
	if (right != nullptr)
	{
		std::cout << "To the right, you see the " << right->getName() << " room." << std::endl;
	}
}
