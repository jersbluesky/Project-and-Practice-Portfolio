/***********************************************************************
* Program:
*    Project 07, Calendar 
*    Brother Ridges, CS124
* Author:
*    Jeremy Johnson
* Summary: 
*    This program, when completed, will output a calendar according
*    to the users month and year selection. After 30 hours of work,
*    this program also causes the coder to weep uncontrollably
*    when the testBed passes with no errors.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/*************************************************
 * This function will prompt the user for the month
 * and put that value into the 'month' variable.
 ************************************************/

int promptMonth() {

   // SET the month variable.
   int month;
   int userMonthSelection;
   // PROMPT the user for the month number
   cout << "Enter a month number: ";
   // SET the variable to the integer value from the user input
   cin >> userMonthSelection;
   while ((userMonthSelection < 1) || (userMonthSelection > 12)) {
      cout << "Month must be between 1 and 12.\n";
      cout << "Enter a month number: ";
      cin >> userMonthSelection;
   }
      month = userMonthSelection;

   // RETURN the month so it can be used in other functions
   return month;
}

/*************************************************
 * This function will prompt the user for the year
 * and put that integer value into the 'year' variable.
 ************************************************/

int promptYear() {
   // SET the month variable.
   int year;
   int userYearSelection;
   // PROMPT the user for the month number
   cout << "Enter year: ";
   // SET the variable to the integer value from the user input
   cin >> userYearSelection;
   while (userYearSelection < 1753) {
      cout << "Year must be 1753 or later.\n";
      cout << "Enter year: ";
      cin >> userYearSelection;
   }
      year = userYearSelection;

   // RETURN the month so it can be used in other functions
   return year;
}

/*************************************************
 * This function will determine if the selected year
 * is a leap year. It is a boolean function, so it
 * will return 'true' or 'false' only. It will use
 * the 'year' parameter.
 ************************************************/

bool isLeapYear(int year) {
   // According to the rules of the Gregorian calendar, 
   // a leap year is every 4 years, unless that year is both
   // divisible by 100 but not divisible by 400. This accounted for
   // below in the context of an 'if' statement, returning either
   // 'true' or 'false'.
   if ((year % 4 == 0) && (year % 100 == 0) && (year % 400 != 0)) {
      return false;
   }
   else if (year % 4 != 0) {
      return false;
   }
   else {
      return true;
   }
}

/*************************************************
 * This function counts the leap days, so that they
 * may be added in later functions. 
 ************************************************/
int countLeapDays (int year) {

   // SET the 'i' and 'leapDays' variables
   // The 'leapDays' variable is set to '0', as the loop
   // will be iterating by ones from there.
   int i;
   int leapDays = 0;

   // First, we loop through every year since 1757. 
   for (i = 1753; i <= year-1; i++) {
      // Here, we increment the leap days based on if the day is
      // divisible by 4, using the 'mod' operator. That number
      // is placed in the 'leapDays' variable. If it is not
      // divisible by 4, we output nothing, and allow the loop
      // to restart.
      if (i % 4 == 0) {
         leapDays++;
      }
      else {
         cout << "";
      }
   }

   // Because of the aforementioned rule, we have to
   // subtract the days that are divisible by 4 and 100,
   // but not divisible by 400. This is done in the same
   // basic manner as the last 'for' loop, but decrementing 
   //from 'leapDays' instead of incrementing.
   for (i = 1753; i <= year-1; i++) {
      if ((i % 100 == 0) && (i % 400 != 0)) {
         leapDays--;
      }
      else {
         cout << "";
      }
   }

   // The final number of leap days is returned in the variable 'leapDays'
   // for use by other functions.
   return leapDays;
}

/*************************************************
 * This will count the number of days in the selected
 * year, MINUS the selected month. We aren't including
 * the selected month, because in a future function, the
 * remainder of the total count of days is calculated based
 * on all days from 1753 up until the month PREVIOUS to 
 * the month selected divided by 7 (days in the week). 
 * It will need parameters of 'month', and--if february
 * is selected, it will need to account for whether or not
 * it is a leap year, so the 'leapYear' bool parameter is
 * referenced.
 ************************************************/
int numDaysInYear(int month, bool leapYear, int year) {

   // The 'daysInYear' variable is set at '0', to make
   // sure no other integer is called for the first month
   // selection.
   int daysInYear = 0;
   // Each month (except February) is set at their number
   // of days. This is done to help with clarity in the 
   // actual calculation in which the numbers must be 
   // counted.
   int jan = 31;
   int mar = 31;
   int apr = 30;
   int may = 31;
   int jun = 30;
   int jul = 31;
   int aug = 31;
   int sep = 30;
   int oct = 31;
   int nov = 30;
   int dec = 31;

   // As mentioned before, February is either 28 or 29 days. 
   // This is accounted for by pulling in the leapYear boolean
   // variable, and placing it within an 'if' statement.
   int feb;
   if (leapYear == true) {
      feb = 29;
   }
   else {
      feb = 28;
   }



   // As mentioned above, the count is taken from the previous
   // month in the year, if applicable, for use in the offset
   // calculation. This is accomplished using 'if' and 'else if'
   // statements.
   if (month == 1) {
      daysInYear = 0;
   }
   else if (month == 2) {
      daysInYear = jan;
   }
   else if (month == 3){
      daysInYear = jan + feb;
   }
   else if (month == 4){
      daysInYear = jan + feb + mar;
   }
   else if (month == 5){
      daysInYear = jan + feb + mar + apr;
   }
   else if (month == 6){
      daysInYear = jan + feb + mar + apr + may;
   }
   else if (month == 7){
      daysInYear = jan + feb + mar + apr + may + jun;
   }
   else if (month == 8){
      daysInYear = jan + feb + mar + apr + may + jun + jul;
   }
   else if (month == 9){
      daysInYear = jan + feb + mar + apr + may + jun + jul + aug;
   }
   else if (month == 10){
      daysInYear = jan + feb + mar + apr + may + jun + jul + aug + sep;
   }
   else if (month == 11){
      daysInYear = jan + feb + mar + apr + may + jun + jul + aug + sep + oct;
   }
   else if (month == 12) {
      daysInYear = jan + feb + mar + apr + may + jun + jul + aug + sep + oct + nov;
   }


   // The final number of days in the selected year is returned in the 
   // variable 'daysInYear' for use by other functions.
   return daysInYear;
    
}

/*************************************************
 * This function is intended to separately determine
 * the number of days since 1753, other than the selected
 * year. In order to accomplish this, it needs the 
 * 'year' and 'leapDays' parameters.
 ************************************************/
int numDaysOtherThanSelectedYear(int year, int leapDays){

// SET the 'numYears' and 'numDaysMinusLeap; variables 
// for calculation, and the 'countDays' variable to retrieve 
// the return value.
int numYears;
int numDaysMinusLeap;
int countDays;

   // Calculate the number of years since 1753 by
   // subtracting the 1753 from the selected year.
   numYears = year - 1753;
   // Get the number of days minus the leap year by
   // multiplying the number of years by 365.
   numDaysMinusLeap = numYears * 365;
   // Get the total number of days by adding the
   // number of days minus the leap year with the
   // calculated number of leap days.
   countDays = numDaysMinusLeap + leapDays;

   // The total count of days necessary to determine
   // the offset is returned in the 'countDays' variable.
   return countDays;

}

/*************************************************
 * This function determines the number of days that
 * are offset for the first day of the selected
 * month. It utilized the 'countDays' parameter and
 * the 'daysInYear' parameter to accomplish this.
 ************************************************/
int computeOffset(int countDays, int daysInYear) {

   // The aforementioned offset is set by determining
   // the number of days since 1753 (Where day 1 was 
   // offset at '0'), to the selected month and year and
   // taking the remainder.
   int offset = (countDays + daysInYear) % 7;


   // This 'offset' variable is returned to be used in the
   // 'displayTable' function.
   return offset;

}

/*************************************************
 * This is a separate function to determine the 
 * number of days in the selected month. It requires
 * the 'month', 'year', and 'leapYear' parameters.
 ************************************************/
int numDaysInMonth(int month, bool leapYear) {

   // SET numDaysInSelectedMonth parameter for the return value.
   int numDaysInSelectedMonth;

   // 'if' statements are utilized based on the month number to determine the number of days
   // in the selected month. February is a separate 'if' statement, due to leap years.
   if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) 
   || (month == 10) || (month == 12)) {
      numDaysInSelectedMonth = 31;
   }

   else if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) {
      numDaysInSelectedMonth = 30;
   }

   else if ((month == 2) && (leapYear == true)) {
      numDaysInSelectedMonth = 29;
   }

   else {
        numDaysInSelectedMonth = 28;
   }

   // cout << "Number of days in selected month: " << numDaysInSelectedMonth << endl;

   return numDaysInSelectedMonth;
   
}


/*************************************************
 * This function takes all of the values and uses them
 * to display the month name, year, and calendar table
 * on the screen for the user. It needs the 'offset',
 * 'daysInMonth', and 'year' parameters.
 ************************************************/
void displayTable(int offset, int daysInMonth, int month, int year) {
   
   // The 'alignment' variable is set, which will provide
   // the number of spaces needed based on the offset.
   int alignment;
   // The 'newLine' variable is set, which is also based
   // on the offset, to determine when the first line 
   // should stop and the second line should begin.
   int newLine;
   // The 'i' variable is set, to be used in a 'while' loop 
   // later in the function.
   int i = 1;

   // These 'if' statements connect the alignment and newLine
   // values with the offset, which will be used in correctly
   // outputting the spacing for the calendar table.
   if (offset == 6) {
      alignment = 4;
      newLine = 7;
   }
   else if (offset == 0) {
      alignment = 8;
      newLine = 6;
   }
   else if (offset == 1) {
      alignment = 12;
      newLine = 5;
   }
   else if (offset == 2) {
      alignment = 16;
      newLine = 4;
   }
   else if (offset == 3) {
      alignment = 20;
      newLine = 3;
   }
   else if (offset == 4) {
      alignment = 24;
      newLine = 2;
   }
   else if (offset == 5) {
     alignment = 28;
     newLine = 1;
   }

   // These 'if' and 'else if' statements simply
   // output the month name based on the user month
   // selection.
   if (month == 1) {
      cout << "\nJanuary, " << year << endl;
   }
   else if (month == 2) {
      cout << "\nFebruary, " << year << endl;
   }
   else if (month == 3) {
      cout << "\nMarch, " << year << endl;
   }
   else if (month == 4) {
      cout << "\nApril, " << year << endl;
   }
   else if (month == 5) {
      cout << "\nMay, " << year << endl;
   }
   else if (month == 6) {
      cout << "\nJune, " << year << endl;
   }
   else if (month == 7) {
      cout << "\nJuly, " << year << endl;
   }
   else if (month == 8) {
      cout << "\nAugust, " << year << endl;
   }
   else if (month == 9) {
      cout << "\nSeptember, " << year << endl;
   }
   else if (month == 10) {
      cout << "\nOctober, " << year << endl;
   }
   else if (month == 11) {
      cout << "\nNovember, " << year << endl;
   }
   else {
      cout << "\nDecember, " << year << endl;
   }

   // This outputs the days of the month with the
   // prescribed spacing.
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";

   // *********LINE #1**************
   
   // This outputs the first day of the month
   // utilizing the pre-determined offset as 
   // converted into an alignment within the 
   // alignment variable. The 'flush' indication
   // forces the next output to be displayed
   // horizontally.
   cout << setw(alignment) << 1;
   
   
   // A loop created to increment up until the 
   // integer set in the 'newLine' variable, which
   // is determined by the offset variable.
   while (i < newLine) {
       i++;
       // Output is always set, right-aligned to 
       // 4 spaces. The 'flush' indicates that 
       // 'i' must be listed horizontally, not 
       // vertically.
       cout << setw(4) << i;
   }

   // Here, a new line must be set.
   cout << "\n";

   // *********LINE #2**************   

   // The variable 'i' is replaced with 'j' on the 
   // second line, for clarity purposes.
   int j = i;

   // The same loop is set here and on the third line, 
   // with the difference being that each of these lines
   // will have 7 days, so that is the limitation of the loop.
   while (j < (i + 7)) {
       j++;
       cout << setw(4) << j;
   }

   // Here, a new line must be set.
   cout << "\n";

   // *********LINE #3**************

   // The variable 'j' is replaced with 'k' on the 
   // second line, for clarity purposes.   
   int k = j;

   // See comments for line 2.
   while (k < (j + 7)) {
       k++;
       cout << setw(4) << k;
   }

   // Here, a new line must be set.
   cout << "\n";

   // *********LINE #4**************

   // The variable 'k' is replaced with 'l' on the 
   // second line, for clarity purposes.   
   int l = k;

   // This line is set to end either when l reaches
   // the number of the previous line plus 7, or 
   // when it reaches the the total days in the month.
   while ((l < (k + 7)) && (l < daysInMonth)) {
       l++;
       cout << setw(4) << l;
   }
   

   // *********LINE #5**************

   // The variable 'm' is replaced with 'l' on the 
   // second line, for clarity purposes.   
   int m = l;

   // Here, a new line must be set.
   cout << "\n";


   // This line is set to end either when m reaches
   // the number of the previous line plus 7, or 
   // when it reaches the the total days in the month.
   // **NOTE**: This loop will only activate if the
   // previous line didn't reach the value associated
   // with 'daysInMonth'.
   while ((m < (l + 7)) && (m < daysInMonth)) {
       m++;
       cout << setw(4) << m;
   }

   // *********LINE #6**************

   // The variable 'm' is replaced with 'l' on the 
   // second line, for clarity purposes. 
   int n = m;

   // Here, a new line must be set.
   cout << "\n";


   // Due to the different nature of this method of 
   // output, exception had to be made for if there
   // were a line 6. Thus, the code below runs based
   // on specific parameters.


   if ((m == 29) && (month != 2)) {
      cout << "  30  31\n";
   }
   else if ((m == 30) && (month != 4) && (month != 6) && (month != 9) && (month != 11)) {
      cout << "  31\n";
   }
   else{
      cout << "";
   }

   // Return value is blank, because the function
   // is a 'void' function.
   return;
}

/*************************************************
 * The 'main' function will set all necessary variables,
 * then call all necessary functions for the correct
 * processing of the calendar program.
 ************************************************/
int main()
{

   // All variables that must be returned by the 
   // functions are set here. 
   int month;
   int year;
   bool leapYear;
   int leapDays;
   int numDaysInSelectedMonth;
   int daysInYear;
   int countDays;
   int offset;
   int daysInMonth;

   // All functions that are necessary for the 
   // calendar function to run correctly are called here.
   month = promptMonth();
   year = promptYear();
   leapYear = isLeapYear(year);
   leapDays = countLeapDays(year);
   numDaysInSelectedMonth = numDaysInMonth(month, leapYear);
   daysInYear = numDaysInYear(month, leapYear, year);
   countDays = numDaysOtherThanSelectedYear(year, leapDays);
   offset = computeOffset(countDays, daysInYear);
   daysInMonth = numDaysInMonth(month, leapYear);

   // This will display the result of all functions on the 
   // for the user to see.
   displayTable (offset, daysInMonth, month, year);

   // The 'main' function always returns '0'.
   return 0;

}