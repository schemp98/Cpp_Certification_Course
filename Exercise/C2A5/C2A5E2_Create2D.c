//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 08 / 05 / 2020
// C2A5E2_Create2D.c
// Win10
// Visual C++ 19.0
//
// File contains Create2D  and Free2D functions,
//  Create2D creates a 2-d pointer array of data type Type, the dimensions are
//  specified via input arguments.  Free2D frees the data at the pointer passed
// to it
//

#include <stdio.h>
#include <stdlib.h>
#include "C2A5E2_Type-Driver.h"

Type **Create2D(size_t rows, size_t cols)
{
   Type **p, **p1, **end;

   size_t typeSize = sizeof(Type);

   // Allocate appropriate memory
   if ((p = malloc(sizeof(Type *) * rows + typeSize * rows * cols)) == NULL)
   {
      fputs("Out of memory\n", stderr);
      exit(EXIT_FAILURE);
   }
   for (end = p + rows, p1 = p; p1 < end; ++p1)
   {
      // find distance from original pointer to next element of pointer array
      size_t rowNum = (size_t)(p1 - p);

      //Calculate address of the start of the next row and place within pointer
      // array, we must typecast to size_t to avoid pointer math which ensures
      // the size of Type is taken into account correctly
      *p1 = (Type *)((size_t)end + typeSize * (cols * rowNum));
   }

   return(p);
}

void Free2D(void *p)
{
   // because all memory was allocated at one tine, we can free everything
   free(p);
}
