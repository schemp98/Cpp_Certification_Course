//
// Shaun Chemplavil U08713628
// schemp98@hotmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L.Mitchell, Jr., M.S.
// 04 / 01 / 2020
// C1A1E2_Main.c
// Win10
// Visual C++ 15.0
// This file will take user input X, and display the result of a function

#include <stdio.h>

int main(void)
{
   // Declare User Input (U), Result (R)
   double U, R;

   // Request and Store User Input
   printf("%s", "Please enter any decimal value: ");
   scanf("%lf", &U);

   // Calculate result (R)
   R = 3.0 * U * U * U - 5.0 * U * U + 6.0;

   printf("%s%g%s%g", "If x = ", U, " the value of \"3x^3 - 5x^2 + 6\" is ", R);
   return 0;
}