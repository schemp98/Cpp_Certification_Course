//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 08 / 09 / 2020
// C2A6E1_GetPointers.c
// Win10
// Visual C++ 19.0
//
// File contains GetPrintfPointer  and GetPutsPointer functions,
//  GetPrintfPointer returns a pointer to the printf standard library function
//  GetPutsPointer returns a pointer to the puts standard library function
//

#include <stdio.h>

int (*GetPrintfPointer(void))(const char *format, ...)
{
   int (*pPrintF)(const char *format, ...);

   // set pointer to printf standard library function
   pPrintF = printf;
   return(pPrintF);
}

int (*GetPutsPointer(void))(const char *str)
{
   int (*pPuts)(const char *str);

   // set pointer to puts standard library function
   pPuts = puts;
   return(pPuts);
}
