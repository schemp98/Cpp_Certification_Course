//
// Shaun Chemplavil U08713628
// schemp98@hotmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L. Mitchell Jr.
// 04 / 04 / 2020
// C1A2E2_main.c
// Win10
// Visual C++ 19.0
//
// This file will take user integer input (u), and display a triangle of
//  characters on the screen
//

#include <stdio.h>

// Set Character to illustrate the "diagonal" of the triangle
#define DIAGONAL_CHAR '\\'

int main(void)
{
   // Declare User Input (u) and Display Character (disp_char)
   int u, disp_char;

   // Declare and set Most Significant Bit (msb);
   int msb = 10;

   // Request and Store User Input
   printf("%s", "Enter any positive integer value: ");
   scanf("%d", &u);

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
         printf("%d", disp_char++ % msb);
      }
      // Add DIAGONAL_CHAR
      printf("%c%c", DIAGONAL_CHAR, '\n');
   }
   return 0;
}
