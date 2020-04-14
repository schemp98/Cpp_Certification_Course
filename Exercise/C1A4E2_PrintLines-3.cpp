//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L. Mitchell Jr.
// 04 / 13 / 2020
// C1A4E2_PrintLines-3.cpp
// Win10
// Visual C++ 19.0
//
// This file returns takes user character input and displays the number of times
//  designated by the second input, and repeats this according to the third
//  input
//

#include <iostream>
using namespace std;

void PrintLines(int charsToDisplay, int numberOfCharacters, int numberOfLines)
{
   // Loop tracking the number of lines to display
   for (int lineCnt = 0; lineCnt < numberOfLines; lineCnt++)
   {
      // Loop tracking the number of characters to display
      for (int charCnt = 0; charCnt < numberOfCharacters; charCnt++)
      {
         cout << char(charsToDisplay);
      }
      cout << "\n";
   }
}
