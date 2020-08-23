//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 08 / 19 / 2020
// C2A7E2_ListHex.cpp
// Win10
// Visual C++ 19.0
//
// File contains ListHex function, which display the characters of a file
// as hexadecimal pairs, a new line is created once the number of bytesPerLine
// has been met
//

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void ListHex(ifstream &inFile, int bytesPerLine)
{
   int hexBytes = 0;

   // Set persistent I/O manipulators
   cout << setfill('0') << hex;

   do
   {
      char buf;
      inFile.get(buf);

      if (inFile.gcount())
      {
         // If not the first character of the line, place a preceding space
         // this avoids having a trailing whitespace character
         if (++hexBytes % bytesPerLine != 1)
            cout << ' ';

         // protect against sign extension bytes by typecasting to unsigned char
         // to display hexadecimal additional typecast to int
         cout << setw(2) << (int)(unsigned char)buf;

         // keep track of the number of characters we've displayed
         if (!(hexBytes % bytesPerLine))
            cout << '\n';
      }
   } while (inFile.good());
}
