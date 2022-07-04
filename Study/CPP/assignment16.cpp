/***********************************************************************
* Program:
*    Assignment 16, If Statements
*    Brother Ridges, CS124
* Author:
*    Jeremy Johnson
* Summary: 
*    This program will all a user to enter their yearly income, and
*    will output which tax bracket they are in.
*
*    Estimated:  0.5 hrs   
*    Actual:     1.0 hrs
*      The most difficult part of this assignment was figuring out
*      how to call the computeTax function within the main function.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * This function includes if/then statements that will determine
 * the tax bracket when called in the main function.
 ***********************************************************************/
int computeTax(double income)
{
   int taxBracket;   //set the variable


   // Create the algorithm of if/then statements.
   {
      if (income <= 15100.00)
         taxBracket = 10;

      else if (income > 15100.00 && income <= 61300.00)
         taxBracket = 15;

      else if (income > 61300.00 && income <= 123700.00)
         taxBracket = 25;

      else if (income > 123700.00 && income <= 188450.00)
         taxBracket = 28;

      else if (income > 188450.00 && income <= 336550.00)
         taxBracket = 33;

      else
         taxBracket = 35;

      return taxBracket;
   }
}

/**********************************************************************
 * This function will prompt the input from the user, call the 
 * "computeTax" function, then output the result for the user.
 ***********************************************************************/
int main()
{
   double income;   // Set the variable


   cout.setf(ios::fixed);        // no scientific notation
   cout.precision(0);            // always display in two variables.


   cout << "Income: "; cin >> income;  // Put the value in the variable
   int taxBracket = computeTax(income); // Call the function
   cout << "Your tax bracket is " << taxBracket << "%" << endl; //output.

   return 0;
}
