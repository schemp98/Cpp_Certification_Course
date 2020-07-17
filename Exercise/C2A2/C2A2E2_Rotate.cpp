//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 07 / 16 / 2020
// C2A2E2_Rotate.cpp
// Win10
// Visual C++ 19.0
//
// File containing definition of the Rotate function
//

int CountIntBitsF();

unsigned Rotate(unsigned object, int count)
{
   int leftShiftCnt, rightShiftCnt, numBits = CountIntBitsF();
   unsigned leftShiftObj, rightShiftObj;

   // avoid shifting by more bits contained in the object
   count %= numBits;

   // For most efficient Rotation, we need to check sign of count
   // this will determine how many counts to right/left shift
   if (count >= 0)
   {
      rightShiftCnt = count;
      leftShiftCnt = numBits - count;
   }
   else
   {
      leftShiftCnt = -count;
      rightShiftCnt = numBits + count;
   }

   rightShiftObj = object >> rightShiftCnt;
   leftShiftObj = object << leftShiftCnt;

   return(leftShiftObj | rightShiftObj);
}
