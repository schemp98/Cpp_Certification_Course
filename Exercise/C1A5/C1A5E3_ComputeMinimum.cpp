//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L. Mitchell Jr.
// 04 / 18 / 2020
// C1A5E3_ComputeMinimum.cpp
// Win10
// Visual C++ 19.0
//
// This file returns the minimum of two type double arguments
//

double *ComputeMinimum(const double *input1, const double *input2)
{
   return (double *)((*input1 < *input2) ? input1 : input2);
}
