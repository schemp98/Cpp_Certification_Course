//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 08 / 14 / 2020
// C2A6E2_SortValues.cpp
// Win10
// Visual C++ 19.0
//
// This file contains the SortValues function, which uses the "Bubble Sort'
// algorithm to sort an floating point array of size 'elements' located at
// 'first' in DESCENDING order, and returns a pointer the first
// element of the sorted array
//

float *SortValues(float *first, size_t elements)
{
   float *last = &first[elements - 1];
   bool didSwap;

   do
   {
      didSwap = false;

      // loop through entire array
      for (float *current = first; current < last; ++current)
      {
         float *next = current;
         // increment to access next pointer
         next++;

         // check if we need to swap values
         if (*current < *next)
         {
            // save current value
            float temp = *current;
            // swap values
            *current = *next;
            *next = temp;

            // indicate that a swap has occurred
            didSwap = true;
         }
      }
      // do not check bubbled values
      --last;

      // if no swaps have occurred sorting is complete
   } while (didSwap);

   return(first);
}
