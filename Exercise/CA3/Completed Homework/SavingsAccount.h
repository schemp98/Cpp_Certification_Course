//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L.Mitchell III
// SavingsAccount.h
// Win10
// Visual C++ 19.0
//
// File contains the SavingsAccount class definition
//

#ifndef SHAUNCHEMPLAVIL_SAVINGSACCOUNT_H
#define SHAUNCHEMPLAVIL_SAVINGSACCOUNT_H

#include <iostream>
using std::cerr;

namespace ShaunChemplavil
{
   class SavingsAccount
   {
   public:

      SavingsAccount(double initialBalance);

      double getSavingsBalance() const;
      // static member function to apply to ALL SavingsAccount objects
      static void  setAnnualInterestRate(double newInterestRate);
      void  applyMonthlyInterest();

   private:
      double savingsBalance;
      static double annualInterestRate;
   };
}

#endif
