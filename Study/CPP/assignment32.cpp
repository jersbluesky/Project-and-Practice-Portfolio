/***********************************************************************
* Program:
*    Assignment 32, Strings
*    Brother Ridges, CS124
* Author:
*    Jeremy Johnson
* Summary: 
*    This program will prompt the user for a letter and an input,
*    and it will count how many instances of that letter can
*    be found in that input.
*
*    Estimated:  0.75 hrs   
*    Actual:     1.0 hrs
*      The most difficult part of this assignment was 
*      figuring out why the program wouldn't let me put in
*      the second char[256].
************************************************************************/

#include <iostream>
#include <string.h>

using namespace std;

/**********************************************************************
 * This function counts the instances of the letter chosen by the 
 * user. It pulls the string array and letter from the main function.
 * It loops through the string array and tests the letters against
 * the chosen letter character. It then returns the number of reps.
 ***********************************************************************/
int countLetters(char letter, const char text[])
{
   int repetition = 0;
   for (int i = 0; i < 256; i++) // almost our second standard FOR loop
   {
      if (text[i] == letter) 
      {
         repetition++;
      }
   }

   return repetition;

}

/**********************************************************************
 * The main function get input from the user for a chosen letter, 
 * and also takes the string input from the user and places is 
 * in the string array.
 * It then calls the countLetters function to complete the task of
 * counting the number of instances per chosen letter.
 ***********************************************************************/
int main()
{
// get the letter to be counted
   char letter;
   cout << "Enter a letter: ";
   cin  >> letter;
   cin.ignore(); // ignore the space after the text is entered.

   // get the text
   char text[256];
   cout << "Enter text: ";
   cin.getline(text, 256);

   int repetition = countLetters(letter, text);

   cout << "Number of \'" << letter << "\'s: " <<  repetition << endl;
     


   return 0;
}
