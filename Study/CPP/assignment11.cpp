/************************************************************************
 * Program:
 *    Assignment 11, Output
 *    Brother Ridges, CS124
 * Author:
 *   Jeremy Johnson
 *Summary:
 *   This program puts items and values for a budget into columns and 
 *   lines using the iomanip library and associated commands. I certainly
 *   miss the days where living expense was $650.
 *
 *
 *   Estimated:  1.0 hrs
 *   Actual:     3.0 hrs
 *     There were a lot of difficult aspects of this assignment for me. I
 *     know that I could have sought help, but I felt like discovering
 *     my own way to complete the assignment led me to learn a lot more,
 *     in this case. 
 ************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * This main function is designed to pull values from the variables and
 * follow the commands listed to place them neatly in a table. 
 ***********************************************************************/
int main()
{

//It's easier to set the numbers to float if they are encapsulated in variables! :)

   float income = 1000;
float taxes = 100;  
float tithing = 100; 
float living = 650;
float other = 90;
float delta = income - taxes - tithing - living - other;


   // OUTPUT for MONEY
   cout.setf(ios::fixed);     // no scientific notation
   cout.setf(ios::showpoint); // always show the decimal 
   cout.precision(2);         // always in two decimals!

   
   cout << "\tItem"
   << setw(20) << "Projected"
   << endl;

   cout << "\t============="
   << setw(12) << "=========="
   << endl;

   //ROWS and COLUMNS: 
   //All of the rows are separated into 3 columns. The dollar sign needed to be a fixed point against which I was able to justify the dollar amount.
   //Third column is the dollar amount. 

   // FIRST ROW
   cout.setf(ios::left);
   cout.width(16);
   cout << "\tIncome";

   cout.unsetf(ios::left);
   cout << "$";

   cout.setf(ios::right);
   cout.width(9);
   cout << income;
   cout.unsetf(ios::right);

   cout << endl;
   
   // SECOND ROW

   cout.setf(ios::left);
   cout.width(16);
   cout << "\tTaxes";

   cout.unsetf(ios::right);
   cout << "$";

   cout.setf(ios::right);
   cout.width(9);
   cout << taxes;
   cout.unsetf(ios::right);

   cout << endl;

   // THIRD ROW

   cout.setf(ios::left);
   cout.width(16);
   cout << "\tTithing";

   cout.unsetf(ios::right);
   cout << "$";

   cout.setf(ios::right);
   cout.width(9);
   cout << tithing;
   cout.unsetf(ios::right);

   cout << endl;

   // FOURTH ROW

   cout.setf(ios::left);
   cout.width(16);
   cout << "\tLiving";

   cout.unsetf(ios::right);
   cout << "$";

   cout.setf(ios::right);
   cout.width(9);
   cout << living;
   cout.unsetf(ios::right);

   cout << endl;   

   // FIFTH ROW

   cout.setf(ios::left);
   cout.width(16);
   cout << "\tOther";

   cout.unsetf(ios::right);
   cout << "$";

   cout.setf(ios::right);
   cout.width(9);
   cout << other;
   cout.unsetf(ios::right);

   cout << endl;

   cout.width(0);
   cout << "\t=============  ==========\n";


   // DELTA ROW

   cout.setf(ios::left);
   cout.width(16);
   cout << "\tDelta";

   cout.unsetf(ios::right);
   cout << "$";

   cout.setf(ios::right);
   cout.width(9);
   cout << delta;
   cout.unsetf(ios::right);

   cout << endl;\

return 0;

}

