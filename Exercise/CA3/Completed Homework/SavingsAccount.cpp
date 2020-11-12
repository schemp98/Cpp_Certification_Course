//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L.Mitchell III
// SavingsAccount.cpp
// Win10
// Visual C++ 19.0
//
// File contains the display member function for the SavingsAccount class
//

#include <iostream>
#include "SavingsAccount.h"
using std::cerr;

// Static class variable
double ShaunChemplavil::SavingsAccount::annualInterestRate;

// Constructor
ShaunChemplavil::SavingsAccount::SavingsAccount(double initialBalance)
{
   if (initialBalance < 0)
   {
      cerr << "\nERROR: INVALID INITIAL BALANCE!\n";
      this->savingsBalance = 0.0;
   }
   else
      this->savingsBalance = initialBalance;
}
// Member function returning the Account Balance
double ShaunChemplavil::SavingsAccount::getSavingsBalance() const
{
   return this->savingsBalance;
}

// Member function to apply the monthly interest rate
void ShaunChemplavil::SavingsAccount::applyMonthlyInterest()
{
   const double ANNUAL_TO_MONTHLY = 1.0 / 12.0;
   this->savingsBalance *= (1 + this->annualInterestRate * ANNUAL_TO_MONTHLY);
}

// Member function to set the annual interest rate for ALL SavingsAccount objs
void ShaunChemplavil::SavingsAccount::setAnnualInterestRate(double newInterestRate)
{
   const double INTEREST_RATE_TO_DEC = 0.01;
   if (newInterestRate < 0)
   {
      cerr << "\nERROR: INVALID INTEREST RATE!\n";
      ShaunChemplavil::SavingsAccount::annualInterestRate = 0.0;
   }
   else
      ShaunChemplavil::SavingsAccount::annualInterestRate = newInterestRate * INTEREST_RATE_TO_DEC;
}
