//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L. Mitchell Jr.
// 04 / 24 / 2020
// C1A6E3_GetSubstring.c
// Win10
// Visual C++ 19.0
//
// This function creates a new string of character by computing them from
// an existing string
//

#define NULL_CHAR '\0'

char *GetSubstring(const char source[], int start, int count, char result[])
{
   //retain original result address
   char *result_copy = result;

   // Increment source pointer until we hit start offset (or null character)
   while (start-- > 0 && (*source != '\0'))
   {
      source++;
   }

   // copy source array count indicies to result (or until null character)
   while ((count-- > 0) && (*source != '\0'))
   {
      *result++ = *source++;
   };

   // Append Null Character to result
   *result++ = NULL_CHAR;

   return (result_copy);
}
