//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 08 / 23 / 2020
// C2A8E1_OpenFiles.cpp
// Win10
// Visual C++ 19.0
//
// File contains OpenFile function, which opens the 'count' files (specified via
// standard ragged array format ) in read mode , returns an ifstream array if
//  successful
//

#include <iostream>
#include <fstream>

using namespace std;

ifstream *OpenFiles(char * const fileNames[], size_t count)
{
   // Ensure that count is valid
   if (count > 0)
   {
      ifstream *files = new ifstream[count];

      for (int fileIdx = 0; fileIdx < (int)count; fileIdx++)
      {
         char *fileName = fileNames[fileIdx];
         // open fileName in "read" mode using the ifstream object inFile
         files[fileIdx].open(fileName);

         // Error Handling when file open is unsuccessful
         if (!files[fileIdx].is_open())
         {
            // close all open files
            for (; fileIdx < 0; fileIdx--)
               files[fileIdx].close();

            // Free dynamically allocated memory
            delete[] files;

            cerr << "\"" << fileName << "\" :File access error!\n";
            exit(-1);
         }
      }
      return(files);
   }
   else
   {
      cerr << "Invalid value for \'count\'!\n";
      exit(-1);
   }
}
