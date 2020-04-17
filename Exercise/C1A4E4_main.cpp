//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L. Mitchell Jr.
// 04 / 16 / 2020
// C1A4E4_main.cpp
// Win10
// Visual C++ 19.0
//
// This file will find the maximum of 3 user input values and return the maximum
// value using an inline function and a macro
//

#include <iostream>
using namespace std;

// Include header containing function prototypes
#include "C1A4E4_MaxOf.h"

int main()
{
   long double in1, in2, in3, macroOut, inlineOut;

   // Request User Input
   cout << "Enter the three space-separated decimal values on the same line:\n";

   cin >> in1 >> in2 >> in3;

   // Find max value using a macro
   macroOut = mMaxOf3(in1, in2, in3);

   // Find max value using an inline function
   inlineOut = fMaxOf3(in1, in2, in3);

   // Display Results...
   cout <<
      "mMaxOf3(" << in1 << "," << in2 << "," << in3 << ")"
      " returned " << macroOut << "\n"
      "fMaxOf3(" << in1 << "," << in2 << "," << in3 << ")"
      " returned " << inlineOut << "\n";

   return 0;
}
