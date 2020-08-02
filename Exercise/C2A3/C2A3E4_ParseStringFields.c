//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 07 / 27 / 2020
// C2A3E4_ParseStringFields.c
// Win10
// Visual C++ 19.0
//
// File contains ParseStringFields function, parses and displays the contents
// of the file pointer passed to it
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFSIZE 256

void ParseStringFields(FILE *fp)
{
   char buf[BUFSIZE];

   // place current line into buf
   while (fgets(buf, (int)sizeof(buf), fp))
   {
      // search for delimiters
      for (char *cp = buf; cp = strtok(cp, "AEIOUaeiou\t\n"); cp = NULL)
      {
         int whiteSpaceIdx = 0;

         // find index in cp of first non whitespace character
         while (isspace(cp[whiteSpaceIdx]))
            whiteSpaceIdx++;

         // display line from buffer (excluding leading whitespace)
         printf("%s\n", cp + whiteSpaceIdx);
      }

      // break loop if End of File reached
      if (feof(fp))
         break;
   }
}
