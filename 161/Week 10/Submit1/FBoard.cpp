/************************************************************************** 
** Author: Andrew Clos
** Date: 05/30/2019
** Description: Assignment 10 (FBoard.cpp) This function definition 
**              fills an 8x8 array with initial '^,' 'x,' and 'o' symbols.
**              It contains a game state method to return the status of the
**              game as well as public methods to move the x and o pieces
**              and print the game board.  It contains two private methods
**              that check to see if x is trapped (o wins) or x has reached
**              the 7th row (x wins).  
**************************************************************************/

#include<iostream>
#include "FBoard.hpp"

/********************************************************************* 
** Description: Default constructor fills 2D array with '^' for empty
**              spaces, and places 'o's and 'x' at starting positions.
**              Also initializes gameState status to UNFINISHED, and 
**              initializes data members xRow and xCol to 0 and 3.
*********************************************************************/
FBoard::FBoard()
{
	xRow = 0;  //initialize the tracking of x's row
	xCol = 3;  //initialize the tracking of x's column
	status = UNFINISHED;   //status is of the enumerated type gameState
	
	for (int row = 0; row < 8; row++)//fills 8x8 array with '^' (empty)
	{
		for (int col = 0; col < 8; col++)
		{
			boardArr[row][col] = '^';
		}
	}
	//puts o's and x in initial positions as specified.
	boardArr[7][0] = 'o';
	boardArr[7][2] = 'o';
	boardArr[7][4] = 'o';
	boardArr[7][6] = 'o';
	boardArr[xRow][xCol] = 'x';
}

/*********************************************************************
** Description: getGameState method simply returns the enumerated 
**              gameState type. (X_WON = 0, O_WON = 1, UNFINISHED = 2)
*********************************************************************/
gameState FBoard::getGameState()
{
	return status;
}

/*********************************************************************
** Description: moveX function uses nested if-statements to perform 
**              legality of the proposed move.  The game must not be
**              finished, the move must remain inbounds, the move must
**              be to an unoccupied spot and must only be "1 away" in 
**              a diagonal position.  If all of these conditions are 
**              satisfied, the move is made, a funciton is called to 
**              check if x has won and true is returned.  
*********************************************************************/
bool FBoard::moveX(int moveXRow, int moveXCol)
{      	   
	if (getGameState() == UNFINISHED)  //is game unfinished?
	{         //is the move within the game board?
		if (moveXRow >= 0 && moveXRow <= 7 && moveXCol >= 0 && moveXCol <= 7)
		{     //is move legal? (1 row and column in any direction)
			if ((moveXRow == xRow + 1 || moveXRow == xRow - 1) && (moveXCol == xCol + 1 || moveXCol == xCol - 1))
			{     //is the location unoccupied?
				if (boardArr[moveXRow][moveXCol] == '^')
				{
					boardArr[xRow][xCol] = '^';  //original x location becomes unoccupied
					xRow = moveXRow;  //x row tracker updates
					xCol = moveXCol;  //x col tracker updates
					boardArr[xRow][xCol] = 'x';  //new x location becomes occupied
					hasXWon();   //call function to see if X has won with this move.
					return true;
				}
				else
				{
					std::cout << "The Xspace was occupied." << std::endl;
					return false;
				}
			}
			else
			{
				std::cout << "The Xmove was illegal." << std::endl;
				return false;
			}
		}
		else
		{
			std::cout << "The Xmove was out of bounds." << std::endl;
			return false;
		}
	}
	else
	{
		std::cout << "The Xgame is finished." << std::endl;
		return false;
	}
}

/*********************************************************************
** Description: moveO function uses nested if-statements to perform
**              legality of the proposed move.  The game must not be
**              finished, the move must remain inbounds, the move must
**              start with location that contains an 'o' and be to an
**              unoccupied spot. The move must only be "1 away" in
**              a forward and diagonal direction.  If all of these 
**              conditions are satisfied the move is made, a funciton 
**              is called to check if o has won and true is returned.
*********************************************************************/
bool FBoard::moveO(int moveOFromRow, int moveOFromCol, int moveOToRow, int moveOToCol)
{
	if (getGameState() == UNFINISHED)  //is game unfinished
	{
		if (boardArr[moveOFromRow][moveOFromCol] == 'o')  //does original location contain an 'o'?
		{        //is the move within the game board?
			if (moveOToRow >= 0 && moveOToRow <= 7 && moveOToCol >= 0 && moveOToCol <= 7)
			{        //is move legal? (1 column in any direction, 1 row ahead)
				if (moveOToRow == moveOFromRow - 1 && (moveOToCol == moveOFromCol + 1 || moveOToCol == moveOFromCol - 1))
				{        //is the location unoccupied?
					if (boardArr[moveOToRow][moveOToCol] == '^')
					{
						boardArr[moveOFromRow][moveOFromCol] = '^';  //original o location becomes unoccupied
						boardArr[moveOToRow][moveOToCol] = 'o';     //occupy new location with o.
						isXTrapped();
						return true;
					}
					else
					{
						std::cout << "The space was occupied." << std::endl;
						return false;
					}
				}
				else
				{
					std::cout << "The move was illegal." << std::endl;
					return false;
				}
			}
			else
			{
				std::cout << "The move was out of bounds." << std::endl;
				return false;
			}
		}
		else
		{
			std::cout << "Origin does not contain 'o.'" << std::endl;
			return false;
		}
	}
	else 
	{
		std::cout << "The game is finished." << std::endl;
		return false;
	}
}

/*********************************************************************
** Description: private isXTrapped function is called after a legal 
**              moveO and checks to see if o has won by leaving x with
**              no remaining legal moves.  It starts to see if x is 
**              surrounded on all four sides by an 'o,' then checks to
**              see if x is cornered with its one escape blocked by o.
**              Next it checks to see if x is against one of the three
**              non-winning sides and to see if its two remaining
**              escapes are blocked by an o's. If any of these 
**              conditions are met, it changes the gameState status to 
**              O_WON.
*********************************************************************/
void FBoard::isXTrapped()
{        //is x surrounded on all four sides by 'o'?
	if (boardArr[xRow + 1][xCol + 1] == 'o' && boardArr[xRow - 1][xCol - 1] == 'o' && boardArr[xRow - 1][xCol + 1] == 'o' && boardArr[xRow + 1][xCol - 1] == 'o')
	{
		std::cout << "O won(surrounded)." << std::endl;
		status = O_WON;
	}       //is x in the upper right corner and blocked by 'o'?
	else if (boardArr[0][7] == 'x' && boardArr[1][6] == 'o')
	{
		std::cout << "O won(upper right cornered)." << std::endl;
		status = O_WON;
	}        //is x in the top row and blocked on two sides by 'o'?
	else if (xRow == 0 && boardArr[xRow + 1][xCol + 1] == 'o' && boardArr[xRow + 1][xCol - 1] == 'o')  //pinned at top
	{
		std::cout << "O won(pinned at top)." << std::endl;
		status = O_WON;
	}        //is x on the left side and blocked on two sides by 'o'?
	else if (xCol == 0 && boardArr[xRow + 1][xCol + 1] == 'o' && boardArr[xRow - 1][xCol + 1] == 'o')  //pinned at left
	{
		std::cout << "O won(pinned at left)." << std::endl;
		status = O_WON;
	}         //is x on the right side and blocked on two sides by 'o'?
	else if (xCol == 7 && boardArr[xRow + 1][xCol - 1] == 'o' && boardArr[xRow - 1][xCol - 1] == 'o')  //pinned at right
	{
		std::cout << "O won(pinned at right)." << std::endl;
		status = O_WON;
	}
}

/*********************************************************************
** Description: hasXWon is called every time moveX completes a legal
**              move.  Using a for-loop to see if x has reached row 7
**              in any of the 8 columns.  If it has, the gameState
**              status is set to X_WON.
*********************************************************************/
void FBoard::hasXWon()
{
	for (int col = 0; col < 8; col++)  
	{
		if (boardArr[7][col] == 'x')
		{
			status = X_WON;
		}
	}
}

/*********************************************************************
** Description: public printer function to print the game board. Used
**              for debugging.
*********************************************************************/
void FBoard::printer()
{
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			std::cout << boardArr[row][col] << " ";
		}
		std::cout << std::endl;
	}
}
