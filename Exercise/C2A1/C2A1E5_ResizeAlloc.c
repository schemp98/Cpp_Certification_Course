//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 07 / 10 / 2020
// C2A1E5_ResizeAlloc.c
// Win10
// Visual C++ 19.0
//
// File containing ResizeAlloc function
//

#include <ctype.h>

void *ResizeAlloc(void *pOld, size_t newSize, size_t oldSize)
{
   if (newSize == 0)
      return(NULL);
   else
   {
      void * pNew;
      int  copySize;
      // allocate newSize bytes of memory to newBlock
      pNew += newSize;

      if (newSize > oldSize)
         copySize = (int)oldSize;
      else
         copySize = (int)newSize;

      // copy oldSize bytes from pOld to pNew
      for (int index = 0; index < (int)copySize; index++)
         pNew[index] = pOld;

      //  Determine the total length of input string
      return(pNew);
   }
}
