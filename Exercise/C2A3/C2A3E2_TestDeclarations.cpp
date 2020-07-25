//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 07 / 24 / 2020
// C2A3E2_TestDeclarations.cpp
// Win10
// Visual C++ 19.0
//
// File containing definition of the TestDeclarations function, it contains
// five single statements to test understanding of "Reverse Right-Left" rule
//

const int ARRAY_SIZE = 6;

void TestDeclarations()
{
   long **(*afe)[ARRAY_SIZE];                    //1
   float (*pv)(int(*pa)[ARRAY_SIZE]) = 0;        //2
   afe = (long **(*)[ARRAY_SIZE])pv;             //3
   int &rF1(double *precision);                  //4
   int *rF3(double &precision);                  //5
}
