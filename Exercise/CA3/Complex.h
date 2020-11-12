//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// Complex.h
// Win10
// Visual C++ 19.0
//
// File contains the SavingsAccount class definition
//
#ifndef SHAUNCHEMPLAVIL_COMPLEX_H
#define SHAUNCHEMPLAVIL_COMPLEX_H
#include<iostream>
using std::ostream;
using std::istream;
namespace ShaunChemplavil
{
   class Complex
   {
      friend ostream &operator<<(ostream &out, const Complex &value);
      friend istream &operator>>(istream &in, Complex &value);
      friend Complex operator+(const Complex &op1, const Complex &op2);
      friend Complex operator-(const Complex &op1, const Complex &op2);
      friend bool operator==(const Complex &op1, const Complex &op2);
      friend bool operator!=(const Complex &op1, const Complex &op2);
   public:
      // Constructors (need to default member variables to 0.0)
      Complex();
      Complex(double real);
      Complex(double real, double imaginary);
   private:
      double real;
      double imaginary;
   };
}
#endif