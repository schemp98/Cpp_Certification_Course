//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 07 / 16 / 2020
// C2A2E2_CountIntBitsF.cpp
// Win10
// Visual C++ 19.0
//
// File contains CountIntBitsF function
//

int CountIntBitsF()
{
   unsigned int sizeTemp = 1;
   int count;

   // Keep left shifting sizeTemp by 1 bit until sizeTemp = 0
   for (count = 0; sizeTemp != 0; count++)
   {
      sizeTemp <<= 1;
   }

   // When sizeTemp = 0 we have cycled through all bits of the variable
   // count contains the number of bits
   return(count);
}
