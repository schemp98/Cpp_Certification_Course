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
//  Set the Most Significant Bit value
#define MSB 10

int main(void)
{
   // Declare User Input (u) and Display Character (disp_char)
   int input, disp_char;

   // Request and Store User Input
   printf("%s", "Enter any positive integer value: ");
   scanf("%d", &input);

   // Set the first character to be displayed
   disp_char = input;

   // Display triangle
   // loop that controls current row display
   for (int row_idx = 0; row_idx < input; ++row_idx)
   {
      // loop that controls current column display
      for (int col_idx = 0; col_idx < row_idx; ++col_idx)
      {
         // Print Current 'disp_char', increment, and enforce msb
         printf("%d", disp_char++ % MSB);
      }
      // Add DIAGONAL_CHAR
      printf("%c%c", DIAGONAL_CHAR, '\n');
   }
   return 0;
}
