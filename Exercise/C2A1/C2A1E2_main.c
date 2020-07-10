//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 07 / 09 / 2020
// C2A1E2_main.c
// Win10
// Visual C++ 19.0
//
// File containing Exercise 2 of Assignment 1
//

#include <stdio.h>

int main(int argc, char *argv[])
{
   // Display the number of input arguments
   printf("%d\n", argc);

   // Print each input argument
   for (int arg_num = 0; arg_num < argc; arg_num++)
   {
      printf("%s\n", argv[arg_num]);
   }

   return 0;
}
