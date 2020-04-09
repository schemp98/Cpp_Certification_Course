//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L.Mitchell, Jr., M.S.
// 04 / 09 / 2020
// C1A3E2_main.cpp
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
   // Declare User Input (inValue)
   int inValue;
   //  Flag to signal sign of input value
   bool isNeg;

   // Request and Store User Input
   cout << "Enter any decimal integer value: ";
   cin >> inValue;

   // Display Opening Quotation Marks
   cout << "\"";

   // Track Original Sign of input
   isNeg = inValue < 0;

   // Force to be positive AND Display Negative sign
   if (isNeg)
   {
      cout << "-";
      inValue = -inValue;
   }

   cout << inValue << "\" in reverse is  \"";

   do
   {
      // Print Current Least Significant Bit
      cout << inValue % RADIX;

      // Remove the LSB
      inValue /= RADIX;
   } while (inValue != 0);

   // Check if we need to display negative sign
   if (isNeg)
   {
      cout << "-";
   }

   cout << "\"\n";
   return 0;
}
