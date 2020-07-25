//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L. Mitchell, Jr., M.S.
// 07 / 17 / 2020
// C2A1E5_ResizeAlloc.c
// Win10
// Visual C++ 19.0
//
// File containing ResizeAlloc function, which  dynamically allocates memory
// containing newSize bytes or resizes an existing block in pOld to
// contain newSize bytes.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void *ResizeAlloc(void *pOld, size_t newSize, size_t oldSize)
{
   if (newSize == 0)
      return(NULL);
   else
   {
      void *pNew;
      // allocate newSize bytes of memory to pNew, test for success
      if ((pNew = malloc(newSize)) == NULL)
      {
         fputs("Not enough memory for pNew\n", stderr);
         exit(EXIT_FAILURE);
      }

      // Exit if no data at pOld memory location
      if (pOld == NULL)
         return(pNew);

      // Keep track number of bytes to copy into newly allocated memory
      size_t  copySize;

      // Ensure that we do not copy more bytes that we need to while not
      // exceeding the allocated memory
      if (newSize > oldSize)
         copySize = oldSize;
      else
         copySize = newSize;

      memcpy(pNew, pOld, copySize);

      free(pOld);

      return(pNew);
   }
}
