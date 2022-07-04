/***********************************************************************
* Program:
*    Assignment 13, Expressions
*    Brother Ridges, CS124
* Author:
*    Jeremy Johnson
* Summary: 
*    This assignment will take a user input in Fahrenheit and put
*    into a prescribed expression which will output a conversion
*    in Celsius.
*
*    Estimated:  0.5 hrs   
*    Actual:     1.0 hrs
*      The most difficult part of this assignment was simply
*      figuring out that, because I had declared the variable as 
*      a float, I needed to put a ".0" at the beginning of each
*      number in the expression.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * This will take an number from the user in Fahrenheit, plug that
 *  number into the given conversion expression, and display the 
 *  output in Celsius. Goal is 72 degrees Fahrenheit--that's 
 *  22 degrees Celsius--golden sunshine, and a nice, gentle breeze. 
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed); // no scientific notation
   cout.precision(0);     // display with no variables, but force-round

   // Declare the variable as a float number.
   float fahrenheit;

   // Input: User inputs degrees in Fahrenheit.

   cout << "Please enter Fahrenheit degrees: " ; cin >> fahrenheit;

   // Calculation and Output: number is placed in the expression
   // and the output is the conversion in degrees Celsius.

   cout << "Celsius: " << (5.0 / 9.0) * (fahrenheit - 32.0) << endl;


   return 0;

}
