//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L. Mitchell Jr.
// 05 / 01 / 2020
// C1A8E1_SavingsAccount.h
// Win10
// Visual C++ 19.0
//
// This header file contains the definition of the SavingsAccount structure
//

#ifndef  C1A8E1_SAVINGSACCOUNT_H
#define C1A8E1_SAVINGSACCOUNT_H

#include <iostream>

const double PERCENT_TO_DECIMAL = 0.01;

class SavingsAccount
{
   int type;
   string ownerName;
   long IDnbr;
   double balance, closurePenaltyPercent;

public:

   void GetInitialValues();
   inline void DisplayValues() const;

   inline double CalculatePenalty() const
   {
      // Calculate and save total fine for closing account
      double fine = balance * closurePenaltyPercent * PERCENT_TO_DECIMAL;

      return fine;
   }
};

// Member function to display account information
inline void SavingsAccount::DisplayValues() const
{
   std::cout <<
      "Account type: " << type << "\n"
      "Owner name: " << ownerName << "\n"
      "ID number: " << IDnbr << "\n"
      "Account balance: " << balance << "\n"
      "Account closure penalty percent: " << closurePenaltyPercent << "\n";
}

#endif
