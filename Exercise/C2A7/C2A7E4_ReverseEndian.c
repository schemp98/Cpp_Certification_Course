//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 08 / 20 / 2020
// C2A7E4_ReverseEndian.c
// Win10
// Visual C++ 19.0
//
// File contains ReverseEndian function, which converts any scalar object
// pointed to it from big endian to little endian (or vice versa)
//

#include <stdlib.h>

void *ReverseEndian(void *ptr, size_t size)
{
   // Swap contents at each byte
   for (char *head = (char *)ptr, *tail = head + size - 1;
      tail > head; --tail, ++head)
   {
      // store contents at head pointer
      char temp = *head;
      *head = *tail;
      *tail = temp;
   }

   //Now contents at the memory addresses have been swapped, so return original
   // address (with new content)
   return(ptr);
}
