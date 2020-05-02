//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L. Mitchell Jr.
// 05 / 01 / 2020
// C1A8E1_main.cpp
// Win10
// Visual C++ 19.0
//
// This file will take user inputs varies calls to an overloaded function
//

#include <iostream>
using namespace std;

#include "C1A8E1_SavingsAccount.h"

int main()
{
   SavingsAccount account;

   // Prompt user and set SavingsAccount member variables
   account.GetInitialValues();
   // Display member variable values
   account.DisplayValues();

   // Calculate and display the dollar amount of an account closure penalty
   cout << "Account closure penalty: " << account.CalculatePenalty() << "\n";

   return 0;
}
