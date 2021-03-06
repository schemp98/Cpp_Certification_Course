//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L. Mitchell Jr.
// 04 / 19 / 2020
// C1A4E3_main.cpp
// Win10
// Visual C++ 19.0
//
// This file will take user inputs varies calls to a function with
//  default parameters in prototype function

#include <iostream>
using namespace std;

void PrintLines(int charToDisp = int('Z'), int numChars = 1, int numLines = 1);

// Define the number of times we repeat the main body
const int REPEAT = 2;

int main()
{
   // Repeat main Block REPEAT times
   for (int reps = 0; reps < REPEAT; reps++)
   {
      char inputChar;
      int numChars, numLines;

      // Request and Store User Input
      cout <<
         "Enter the following space separated items on the same line:\n"
         "Character to display.\n "
         "Number of times to display this character.\n"
         "Number of lines to display: ";

      cin >> inputChar >> numChars >> numLines;

      // Because the first input expects to be type int, we must type cast it
      PrintLines(int(inputChar), numChars, numLines);
      PrintLines(int(inputChar), numChars);
      PrintLines(int(inputChar));
      // Output 'Z' when no inputs are passed
      PrintLines();
   }
   return 0;
}
