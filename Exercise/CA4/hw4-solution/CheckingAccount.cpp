/*===========================================================================
 * Homework #4 - CSE40478
 *
 * File:    CheckingAccount.cpp
 * Author:  Ray Mitchell
 * Date:    5/9/2012
 *===========================================================================*/
#include <list>
#include <string>
#include <vector>
using namespace std;

#include "Check.h"            // Class Check
#include "CheckingAccount.h"  // Class CheckingAccount

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