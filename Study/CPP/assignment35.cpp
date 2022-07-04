/***********************************************************************
* Program:
*    Assignment 35, Advanced Conditionals
*    Brother Ridges, CS124
* Author:
*    Jeremy Johnson
* Summary: 
*    This program takes and grade number entry from a user, and puts
*    it through two functions. The first function computers the letter
*    grade and the second computes the grade sign (+, -, or none) based
*    on criteria from the syllabus for cs124.
*
*    Estimated:  0.75 hrs   
*    Actual:     1.25 hrs
*      The most difficult part was incorporating a conditional statement
*      into the programming in a logical, non-forced way.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * The 'computerLetterGrade function will take the number grade and
 * convert it to a letter grade using the a 'switch' statement. 
 ***********************************************************************/
char computeLetterGrade(int numberGrade)
{
   // The grade is determined by the first number of the number grade.
   // The reducedNumberGrade variable equation reduces the number
   // grade to that number by subtracting the remainder of the grade
   // when divided by ten, then dividing the resultin number by 10.
   int reducedNumberGrade = ((numberGrade - (numberGrade % 10)) / 10);
   char letterGrade;

   // Simply put, this will take the reduced number grade and convert it
   // into a letter grade based on which condition it matches up with.
   switch (reducedNumberGrade)
   {
      case 10:
      case 9:
         letterGrade = 'A';
         break;
      case 8:
         letterGrade = 'B';
         break;
      case 7:
         letterGrade = 'C';
         break;
      case 6:
         letterGrade = 'D';
         break;
      default:
         letterGrade = 'F';
   }
  
   return letterGrade;
}

/**********************************************************************
 * The 'computerGradeSign function will look at the numberGrade and
 * determine if there should be a '+', a '-', or a '*' based on criteria
 * set forth in the class syllabus.
 ***********************************************************************/
char computeGradeSign(char numberGrade)
{

   // The remainder when the grade is divided by 10 makes it easier
   // to set forth conditional statements that determine which sign to use.
   int remainder = numberGrade % 10;
   char gradeSign;
   int aGrade = 0;
   int failingGrade = 0;

   // The 'aGrade' and 'failingGrade variables are set to 
   // determine with a conditional statement whether the grade is above 
   // a 94 or not, as this is an exception to the '+' and '-' rules.
   aGrade = (numberGrade >= 94) ? 1 : 2;
   failingGrade = (numberGrade <= 59) ? 1 : 2;


   // This set of 'if' statements determine the gradeSign variable.
   if ((aGrade == 1) || (failingGrade == 1))
   {
      gradeSign = '*';
   }
   else
   {
      if ((remainder <= 2) || (remainder == 0))
      {
         gradeSign = '-';
      }
      else if (remainder >= 7)
      {
         gradeSign = '+';
      }
      else
      {
         gradeSign = '*';
      }
   }

   return gradeSign;
}

/**********************************************************************
 * The 'main' function will set the variables, prompt the users, and
 * call the other functions. It will then output the final letter grade
 * with the appropriate grade sign for the user.
 ***********************************************************************/
int main()
{
   int numberGrade;
   char letterGrade;
   char gradeSign;
   // Prompt the user for a number grade;
   cout << "Enter number grade: ";
   cin >> numberGrade;
   letterGrade = computeLetterGrade(numberGrade);
   gradeSign = computeGradeSign(numberGrade);

   // The testBed doesn't accept the '*' as the instructions
   // seemed to infer, so we created another if statement for
   // our final 'cout'. 
   if (gradeSign == '*')
   {
      cout << numberGrade << "% is " << letterGrade << "\n";;
   }
   else
   {
      cout << numberGrade << "% is " << letterGrade << gradeSign << "\n";
   }

   return 0;
}
