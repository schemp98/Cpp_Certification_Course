//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// hw6.cpp
// Win10
// Visual C++ 19.0
//
// Test Program for the Array Template class
//

#include "Array.h"

#include <iostream>

using std::cout;
using ShaunChemplavil::Array;

const int ARRAY_SIZE = 5;

int main()
{
   // a ) Creating default array with " << ARRAY_SIZE << " ints
   Array<int, ARRAY_SIZE> arrayOfFiveInts;

   // b) Modifying array with arbitrary values
   for (int idx = 0; idx < ARRAY_SIZE; idx++)
      arrayOfFiveInts[idx] = 2 * idx + 1;

   cout << "c) Outputting array contents\n";
   for (int idx = 0; idx < ARRAY_SIZE; idx++)
      cout << arrayOfFiveInts[idx] << "\n";

   // d) creating a const Array using the copy constructor
   const Array<int, ARRAY_SIZE> constArrayOfFiveInts(arrayOfFiveInts);

   // e) Assigning Array to existing Array using copy assignment
   Array<int, ARRAY_SIZE> copyAssignArrayOfFiveInts;
   copyAssignArrayOfFiveInts = arrayOfFiveInts;

   cout << "f) Comparing two equal arrays using equality operator:\n"
      << "Result: " << (arrayOfFiveInts == constArrayOfFiveInts) << "\n";

   cout << "g) Comparing two equal arrays using inequality operator:\n"
      << "Result: " << (arrayOfFiveInts != copyAssignArrayOfFiveInts) << "\n";

   cout << "h) Show invalid_argument for L-Value with negative subscript:\n";
   copyAssignArrayOfFiveInts[-1] = 5;

   cout << "i) Show invalid_argument for L-Value with > SIZE subscript:\n";
   copyAssignArrayOfFiveInts[ARRAY_SIZE + 1] = 5;

   cout << "j) Show invalid_argument for R-Value with negative subscript:\n";
   int temp = constArrayOfFiveInts[-1];

   cout << "k) Show invalid_argument for R-Value with > SIZE subscript:\n";
   temp = constArrayOfFiveInts[ARRAY_SIZE + 1];
}
