//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L. Mitchell Jr.
// 05 / 08 / 2020
// C1A8E1_SavingsAccount.cpp
// Win10
// Visual C++ 19.0
//
// This function allows a user to set the SavingsAccount class member variables
//

#include <iostream>
#include <string>

using namespace std;

#include "C1A8E1_SavingsAccount.h"

void SavingsAccount::GetInitialValues()
{
   // Prompt the user to set SavingsAccount member variables
   cout << "Enter the account type: ";
   cin >> type;
   cout << "Enter the owner name: ";
   // Ignore leading whitespace
   cin >> ws;
   // Capture all remaining characters until '\n' is detected
   getline(cin, ownerName);
   cout << "Enter the ID number: ";
   cin >> IDnbr;
   cout << "Enter the account balance: ";
   cin >> balance;
   cout << "Enter the account closure penalty percentage: ";
   cin >> closurePenaltyPercent;
}
