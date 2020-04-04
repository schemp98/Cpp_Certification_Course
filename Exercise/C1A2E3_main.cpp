//
// Shaun Chemplavil U08713628
// schemp98@hotmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L.Mitchell, Jr., M.S.
// 04 / 04 / 2020
// C1A2E3_main.cpp
// Win10
// Visual C++ 19.0
//
// This file will take user integer input (u), and display a triangle of
//  characters on the screen
//

#include <iostream>
using namespace std;

int main(void)
{
   // Declare User Input (u) and Display Character (disp_char)
   int u, disp_char;

   // Declare and set Most Significant Bit (msb);
   int msb = 10;
   // Set Character to illustrate the "diagonal" of the triangle
   const char DIAGONAL_CHAR = '\\';

   // Request and Store User Input
   cout << "Enter any positive integer value: ";
   cin >> u;

   // Set the first character to be displayed
   disp_char = u;

   // Display triangle
   // loop that controls current row display
   for (int row_idx = 0; row_idx < u; ++row_idx)
   {
      // loop that controls current column display
      for (int col_idx = 0; col_idx < row_idx; ++col_idx)
      {
         // Print Current 'disp_char', increment, and enforce msb
         cout << disp_char++ % msb;
      }
      // Add DIAGONAL_CHAR
      cout << DIAGONAL_CHAR << '\n';
   }
   return 0;
}
