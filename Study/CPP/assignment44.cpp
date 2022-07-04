/***********************************************************************
* Program:
*    Assignment 44, ????          (e.g. Assignment 10, Hello World)
*    Brother {Cook, Comeau, Falin, Lilya, Honeycutt, Unsicker, Peterson, Phair, Ellsworth, Helfrich}, CS124
* Author:
*    your name
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int readNums(int list[], int max);
float computeAverageLin(int list[], int num);
float computeAverageBin(int list[], int num);
int lin(int list[], int num, int search);
int bin(int list[], int num, int search);
/**********************************************************************
* The 'main' function takes the initializes the list and calls 
* the other functions in to complete their calculations.
***********************************************************************/
int main()
{
int list[1024];
const int MAX = sizeof (list) / sizeof (list[0]);
int num;

if (!(num = readNums(list, MAX)))
return 1;

float averageLinear;
averageLinear = computeAverageLin(list, num);
// determine how long it takes for a binary search
float averageBinary;
averageBinary = computeAverageBin(list, num);
// display results
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(1);
cout << "Linear search: " << setw(10) << averageLinear << endl;
cout << "Binary search: " << setw(10) << averageBinary << endl;
return 0;
}
/************************************************************
* READ NUMBERS
* Input:
* list: a list of numbers to search through
* max: the size of the numbers list
* Output:
* num: the number of items actually read
***********************************************************/
int readNums(int list[], int max)
{
char fileName[256];
int num = 0;
// get the filename
cout << "Enter filename of list: ";
cin >> fileName;
// open the file
ifstream fin(fileName);
if (fin.fail())
{
cout << "Unable to open file " << fileName << endl;
return 0;
}
// read the file
while (num < max && fin >> list[num])
num++;
// make like a tree
fin.close();
return num;
}
/*********************************************************
* COMPUTE AVERAGE LINEAR
* Input:
* list: a list of numbers to search through
* num: the size of the numbers list
* Output:
* averageLinear: the average number of comparisons it takes
* to find each item in the array
*******************************************************/
float computeAverageLin(int list[], int num)
{
float totalLinear = 0.0;
float averageLinear = 0.0;
for (int i = 0; i < num; i++)
{
totalLinear += lin(list, num, list[i]);
}
averageLinear = totalLinear / num;
return averageLinear;
}
/*********************************************************
* COMPUTE AVERAGE BINARY
* Input:
* list: a list of numbers to search through
* num: the size of the numbers list
* Output:
* averageBinary: the average number of comparisons it takes
* to find each item in the array
*******************************************************/
float computeAverageBin(int list[], int num)
{
float totalBinary = 0.0;

float averageBinary = 0.0;
for (int i = 0; i < num; i++)
{
totalBinary += bin(list, num, list[i]);
}
averageBinary = totalBinary / num;
return averageBinary;
}
/*******************************************************
* LINEAR
* Input:
* list: a list of numbers to search through
* num: the size of the numbers list
* search: the number that you are searching for
* Output:
* compares: the number of compares that were made
* before 'search' was found in the 'numbers' array
******************************************************/
int lin(int list[], int num, int search)
{
bool found = false;
int compares = 0; // you will need to compute this
for (int i = 0; i < num && ! found; i++)
{
if (search == list[i])
{
found = true;
}
compares++;
}
return compares;
}
/*******************************************************
* BINARY
* Input:
* list: a list of numbers to search through
* num: the size of the numbers list
* search: the number that you are searching for
* Output:
* compares: the number of compares that were made
* before 'search' was found in the 'numbers' array
******************************************************/
int bin(int list[], int num, int search)
{
bool found = false;
int compares = 0; // you will need to compute this
// set the bounds of the search space, initially the whole list
int iFirst = 0;
int iLast = num - 1;
// continue until found or the search size is not zero
while (iLast >= iFirst && !found)
{
int iMiddle = (iLast + iFirst) / 2;
// note that both the == and > count as one comparison

if (list[iMiddle] == search)
{
found = true;
}
else if (list[iMiddle] > search)
{
iLast = iMiddle - 1;
}
else
{
iFirst = iMiddle + 1;
}
compares++;
}
return compares;
}