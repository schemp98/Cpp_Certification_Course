//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L. Mitchell Jr.
// 04 / 23 / 2020
// C1A6E1_MyStrlen.c
// Win10
// Visual C++ 19.0
//
// This function calculates the length of a string
//

#include <stddef.h>

size_t MyStrlen(const char *s1)
{
   const char * const START = s1;

   // Increment pointer until the end of s1 is reached
   while (*s1)
      s1++;

   //  Determine the total length of input string
   return (size_t)(s1 - START);
}
