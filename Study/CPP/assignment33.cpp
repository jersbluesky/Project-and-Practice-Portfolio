/***********************************************************************
* Program:
*    Assignment 33, Pointers
*    Brother Ridges, CS124
* Author:
*    Jeremy Johnson
* Summary: 
*    This assignment prompts and assigns input from the user about
*    the amount Sam and Sue have in their respective accounts, and 
*    how much the date will cost. It then calculates with person has 
*    the most in their account, and makes them pay for the date. Now 
*    tell me why this isn't fair? :) I say we adopt this system.
*
*    Estimated:  1.0 hrs   
*    Actual:     2.5 hrs
*      Ironically, the most difficult part of this assignment was 
*      setting the spacing. I had to completely re-learn it. 
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/***********************************************************************
* The main function is the entire function for this assignment. It does
* what is outlined in the summary, above.
************************************************************************/
int main() 
{
   cout.setf(ios::fixed);        // no scientific notation
   cout.setf(ios::showpoint);    // always show the decimal
   cout.precision(2);            // always display in two variables.

   // Variables have to be set for everything that will account in the
   // the program, including the prices of each part of the date, 
   // the total date cost, the initial amount in Sam and Sue's resective 
   // accounts, and the pointer, or 'pAccount'.
   float dinner;
   float movie;
   float iceCream;
   float dateCost;
   float samsAccount;

   // Get the amounts from the user:
   cout << "What is Sam's balance? ";
   cin >> samsAccount;
   float suesAccount;
   cout << "What is Sue's balance? ";
   cin >> suesAccount;
   float * pAccount;

   // Width must be left-aligned and spacing must be set.
   // Each item is put into its own variable, and added 
   // at the end into the 'dateCost' variable.
   cout << "Cost of the date:\n";
   cout.setf(ios::left);
   cout.width(12);
   cout << "\tDinner: ";
   cout.width(12);
   cin >> dinner;
   cout << "\tMovie: ";
   cout.width(12);
   cin >> movie;
   cout << "\tIce cream: ";
   cin >> iceCream;   
   dateCost = dinner + movie + iceCream;

   // This 'if' statement puts the account balance of the person
   // with the highest account balance into the pointer, to be adjusted
   // in the following step.
   if (samsAccount > suesAccount)
   {
      pAccount = &samsAccount;
   }
   else
   {
      pAccount = &suesAccount;
   }

   // The amount that was placed in the pointer account is diminished by
   // the cost of the date, thus determining how much the person has after
   // the date is over.
   *pAccount -= dateCost;
   // We outout the amounts in the accounts. The account referenced by the
   // pointer is adjusted.  
   cout << "Sam's balance: $" << samsAccount << endl;
   cout << "Sue's balance: $" << suesAccount << endl;
   return 0;
}