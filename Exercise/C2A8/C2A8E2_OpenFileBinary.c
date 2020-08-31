//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 08 / 31 / 2020
// C2A8E2_OpenFileBinary.c
// Win10
// Visual C++ 19.0
//
// File contains OpenFile function, which opens file located at the pointer
// passed to it in read-only binary mode
//

#include <stdio.h>
#include <stdlib.h>

FILE *OpenFileBinary(const char *fileName)
{
   FILE *source;

   // open fileName in "read-only binary" mode, return error if failed
   if ((source = fopen(fileName, "rb")) == NULL)
   {
      fprintf(stderr, "%s  failed to open\n", fileName);
      exit(EXIT_FAILURE);
   }

   return(source);
}
