//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 07 / 10 / 2020
// C2A1E3_FindFirstInt.c
// Win10
// Visual C++ 19.0
//
// File containing FindFirstInt function
//

#include <stdio.h>

int *FindFirstInt(const int *ptr, size_t count, int value)
{
   // cycle through array values
   for (int index = 0; index < (int)count; index++)
   {
      //  When desired value encountered, return pointer
      if (ptr[index] == value)
         return((int *)&ptr[index]);
   }

   // If value is not found return NULL
   return(NULL);
}
