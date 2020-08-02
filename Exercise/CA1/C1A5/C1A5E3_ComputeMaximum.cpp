//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L. Mitchell Jr.
// 05 / 01 / 2020
// C1A5E3_ComputeMaximum.cpp
// Win10
// Visual C++ 19.0
//
// This function returns the maximum of two type double arguments
//

double *ComputeMaximum(const double *input1, const double *input2)
{
   return (double *)((*input1 > *input2) ? input1 : input2);
}
