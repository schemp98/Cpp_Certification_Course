//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L. Mitchell Jr.
// 04 / 10 / 2020
// C1A2E2_main.c
// Win10
// Visual C++ 19.0
//
// This file will take user integer input (input), and display a triangle of
//  characters on the screen
//

#include <stdio.h>

// Set Character to illustrate the "diagonal" of the triangle
#define DIAGONAL_CHAR '\\'
//  Set the RADIX value
#define RADIX 10

int main(void)
{
   // Declare User Input (input) and Display Character (disp_char)
   int input, disp_char;

   // Request and Store User Input
   printf("Enter any positive integer value: ");
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
         // Print Current 'disp_char', increment, and enforce RADIX
         printf("%d", disp_char++ % RADIX);
      }
      // Add DIAGONAL_CHAR
      printf("%c\n", DIAGONAL_CHAR);
   }
   return 0;
}
