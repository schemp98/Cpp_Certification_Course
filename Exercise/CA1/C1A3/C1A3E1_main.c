//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L. Mitchell Jr.
// 04 / 07 / 2020
// C1A3E1_main.c
// Win10
// Visual C++ 19.0
//
// This file will take a positive user integer input (input),
//  and display a table of the cubic sum to that number
//

#include <stdio.h>

int main(void)
{
   int input;
   short cubic_sum = 0;

   // Request and Store User Input
   printf("Enter integer value >=0: ");
   scanf("%d", &input);

   // Display Column Headers
   printf(
      "nbr   cubic sum\n"
      "---------------\n");

   // loop that controls current row display
   for (short nbr = 0; nbr <= input; ++nbr)
   {
      // Add cube of current number to cubic sum
      // Type conversion is necessary due to multiplication
      cubic_sum += (short)(nbr * nbr * nbr);

      // Print table contents for current row
      printf("%3hi %10hi\n", nbr, cubic_sum);
   }
   return 0;
}
