/***********************************************************************
* Program:
*    Project 04, Monthly Budget 
*    Brother Ridges, CS124
* Author:
*    Jeremy Johnson
* Summary: 
*    This is a program that allows the user to enter in their income
*    and expenses, then displays that information in an orderly
*    logical table format. It will also automatically compute donations
*    and taxes, the 'other' category, and the difference. This version
*    computes taxes based on a formula provided for the project. Didn't
*    we all just love thinking about taxes all week?
*
*    Estimated:  2.0 hrs   
*    Actual:     2.0 hrs
*      The most difficult part of this assignment was isolating the`
*      tax code into a separate program, creating it based on the
*      psuedocode from the assignment, and then re-assimilating it
*      into the program itself. 
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * These first set of functions get input from the user,
 * then return that input into a declared variable.
 ***********************************************************************/

/**********************************************************************
 * Get the income.
 ***********************************************************************/
double getIncome()
{
   double monthlyIncome;
   cout << "\tYour monthly income: ";   // Prompt
   cin  >> monthlyIncome;   // Get
   return monthlyIncome;   // Return
   cout << endl;
}

/**********************************************************************
 * Get the budgeted living expenses.
 ***********************************************************************/
double getBudgetLiving()
{
   double budgetLiving;
   cout << "\tYour budgeted living expenses: "; // Prompt
   cin  >> budgetLiving;                        // Get
   return budgetLiving;                       // Return
}

/**********************************************************************
 * Get the actual living expenses.
 ***********************************************************************/
double getActualLiving()
{
   double actualLiving;
   cout << "\tYour actual living expenses: "; // Prompt
   cin  >> actualLiving;                      // Get
   return actualLiving;                       // Return
}

/**********************************************************************
 * Get the actual taxes withheld.
 ***********************************************************************/
double getActualTax()
{
   double actualTax;
   cout << "\tYour actual taxes withheld: "; // Prompt
   cin  >> actualTax;                      // Get
   return actualTax;                       // Return
}

/**********************************************************************
 * Get the actual donations paid.
 ***********************************************************************/
double getActualDonation()
{
   double actualDonation;
   cout << "\tYour actual donation offerings: "; // Prompt
   cin  >> actualDonation;                      // Get
   return actualDonation;                       // Return
}

/**********************************************************************
 * Get the actual other expenses.
 ***********************************************************************/
double getActualOther()
{
   double actualOther;
   cout << "\tYour actual other expenses: "; // Prompt
   cin  >> actualOther;                      // Get
   return actualOther;                       // Return
}

/**********************************************************************
 * Compute the taxes based on the income (currently set at $0)
 ***********************************************************************/
double computeTax(double monthlyIncome)
{ 
   double yearlyTax;
   double yearlyIncome = monthlyIncome * 12.00;

   if (yearlyIncome < 15100)
      yearlyTax = yearlyIncome * 0.10;
   else if ((yearlyIncome < 61300)  && (yearlyIncome >= 15100))
      yearlyTax = 1510 + 0.15 * (yearlyIncome - 15100);
   else if ((yearlyIncome < 123700) && (yearlyIncome >= 61300))
      yearlyTax = 8440 + 0.25 * (yearlyIncome - 61300);
   else if ((yearlyIncome < 188450) && (yearlyIncome >= 123700))
      yearlyTax = 24040 + 0.28 * (yearlyIncome - 123700);
   else if ((yearlyIncome < 336550) && (yearlyIncome >= 188450))
      yearlyTax = 42170 + 0.33 * (yearlyIncome - 188450);
   else
      yearlyTax = 91043 + 0.35 * (yearlyIncome - 336550);

   double monthlyTax = yearlyTax / 12.00;
   return monthlyTax;
}

/**********************************************************************
 * Compute Donation for the budgeted Donation line.
 ***********************************************************************/
double computeDonation(double monthlyIncome)
{
   return (monthlyIncome / 10.00);
}



/**********************************************************************
 * This second section calls the compute functions and sets the output
 * display for the user.
 ***********************************************************************/
int display (double monthlyIncome, double budgetLiving, double actualTax, 
   double actualDonation, double actualLiving, double actualOther)
{ 
        // Set output for MONEY
   cout.setf(ios::fixed);        // no scientific notation
   cout.setf(ios::showpoint);    // always show the decimal
   cout.precision(2);            // always display in two variables.

   double budgetTax = computeTax(monthlyIncome);
   double budgetDonation = computeDonation(monthlyIncome);
   double budgetOther = monthlyIncome - budgetTax - budgetDonation - 
      budgetLiving;
   double actualDifference = monthlyIncome - actualTax - actualDonation 
      - actualLiving - actualOther;
   double budgetDifference = 0;
        
   // Output:

   // Introduce the output to the user:
   cout << "The following is a report on your monthly expenses\n";

   // The table-header:
   cout << "\tItem                  Budget          Actual" << endl;

   cout << "\t=============== =============== ===============" << endl;

   // Creating rows and columns: For row, cout.setf() is used to 
   // define the justification, cout.width() is used to set spacing,
   // and the amounts and variables are placed within that context
   // to produce an orderly table. 


   // FIRST ROW

   cout.setf(ios::left);
   cout.width(17);
   cout << "\tIncome";

   cout.unsetf(ios::left);
   cout << "$";

   cout.setf(ios::right);
   cout.width(11);
   cout << monthlyIncome;
   cout.unsetf(ios::right);

   cout.setf(ios::right);
   cout.width(5);
   cout << "$";
   cout.unsetf(ios::right);

   cout.setf(ios::right);
   cout.width(11);
   cout << monthlyIncome;
   cout.unsetf(ios::right);

   cout << endl;


   // SECOND ROW

   cout.setf(ios::left);
   cout.width(17);
   cout << "\tTaxes";

   cout.unsetf(ios::left);
   cout << "$";

   cout.setf(ios::right);
   cout.width(11);
   cout << budgetTax;
   cout.unsetf(ios::right);

   cout.setf(ios::right);
   cout.width(5);
   cout << "$";
   cout.unsetf(ios::right);

   cout.setf(ios::right);
   cout.width(11);
   cout << actualTax;
   cout.unsetf(ios::right);

   cout << endl;


   // THIRD ROW

   cout.setf(ios::left);
   cout.width(17);
   cout << "\tDonation";

   cout.unsetf(ios::left);
   cout << "$";

   cout.setf(ios::right);
   cout.width(11);
   cout << budgetDonation;
   cout.unsetf(ios::right);

   cout.setf(ios::right);
   cout.width(5);
   cout << "$";
   cout.unsetf(ios::right);

   cout.setf(ios::right);
   cout.width(11);
   cout << actualDonation;
   cout.unsetf(ios::right);

   cout << endl;


   // FOURTH  ROW

   cout.setf(ios::left);
   cout.width(17);
   cout << "\tLiving";

   cout.unsetf(ios::left);
   cout << "$";

   cout.setf(ios::right);
   cout.width(11);
   cout << budgetLiving;
   cout.unsetf(ios::right);

   cout.setf(ios::right);
   cout.width(5);
   cout << "$";
   cout.unsetf(ios::right);

   cout.setf(ios::right);
   cout.width(11);
   cout << actualLiving;
   cout.unsetf(ios::right);

   cout << endl;


   // FIFTH  ROW

   cout.setf(ios::left);
   cout.width(17);
   cout << "\tOther";

   cout.unsetf(ios::left);
   cout << "$";

   cout.setf(ios::right);
   cout.width(11);
   cout << budgetOther;
   cout.unsetf(ios::right);

   cout.setf(ios::right);
   cout.width(5);
   cout << "$";
   cout.unsetf(ios::right);

   cout.setf(ios::right);
   cout.width(11);
   cout << actualOther;
   cout.unsetf(ios::right);

   cout << endl;


   // Barrier

   cout.width(0);
   cout << "\t=============== =============== ===============" << endl;


   // DIFFERENCE ROW
   cout.setf(ios::left);
   cout.width(17);
   cout << "\tDifference";

   cout.unsetf(ios::left);
   cout << "$";

   cout.setf(ios::right);
   cout.width(11);
   cout << budgetDifference;
   cout.unsetf(ios::right);

   cout.setf(ios::right);
   cout.width(5);
   cout << "$";
   cout.unsetf(ios::right);

   cout.setf(ios::right);
   cout.width(11);
   cout << actualDifference;
   cout.unsetf(ios::right);

   cout << endl;
   
   return 0;
}

/**********************************************************************
 * The main function introduces the program and calls the different
 * functions as required.
 ***********************************************************************/
int main()
{
 //Introduce the program and instruct the user:

   cout << "This program keeps track of your monthly budget\n";
   cout << "Please enter the following:\n";

   // Below section calls the 'get' functions.
   
   double monthlyIncome = getIncome();
   double budgetLiving = getBudgetLiving();
   double actualLiving = getActualLiving();
   double actualTax = getActualTax();
   double actualDonation = getActualDonation();
   double actualOther = getActualOther();
   cout << endl;

   // Call the display function to output the information
   // to the user.
   display(monthlyIncome, budgetLiving, actualTax, actualDonation, 
      actualLiving, actualOther);

   return 0;
   
}
