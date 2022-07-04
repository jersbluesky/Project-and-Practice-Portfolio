/***********************************************************************
* Program:
*    Assignment 41, Allocating Memory
*    Brother Ridges, CS124
* Author:
*    Jeremy Johnson
* Summary: 
*    This program prompts the user for a number of characters in a 
*    string, allocates that string to a sufficient length, 
*    then takes an input from the user and displays that input
*    back to the user.
*
*    Estimated:  1.0 hrs   
*    Actual:     3.0 hrs
*      After having read through the book again, this was actually 
*      pretty easy. The most difficult part was just assimilating 
*      the idea of memory allocation into the actual code.
************************************************************************/
#include <iostream>
#include <cassert>
using namespace std;

// I finally understand the concept of prototypes!!!
int getNumCharacters();
int * allocate(const int numItems);
char promptForInput(char userString[]);
void displayInput(char string[], int numChars);

/*************************************************
 * The main function brings calls the other functions.
 * It also returns 0 if the list is null.
 ************************************************/ 
int main()
{
   int numChars = getNumCharacters();   
   int * list = allocate(numChars);
   if (list == NULL)
   {
      return 0;
   }

   char userInput[256];
   promptForInput(userInput);
   displayInput(userInput, numChars);

   delete [] list;
   list = NULL;
   return 0;
}


/*************************************************
 * The getNumCharacters fuction prompts the user
 * for a number of characters and returns it 
 * for further use.
 ************************************************/ 
int getNumCharacters()
{
   int numChars;
   cout << "Number of characters: ";
   cin >> numChars;
   if (numChars < 1)
   {
      cout << "Allocation Failure!";
   }
   return numChars;
}

/*************************************************
 * This was the tough one. The allocate function
 * sets aside the memory for the further use
 * and puts it in an array.
 ************************************************/ 
int * allocate(const int numItems)
 // allocate the memory
 char * text = new(nothrow) char [numItems + 1]; // allocate one more for \0
 if (!text) // same as “if (text != NULL)”
 cout << "Allocation Failure!\n"; // should return because we 
   return ;
}

/*************************************************
 * This simply prompts the user for text and
 * places it in a variable that is 
 * returned as a pointer.
 ************************************************/ 
char promptForInput(char userString[])
{
   cout << "Enter Text: ";
   cin.ignore();
   cin.getline(userString, 256);
   return * userString;
}

/*************************************************
 * THis displays the output.
 ************************************************/ 
void displayInput(char string[], int numChars)
{
   cout << "Text: ";
   for (int i = 0; i < numChars; i++)
   {
      cout << string[i];
   }
   cout << '\n';
   return;
}