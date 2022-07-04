/***********************************************************************
* Program:
*    Assignment 12, Input & Variables
*    Brother Ridges, CS124
* Author:
*    Jeremy Johnson
* Summary: 
*    This program is designed to request input from the user, store
*    it in a variable, and then output the result to the display
*    in the context of the prescribed sentence.
*
*    Estimated:  0.5 hrs   
*    Actual:     0.5 hrs
*      The most difficult part of this assignment for me was the stress
*      of making sure the formatting was exactly correct.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * This function requests the monthly income amount from the user, then
 * stores the user's response in a variable. The variable is used within
 * a prescribed sentence which is then displayed for the user to see.
 ***********************************************************************/
int main()

{
   // Declare the variable
   float income;

   // Prompt the user for the monthly income amount
   cout << "\tYour monthly income: "; cin >> income;

   // Configure the display always display the decimal to 2 places.
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   // Display the results
   cout << "Your income is: $" << setw(9) << income << "\n";

   //Return when the program's function is complete.
   return 0;
}
