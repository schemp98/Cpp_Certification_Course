//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 07 / 21 / 2020
// C2A2E4_OpenFile.cpp
// Win10
// Visual C++ 19.0
//
// File contains OpenFile function
//
#include <iostream>
#include <fstream>

using namespace std;

static void ErrorAndQuit(const char *myString)
{
   cerr << "\"" << myString << "\" :File access error!\n";
   exit(-1);
}

void OpenFile(const char *fileName, ifstream &inFile)
{
   // open fileName in "read" mode using the ifstream object inFile
   inFile.open(fileName);
   if (!inFile.is_open())
      ErrorAndQuit(fileName);
}
