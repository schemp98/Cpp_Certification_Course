//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L. Mitchell Jr.
// 05 / 02 / 2020
// C1A8E2_main.c
// Win10
// Visual C++ 19.0
//
// This program will run at the command line with two space separated arguments
//  first argument specifies a text file name, and the second specified the
//  number of lines in a group
//

#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 256
#define EXPECTED_ARGS 3
#define NEW_LINE_ASCII 10
#define FILENAME_ARG  1
#define DISP_LINE_ARG  2

void ErrorAndExit(const char *filename)
{
   fprintf(stderr, "%s  failed to open \n", filename);
   exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
   // Check to make ensure correct amount of arguments,
   if (argc != EXPECTED_ARGS)
   {
      fputs("Unexpected number of arguments \n", stderr);
      exit(EXIT_FAILURE);
   }

   int   numDispLines, lineCnt = 0;
   char *filename, buf[BUFSIZE];
   FILE *source;

   // Store Arguments
   filename = argv[FILENAME_ARG];
   numDispLines = atoi(argv[DISP_LINE_ARG]);

   // Open file containing we want to display
   if ((source = fopen(filename, "r")) == NULL)
      ErrorAndExit(filename);

   // Display requested amount of lines
   while (lineCnt < numDispLines)
   {
      // store line from source file into buffer
      fgets(buf, (int)sizeof(buf), source);

      // break loop if End of File reached
      if (feof(source))
         break;

      // display line from buffer
      printf("%s", buf);

      // once we have displayed the request amount of lines
      // check if user has entered '\n' to indicate if the same amount of lines
      // (until EOF reached) should be displayed
      if ((++lineCnt == numDispLines) && (getchar() == NEW_LINE_ASCII))
         lineCnt = 0;
   }

   fclose(source);

   return(EXIT_SUCCESS);
}
