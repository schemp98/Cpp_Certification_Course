// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming IV : Advanced Programming with Objects
// 152488 Raymond L. Mitchell III
// BingInt.h
// Win10
// Visual C++ 19.0
//

#ifndef PROJECT1_BIGINT_H
#define PROJECT1_BIGINT_H

#include<vector>
#include<iostream>

using namespace std;

namespace Project1
{
   class BigInt
   {
      friend const BigInt operator+(const BigInt &, const BigInt &);
      friend const BigInt operator-(const BigInt &, const BigInt &);
      friend bool operator==(const BigInt &, const BigInt &);
      friend bool operator!=(const BigInt &, const BigInt &);
      friend bool operator<(const BigInt &, const BigInt &);
      friend bool operator<=(const BigInt &, const BigInt &);
      friend bool operator>(const BigInt &, const BigInt &);
      friend bool operator>=(const BigInt &, const BigInt &);
      friend ostream &operator<<(ostream &, const BigInt &);
      friend istream &operator>>(istream &, BigInt &);

   public:
      BigInt();
      BigInt(const BigInt &);
      BigInt(long long);
      // Throws invalid_argument if string malformed (contains anything other than a legally formatted number)
      BigInt(const string &);
      const BigInt &operator=(const BigInt &);
      const BigInt &operator+=(const BigInt &);
      const BigInt &operator-=(const BigInt &);
   private:
      string bigDigitsString;
      vector<int> bigDigitsVector;
      void negate();
      void setbigDigitsString(string);
      void setbigDigitsVector(vector<int>);
   };
};
#endif
