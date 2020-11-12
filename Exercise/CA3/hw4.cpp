//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// hw4.cpp
// Win10
// Visual C++ 19.0
//
// Test Program for the Complex class
//

#include <iostream>
#include "Complex.h"
using std::cout;
using std::cin;

using ShaunChemplavil::Complex;

int main()
{
   // declare original date variables (arbitrary values)
   Complex input1, input2, temp, tempIn2(9.1, 8.55), tempIn1(1.2);
   cout << "Default input is: " << temp << "\n"
      << "Specified input (2 inputs) is: " << tempIn2 << "\n"
      << "Specified input (1 inputs) is: " << tempIn1 << "\n\n";

   cout << "Please enter 2 Complex numbers (space separated):\n";
   cin >> input1 >> input2;

   cout << "\nInput 1 is: " << input1 << "\n"
      << "Input 2 is: " << input2 << "\n\n"
      << "Input 1 + Input 2 + Specified (2 inputs) = " << (input1 + input2 + tempIn2) << "\n"
      << "Input 2 - Input 1 - Specified (2 inputs) = " << (input2 - input1 - tempIn2) << "\n\n"
      << "Input 1 == Input 1 :" << (input1 == input1) << "\n"
      << "Input 1 == Input 2 :" << (input1 == input2) << "\n"
      << "Input 1 != Input 2 :" << (input1 != input2) << "\n";

   return 0;
}
