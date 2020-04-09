//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L.Mitchell, Jr., M.S.
// 04 / 09 / 2020
// C1A3E3_main.cpp
// Win10
// Visual C++ 19.0
//
// This file will take user integer input (inValue), and the reverse of it
//

#include <iostream>
using namespace std;

// Declare and set RADIX;
const int RADIX = 10;

int main()
{
   // Declare User Input (inValue), most significant digit (msd)
   int inValue, msd, dividend, divisor = 1;

   // Request and Store User Input
   cout << "Enter any decimal integer value: ";
   cin >> inValue;

   // Display Opening Phrase
   cout << "\"" << inValue << "\" in words is  \"";

   // Force to be positive AND display "minus"
   if (inValue < 0)
   {
      inValue = -inValue;
      cout << "minus";
   }

   dividend = inValue;

   // Find the power of ten of the input
   do
   {
      divisor *= RADIX;
      dividend /= RADIX;
   } while (dividend > 9);

   dividend = inValue;

   do
   {
      // Determine the most significant digit
      msd = dividend / divisor;

      // Write out most significant digit in words
      switch (msd)
      {
         case 0:
            cout << " zero";
            break;
         case 1:
            cout << " one";
            break;
         case 2:
            cout << " two";
            break;
         case 3:
            cout << " three";
            break;
         case 4:
            cout << " four";
            break;
         case 5:
            cout << " five";
            break;
         case 6:
            cout << " six";
            break;
         case 7:
            cout << " seven";
            break;
         case 8:
            cout << " eight";
            break;
         case 9:
            cout << " nine";
            break;
         default:
            cout << " UNRECOGNIZED DIGIT";
      }

      // reduce the most significant digit
      dividend -= msd * divisor;

      // Remove the LSB
      divisor /= RADIX;
   } while (divisor != 0);

   cout << "\"\n";
   return 0;
}
