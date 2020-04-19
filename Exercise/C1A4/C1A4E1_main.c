//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L. Mitchell Jr.
// 04 / 19 / 2020
// C1A4E1_main.c
// Win10
// Visual C++ 19.0
//
// This file will take two decimal numbers and display their
//  maximum and minimum values
//

#include <stdio.h>

double ComputeMinimum(double input1, double input2);
double ComputeMaximum(double input1, double input2);

int main(void)
{
   double input1, input2;

   // Request and Store User Input
   printf("Enter two space-separated decimal values on the same line: ");
   scanf("%lg%lg", &input1, &input2);

   // Display Minimum and Maximum values
   printf(
      "ComputeMinimum(%lg,%lg) returned %lg\n"
      "ComputeMaximum(%lg,%lg) returned %lg\n",
      input1, input2, ComputeMinimum(input1, input2),
      input1, input2, ComputeMaximum(input1, input2));

   return 0;
}
