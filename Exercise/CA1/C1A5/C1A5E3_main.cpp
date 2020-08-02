//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L. Mitchell Jr.
// 05 / 01 / 2020
// C1A5E3_main.cpp
// Win10
// Visual C++ 19.0
//
// This file will take two decimal numbers and display their
//  maximum and minimum values via pointers to their values
//

#include <iostream>

using namespace std;

double *ComputeMinimum(const double *input1, const double *input2);
double *ComputeMaximum(const double *input1, const double *input2);

int main()
{
   double input1, input2;

   // Request and Store User Input
   cout << "Enter two space-separated decimal values on the same line: ";
   cin >> input1 >> input2;

   // Display Minimum and Maximum values
   cout <<
      "ComputeMinimum(&" << input1 << ",&" << input2 << ") returned &" <<
      *ComputeMinimum(&input1, &input2) << "\n"
      "ComputeMaximum(&" << input1 << ",&" << input2 << ") returned &" <<
      *ComputeMaximum(&input1, &input2) << "\n";

   return 0;
}
