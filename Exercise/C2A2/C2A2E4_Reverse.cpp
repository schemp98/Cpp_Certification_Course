//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 07 / 21 / 2020
// C2A2E4_Reverse.cpp
// Win10
// Visual C++ 19.0
//
// File contains Reverse function, it recursively reads in characters from a
// text file in inFile, until a separator (defined as whitespace .?!!,:; or EOF)
// is encountered, then the characters are displayed in reverse order with the
// last and next to next to last characters being displayed as capitalized
//

#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

// Define the "levels" that we want to force a capitalization
const int CAPLEVEL1 = 1;
const int CAPLEVEL2 = 3;

// Function to check if character is a 'separator'
inline bool isSeparator(int thisChar)
{
   return(isspace(thisChar) || thisChar == '.' || thisChar == '?' ||
      thisChar == '!' || thisChar == ',' || thisChar == ':' ||
      thisChar == ';' || thisChar == EOF);
}

int Reverse(ifstream &inFile, const int level)
{
   int thisChar;

   // Get Current Character
   thisChar = inFile.get();

   // Return character if it is a separator
   if (isSeparator(thisChar))
      return(thisChar);

   // if not a separator, continue reversing
   int thisSeparator;
   thisSeparator = Reverse(inFile, level + 1);

   //  Capitalize character if last or "next to next to last" character
   if (level == CAPLEVEL1 || level == CAPLEVEL2)
      cout << (char)toupper(thisChar);
   else
      cout << (char)thisChar;

   return thisSeparator;
}
