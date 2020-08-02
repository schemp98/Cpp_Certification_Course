//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 07 / 26 / 2020
// C2A4E1_ComputeAverages.cpp
// Win10
// Visual C++ 19.0
//
// File containing definition of the ComputeAverages function, which calculates
// the average of the values within testArray using nested loops and
// linearly using pointer access
//

#include "C2A4E1_ArraySize.h"

void ComputeAverages(float testArray[][DIM1][DIM2][DIM3],
   float *nestedAvg, float *linearAvg)
{
   // ensure that initial value at pointer address is 0
   *nestedAvg = 0, *linearAvg = 0;

   // Calculate average of the values in testArray by accessing them via
   // nested loops
   for (int index0 = 0; index0 < DIM0; ++index0)
      for (int index1 = 0; index1 < DIM1; ++index1)
         for (int index2 = 0; index2 < DIM2; ++index2)
            for (int index3 = 0; index3 < DIM3; ++index3)
               *nestedAvg += testArray[index0][index1][index2][index3];

   // divide by total elements to get average value
   *nestedAvg /= (float)TOT_DIM;

   // Calculate average of the values in testArray by accessing them linearly
   // via pointer
   for (float *pntIdx = (float *)testArray;
      pntIdx < (float *)testArray + TOT_DIM; ++pntIdx)
      *linearAvg += *pntIdx;

   // divide by total elements to get average value
   *linearAvg /= (float)TOT_DIM;
}
