/*************************************************************************** 
** Author: Andrew Clos
** Date: 05/30/2019
** Description: Assignment 10 (FBoard.hpp) This class declaration provides 
**              the framework for an object called a FBoard. An enumerated 
**              gameState type is established with three possible values to
**              the winning or unfinished conditions.  An 8x8 2d array is
**              defined, as well as the gameState variable 'status,' and 
**              integer values to track the row and column of 'x.'  Two
**              private functions are used to determine if x or o have won
**              the game.  A default constructor is declared as well as a
**              functions to return the gameState, move X, move O and print
**              the game board to the console.
***************************************************************************/

#ifndef FBOARD_HPP
#define FBOARD_HPP

//delcaration of a new enumerated type 'gameState'
enum gameState {X_WON, O_WON, UNFINISHED};

//Defines the interface of the FBoard class
class FBoard
{
   private:            
	   char boardArr[8][8];  //declare 8x8 array of characters.
	   enum gameState status;  //declare enumerated gameState type
	   int xRow;               //row tracking for x piece.
	   int xCol;               //column tracking for x piece.
	   void isXTrapped();   //a function to determine if x has remaining legal moves
	   void hasXWon();   //a private function to determine if x has won.
   public:            
      FBoard();     //default constructor 
      gameState getGameState();
	  bool moveX(int moveXRow, int moveXCol);
	  bool moveO(int moveOFromRow, int moveOFromCol, int moveOToRow, int moveOToCol);
	  void printer();
};
#endif

