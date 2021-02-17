/*===========================================================================
 * Homework #4 - CSE40478
 *
 * File:    CheckingAccount.h
 * Author:  Ray Mitchell
 * Date:    5/9/2012
 *===========================================================================*/
#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

//#include <iostream>
#include <iosfwd>                   // Forward declare streams
//#include <list>
#include <string>                   // Cannot forward declare string
//#include <vector>
using namespace std;

//#include "AccountExceptions.h"    // class OverdrawException
#include "BankAccount.h"            // class BankAccount
//#include "Check.h"                // class Check
class Check;

class CheckingAccount : public BankAccount
{
public:
   CheckingAccount(long accountNumber,
                   double initialBalance,
                   const string &firstName,
                   const string &lastName);
   ~CheckingAccount();
   double getBalance() const;
   void depositCheck(const Check &);
   void depositCash(double);
   void withdrawCash(double);
   virtual ostream &print(ostream &) const;

protected:
   void processAccount();

private:
   //long accountNumber_;
   //double balance_;
   //string firstName_;
   //string lastName_;
   //vector<double> deposits_;
   //vector<double> withdrawals_;
   //list<Check> checks_;
   struct CheckingAccountImpl;      // Forward declaration
   CheckingAccountImpl *pimpl_;
};

ostream &operator<<(ostream &, const CheckingAccount &);

#endif