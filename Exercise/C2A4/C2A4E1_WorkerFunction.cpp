//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 07 / 26 / 2020
// C2A4E1_WorkerFunction.cpp
// Win10
// Visual C++ 19.0
//
// File containing definition of the WorkerFunction function, which declares
// a local automatic 4-d array of floats, and then calls RandomizeArray
// ComputeAverages functions
//

#include "C2A4E1_ArraySize.h"

void RandomizeArray(float testArray[][DIM1][DIM2][DIM3]);
void ComputeAverages(float testArray[][DIM1][DIM2][DIM3],
   float *nestedAvg, float *linearAvg);

void WorkerFunction(float *nestedAvg, float *linearAvg)
{
   // declare 4-D array with dimensions defined in "C2A4E1_ArraySize.h"
   float testArray[DIM0][DIM1][DIM2][DIM3];
   RandomizeArray(testArray);
   ComputeAverages(testArray, nestedAvg, linearAvg);
}
