//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 08 / 02 / 2020
// C2A5E1_SwapObjects.c
// Win10
// Visual C++ 19.0
//
// File contains SwabObjects function, which swaps the objects from one pointer
// address to the other
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SwapObjects(void *pa, void *pb, size_t size)
{
   void *temp;

   // Allocate appropriate memory
   if ((temp = malloc(size)) == NULL)
   {
      fputs("Out of memory\n", stderr);
      exit(EXIT_FAILURE);
   }

   // Copy object at pa to temp
   memcpy(temp, pa, size);
   // Copy object at pb to pa
   memcpy(pa, pb, size);
   // Copy object at temp (original object at pa) to pb
   memcpy(pb, temp, size);
   // free allocated memory
   free(temp);
}
