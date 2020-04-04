//
// Shaun Chemplavil U08713628
// schemp98@hotmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L.Mitchell, Jr., M.S.
// 04 / 03 / 2020
// C1A2E1_main.cpp
// Win10
// Visual C++ 19.0
//
// This file converts a user-input character to lowercase
// This is accomplished by adding "TO_LOWER" to the integer value of the input
// ("TO_LOWER" = '32' is the difference between upper and lower case letters
//   Code entries in the ASCII table)
// Off-nominal Case 1: If a non-Uppercase character is entered, the character
//                     32 codes higher than the entered character will be output
// Off-nominal Case 2: If a white-space character is entered, the character
//                     32 codes higher than the FIRST whitespace character
//                     entered will be output
//

#include <iostream>
using namespace std;

int main()
{
   // Set variable to convert from upper to lowercase
   const int TO_LOWER = 'a' - 'A';
   char ch;

   cout << "Enter any character: ";

   // Grab character from user
   cin.get(ch);

   // Convert to lowercase (by adding ASCII Code offset) and output to screen
   cout
      << "\nThe lowercase equivalent of '" << ch << "' is '"
      << char(ch + TO_LOWER) << "'\n";

   return 0;
}
