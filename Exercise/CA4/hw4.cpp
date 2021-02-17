//-----------------------------------------------------------------------------
// CheckingAccount.h
#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include <iofwd>
class string;

using namespace std;
#include "BankAccount.h" // class BankAccount (needed because of inheritance)
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
   struct CheckingAccountImpl;
   CheckingAccountImpl *pimpl_;
};
ostream &operator<<(ostream &, const CheckingAccount &);
#endif

//-----------------------------------------------------------------------------
// Implementation of CheckingAccount.cpp
//
#include "CheckingAccount.h"
struct CheckingAccount::CheckingAccountImpl
{
   long accountNumber_;
   double balance_;
   string firstName_;
   string lastName_;
   vector<double> deposits_;
   vector<double> withdrawals_;
   list<Check> checks_;
};
