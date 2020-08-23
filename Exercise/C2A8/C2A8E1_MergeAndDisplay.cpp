//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 08 / 23 / 2020
// C2A8E1_MergeAndDisplay.cpp
// Win10
// Visual C++ 19.0
//
// File contains MergeAndDisplay function, which merges text from an ifstream
// array of open files and displays them to the console, line by line, in order
// of their array location
//

#include <iostream>
#include <fstream>

using namespace std;

const int BUFSIZE = 512;

void MergeAndDisplay(ifstream files[], size_t count)
{
   int numFilesClosed = 0;
   do
   {
      // Reset counter every time do/while repeats
      numFilesClosed = 0;

      for (int fileIdx = 0; fileIdx < (int)count; fileIdx++)
      {
         // if file is open
         if (files[fileIdx].is_open())
         {
            char buf[BUFSIZE];

            // Close when we reach the end of file
            if (files[fileIdx].eof())
               files[fileIdx].close();

            // Read line from file
            files[fileIdx].getline(buf, sizeof(buf));

            // Output buf contents if line was successfully read
            if (files[fileIdx].good())
               cout << buf << "\n";
         }
         else
            numFilesClosed++;
      }
   } while (numFilesClosed < (int)count);
}
