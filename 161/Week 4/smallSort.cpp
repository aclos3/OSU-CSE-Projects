/********************************************************************* 
** Author: Andrew Clos
** Date: 04/23/2019
** Description: Assignment 4b (smallSort)
*********************************************************************/

#include<iostream>

void smallSort(int &first, int &second, int &third); //funtion prototype 
/*
int main()
{
   int fir = 1,
      sec = 3,
      thir = 2;
      smallSort(fir, sec, thir);
      cout << fir << " " << sec << " " << thir << endl;       
   
return 0;
}
*/

/********************************************************************* 
** Description: This function will take three integers by reference,  
** sort them in ascending order and return them.
*********************************************************************/ 

void smallSort(int &first, int &second, int &third) 
{
   if (first > second) {         
      if (first > third) {        //true if first is largest overall
         if (second > third) {    //true if third is smallest overall
            int temp = third;
            third = first;
            first = temp;
         }
         else {               
            int temp = first;    //second is smallest overall
            first = second;
            second = third;
            third = temp;
         }    
      }
      else {                  //first > second, but first < third
         int temp = second;    
         second = first;
         first = temp;
      }
   }
   else if (first > third) {   //first > third, but < second
      int temp = third;
      third = second;
      second = first;
      first = temp;
   }     
   else if (second > third) { //first smallest, second > third
      int temp = third;
      third = second;
      second = temp;      
   } 
}         //outermost 'if' and 'if-else' statements are all false 
          //if the integers already arrive in ascending order.


