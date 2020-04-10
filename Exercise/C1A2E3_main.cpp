//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L.Mitchell, Jr., M.S.
// 04 / 10 / 2020
// C1A2E3_main.cpp
// Win10
// Visual C++ 19.0
//
// This file will take user integer input, and display a triangle of
//  characters on the screen
//

#include <iostream>
using namespace std;

// Set Character to illustrate the "diagonal" of the triangle
const char DIAGONAL_CHAR = '\\';
// Declare and set RADIX;
const int RADIX = 10;

int main()
{
   // Declare User Input (input) and Display Character (disp_char)
   int input, disp_char;

   // Request and Store User Input
   cout << "Enter any positive integer value: ";
   cin >> input;

   // Set the first character to be displayed
   disp_char = input;

   // Display triangle
   // loop that controls current row display
   for (int row_idx = 0; row_idx < input; ++row_idx)
   {
      // loop that controls current column display
      for (int col_idx = 0; col_idx < row_idx; ++col_idx)
      {
         // Print Current 'disp_char', increment, and enforce RADIX
         cout << disp_char++ % RADIX;
      }
      // Add DIAGONAL_CHAR
      cout << DIAGONAL_CHAR << '\n';
   }
   return 0;
}
