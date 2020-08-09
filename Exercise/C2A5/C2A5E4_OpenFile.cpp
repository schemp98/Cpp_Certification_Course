//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 08 / 08 / 2020
// C2A5E4_OpenFile.cpp
// Win10
// Visual C++ 19.0
//
// File contains OpenFile function, which opens the file (specified via a
// pointer to the name of filename) in read mode , use the ifstream reference
//  which is also passed to it
//
#include <iostream>
#include <fstream>

using namespace std;

void OpenFile(const char *fileName, ifstream &inFile)
{
   // open fileName in "read" mode using the ifstream object inFile
   inFile.open(fileName);
   if (!inFile.is_open())
   {
      {
         cerr << "\"" << fileName << "\" :File access error!\n";
         exit(-1);
      }
   }
}
