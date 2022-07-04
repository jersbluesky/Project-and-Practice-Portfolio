/***********************************************************************
* Program:
*    Assignment 30, Array Syntax
*    Brother Ridges, CS124
* Author:
*    Jeremy Johnson
* Summary: 
*    This program will prompt the user for a list of 10 grades,
*    place those numbers in an array, then output the average
*    of those grades for the user.
*
*    Estimated:  1.0 hrs   
*    Actual:     3.0 hrs
*      I'm still getting caught up from missing a week, so the most
*      difficult part is still time--in other words, reading, practicing
*      and inputting within the alotted time frame. Nothing about this 
*      assignment was difficult after completing the reading. 
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/*************************************************
 * This function will get the grades from the user
 * and put them into an array.
 ************************************************/
float getGrades(){           

// Create the array with the assigned name;
   float grades[10];      
// Create a variable for the sum, to be used in the other function.
   float sum = 0.0;          


// This loop pulls input from the
// the 10 reserved spots in the array.
// the user, and places it into the
   for(int i = 0; i < 10; ++i)         
   {
      cout << "Grade "<< i + 1 << ": ";
      cin >> grades[i];
      sum += grades[i]; // this adds the values in the array.
   }
   
   // Sum is returned to be used in the 'getAverage' function.
   return sum;

}
/*************************************************
 * This function will determine the average
 * of the grades within the array.
 ************************************************/
float averageGrades(float sum) {
   // Average is first calculated in decimal form.
   float averageRaw = sum / 1000.00;
   // Average is converted to percentage format.
   float average = averageRaw * 100;
   // Average is returned, to be displayed by the 'main' function.
   return average;
}

/*************************************************
 * This function will call the previous functions
 * and display the result.
 ************************************************/
int main()
{
   // Call the 'getGrades' function to get the 'sum' variable.
   float sum = getGrades();
   // Call the 'averageGrades' function to get the average.
   float average = averageGrades(sum);
   // Display the average grade for the user.
   cout << "Average Grade: " << average << "%\n";

return 0;

}

