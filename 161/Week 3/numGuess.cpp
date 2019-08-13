/******************************************************************** 
** Author: Andrew Clos
** Date: 04/15/2019
** Description: Assignment 3c (numGuess). This program will prompt
**              the user to enter an integer number that will be
**              guessed by a user.  As the user then enters guesses
**              the program will tell the user if the guess is too 
**              high or too low and count the number of guesses.
*********************************************************************/ 

#include <iostream>

using std::cout;             //using three different std names.
using std::cin;
using std::endl;

int main () 
{
   int mysteryNum, numGuess = 0, userGuess;    //declare/initialize variables
  
   cout << "Enter the number for the player to guess." << endl;
   cin >> mysteryNum;            //user specifies number
   cout << "Enter your guess." << endl;

   do                           //post-test check since this is a guessing game 
   {
      cin >> userGuess;                //stores user guess as integer
      numGuess = numGuess + 1;         //increment guess count.
      if (userGuess == mysteryNum)   //check for correct guess
      {   
         cout << "You guessed it in " << numGuess << " tries." << endl;
      }
      else if (userGuess < mysteryNum)  //guess is low
      {
         cout << "Too low - try again." << endl;
      }
      else                         //guess is high
         cout << "Too high - try again." << endl;
      
   } while (userGuess != mysteryNum); //re-runs loop if guess is wrong.
     
   return 0;
}
