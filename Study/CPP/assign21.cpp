/***********************************************************************
* Program:
*    Assignment 21, Debugging
*    Brother Ridges, CS124
* Author:
*    your name
* Summary: 
*    This is a program that, in its current state, includes
*    stub functions intended to be a start for a program which
*    will eventually determine the cost for parking a vehicle
*    versus the cost for driving it. 
*
*    Estimated:  0.75 hrs   
*    Actual:     0.75 hrs
*      The hardest part was at things from an organizational perspective
*      without being able to test the interaction of the functions. It
*      certainly tests my confidence in my understanding of how 
*      parameters and functions work and interact.
************************************************************************/

#include <iostream>
using namespace std;


double promptDevalue()
{
   double devalueCost;
   return devalueCost;
}

double promptInsurance()
{
   double insuranceCost;
   return insuranceCost;
}

double promptParking()
{
   double parkingCost;
   return parkingCost;
}

double getPeriodicCost(double deValueCost, double insuranceCost, double parkingCost)
{
    double costPeriodic;
    promptDevalue();
    promptInsurance();
    promptParking();

   return costPeriodic;
}


double promptMileage()
{
   double mileage;
   return mileage;
}

double promptGas()
{
   double gasCost;
   return gasCost;
}

double promptRepairs()
{
   double repairsCost;
   return repairsCost;
}

double promptTires()
{
   double tiresCost;
   return tiresCost;
}

double getUsageCost(double mileage, double gasCost, double repairsCost, double tiresCost)
{
    double costUsage;
    promptMileage();
    promptGas();
    promptRepairs();
    promptTires();

   return costUsage;
}


void display(double deValueCost, double insuranceCost, double parkingCost,
double mileage, double gasCost, double repairsCost, double tiresCost)
{
   
   double costPeriodic = getPeriodicCost(deValueCost, insuranceCost, parkingCost);
   double costUsage = getUsageCost(mileage, gasCost, repairsCost, tiresCost);

   cout << "Success\n";

   return;
}



int main()
{
    double deValueCost = promptDevalue();
    double insuranceCost = promptInsurance();
    double parkingCost = promptParking();
    double mileage = promptMileage();
    double gasCost = promptGas();
    double repairsCost = promptRepairs();
    double tiresCost = promptTires();

    display(deValueCost, insuranceCost, parkingCost,
    mileage, gasCost, repairsCost, tiresCost);





   return 0;
}