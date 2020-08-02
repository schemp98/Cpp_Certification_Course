//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 07 / 26 / 2020
// C2A4E1_RandomizeArray.cpp
// Win10
// Visual C++ 19.0
//
// File containing definition of the RandomizeArray function, which populates
// the values of testArray with random values
//

#include <cstdlib>
#include <ctime>
#include "C2A4E1_ArraySize.h"

void RandomizeArray(float testArray[][DIM1][DIM2][DIM3])
{
   time_t timer;

   // Get current real time clock values
   time(&timer);

   // Set seed for random number generator
   srand((unsigned int)timer);

   // Populate testArray with random numbers
   for (float *pntIdx = (float *)testArray;
      pntIdx < (float *)testArray + TOT_DIM; ++pntIdx)
      *pntIdx = (float)rand();
}
