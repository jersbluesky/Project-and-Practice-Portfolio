/***********************************************************************
* Program:
*    Assignment 31, Array Design
*    Brother Ridges, CS124
* Author:
*    Jeremy Johnson
* Summary: 
*    This program will prompt the user for a list of 10 grades,
*    place those numbers in an array, then output the average
*    of those grades for the user. If the user enters -1, then
*    it indicates the assignment wasn't turned in, and that 
*    grade doesn't count against the average.
*
*    Estimated:  1.0 hrs   
*    Actual:     3.0 hrs
*      The most difficult part was determining how to effectively
*      pass the array into the average function. 
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

#define ASIZE 10

/*************************************************
* This function will get the grades from the user
* and put them into an array.
************************************************/
int getGrades(int grades[], int& n) 
{

// 'n' is initially set at 10, so the user can
// enter in all 10 inputs.
   n = 10;

// gradeEntry is a buffer variable, where the
// input will initially be entered to test
// whether or not it is -1.
   int gradeEntry;

// The 'gradeCount' variable will be used to
// clarify the grade the user is on when
// inputting the values.
   int gradeCount = 1;


// This for loop will get input from the user,
// test whether or not it is -1, and if it
// is not, it will place the value in the
// 'grade' array.
   for (int i = 0; i < n; ++i)
   {
      cout << "Grade " << gradeCount << ": ";
      cin >> gradeEntry;
      if (gradeEntry != -1) 
      {
         grades[i] = gradeEntry;
      }
// If the value IS in fact -1, then the value will
// not count be added to the array, the 'i' variable
// will go back one number (so the grade can be entered
// into the next spot in the array), and the total number
// of spots (n) in the array will be reduced by 1.
      else 
      {
         i--;
         n--;
      }
// This will move the value up from 1, regardless of the
// 'n' or 'i' values.
      gradeCount++;
   }

// 'n' is returned, changed by the previous loop, to be
// used in the 'average' function, as the new numbers of
// items in the array.
   return n;

}

/*************************************************
* This function will pull reference back to the
* 'grades' array and the pull the 'n' variable
* from the previous function. It will then calculate
* the average, based on the summation of variables
* divided by the number of items in the array.
************************************************/
int getAverage(int grades[], int n) 
{
   int average;
   int sum = 0;
   for (int i = 0; i < n; i++)
   {
      sum += grades[i]; // this adds the values in the array.
   }

   average = sum / n;

   return average;
}

/*************************************************
* This main function sets the 'n' variable, the
* grade array as a variable, and then calls the
* 'getGrades' function. It then determines if
* an average can be obtained, by testing whether
* or not there are any items in the array. If there
* aren't, it will output ---%. Otherwise, it
* outputs the average by calling the 'average'
* function.
************************************************/
int main() 
{
   int n = ASIZE;
   int grades[ASIZE];
   getGrades(grades, n);
   
   if (n == 0) 
   {
      cout << "Average Grade: ---%\n";
   }
   else 
   {
      int average = getAverage(grades, n);
      cout << "Average Grade: " << average << "%\n";
   }
   return 0;
}