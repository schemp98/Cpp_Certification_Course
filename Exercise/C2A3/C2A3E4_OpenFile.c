//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 07 / 27 / 2020
// C2A3E4_OpenFile.c
// Win10
// Visual C++ 19.0
//
// File contains OpenFile function, which opens file located at the pointer
// passed to it
//

#include <stdio.h>
#include <stdlib.h>

FILE *OpenFile(const char *fileName)
{
   FILE *source;

   // open fileName in "read" mode, return error if failed
   if ((source = fopen(fileName, "r")) == NULL)
   {
      fprintf(stderr, "%s  failed to open \n", fileName);
      exit(EXIT_FAILURE);
   }

   return(source);
}
