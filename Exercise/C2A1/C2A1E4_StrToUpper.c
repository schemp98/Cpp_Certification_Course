//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 07 / 17 / 2020
// C2A1E4_StrToUpper.c
// Win10
// Visual C++ 19.0
//
// File containing StrToUpper function, which converts all characters in
// a string to Upper Case, and returns the length of the string
//

#include <ctype.h>

size_t StrToUpper(char destination[], const char source[])
{
   // Keep track of initial pointer location
   const char * const START = source;

   // Increment source pointer until the null character is reached
   while (*source)
      *destination++ = (char)toupper(*source++);

   // Append Null Character
   *destination = *source;

   //  Determine the total length of input string
   return (size_t)(source - START);
}
