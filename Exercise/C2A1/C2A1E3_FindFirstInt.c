//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 07 / 17 / 2020
// C2A1E3_FindFirstInt.c
// Win10
// Visual C++ 19.0
//
// File containing FindFirstInt function, which searches an integer array
// pointer location (with size 'count') and returns the pointer to the
// element which contains 'value', if 'value' is not found a NULL pointer
// is returned
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
