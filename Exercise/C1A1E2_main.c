//
// Shaun Chemplavil U08713628
// schemp98@hotmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L. Mitchell Jr.
// 04 / 04 / 2020
// C1A1E2_main.c
// Win10
// Visual C++ 19.0
//
// This file will take user input (u) and display the result of a function
//

#include <stdio.h>

int main(void)
{
   // Declare User Input (u), Result (r)
   double u, r;

   // Request and Store User Input
   printf("%s", "Enter a decimal value: ");
   scanf("%lf", &u);

   // Calculate result (r)
   r = 3.0 * u * u * u - 5.0 * u * u + 6.0;

   printf("%s%g%s%g%c", "If x = ", u,
      " the value of \"3x^3 - 5x^2 + 6\" is ", r, '\n');

   return 0;
}
