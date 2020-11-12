//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// Complex.cpp
// Win10
// Visual C++ 19.0
//
// File contains the display member function for the SavingsAccount class
//

#include <iostream>
#include "Complex.h"

using std::ostream;
using std::istream;

namespace ShaunChemplavil
{
   // Default Constructor
   Complex::Complex()
      : real(0.0), imaginary(0.0) {}

   Complex::Complex(double real)
      : real(real), imaginary(0.0) {}

   Complex::Complex(double real, double imaginary)
      : real(real), imaginary(imaginary) {}

   ostream &operator<<(ostream &out, const Complex &value)
   {
      out << value.real;

      //Check if imaginary part is positive, and place '+'
      // (negative sign from imaginary will automatically be displayed)
      if (value.imaginary >= 0.0)
         out << "+";

      out << value.imaginary << "i";

      return out;
   }

   istream &operator>>(istream &in, Complex &value)
   {
      //a '+/-' separating the real from imaginary will put values in correct
      // member variables
      in >> value.real;
      in >> value.imaginary;

      // Ignore the character i
      in.ignore();

      return in;
   }

   Complex operator+(const Complex &op1, const Complex &op2)
   {
      return(Complex(op1.real + op2.real, op1.imaginary + op2.imaginary));
   }

   Complex operator-(const Complex &op1, const Complex &op2)
   {
      return(Complex(op1.real - op2.real, op1.imaginary - op2.imaginary));
   }

   bool operator==(const Complex &op1, const Complex &op2)
   {
      return((op1.real == op2.real) && (op1.imaginary == op2.imaginary));
   }

   bool operator!=(const Complex &op1, const Complex &op2)
   {
      return(!(op1 == op2));
   }
}
