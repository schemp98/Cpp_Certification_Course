//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 08 / 14 / 2020
// C2A6E2_GetValues.cpp
// Win10
// Visual C++ 19.0
//
// This file contains the GetValues function, which prompts the user for
// 'elements' white-space floating point values, and places them into an array
// located at 'first', and returns a pointer the first element of the array
//

#include <iostream>

using namespace std;

float *GetValues(float *first, size_t elements)
{
   float *end, *firstIdx;

   // Prompt user for input
   cout << "Please input " << elements
      << " whitespace-separated floating point values:\n";

   // place user input into floating point array located at first
   // and add additional elements to array
   for (end = first + elements, firstIdx = first; firstIdx < end; firstIdx++)
      cin >> *firstIdx;

   return(first);
}
