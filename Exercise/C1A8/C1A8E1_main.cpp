//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L. Mitchell Jr.
// 05 / 08 / 2020
// C1A8E1_main.cpp
// Win10
// Visual C++ 19.0
//
// This program asks the user to enter account information to populate a
//  SavingsAccount class variable, and then displays the dollar amount
//  penalty to close the account
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
