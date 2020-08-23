//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 08 / 22 / 2020
// C2A7E4_OpenTemporaryFile.c
// Win10
// Visual C++ 19.0
//
// File contains OpenTemporaryFile function, which opens temporary file
// and returns the pointer to that temporary file
//

#include <stdio.h>
#include <stdlib.h>

FILE *OpenTemporaryFile(void)
{
   FILE *source;

   // open fileName in "read" mode, return error if failed
   if ((source = tmpfile()) == NULL)
   {
      fprintf(stderr, "Temporary File failed to open\n");
      exit(EXIT_FAILURE);
   }

   return(source);
}
