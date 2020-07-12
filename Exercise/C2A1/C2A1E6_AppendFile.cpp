//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 07 / 11 / 2020
// C2A1E6_AppendFile.cpp
// Win10
// Visual C++ 19.0
//
// File containing definition of the AppendFile function
//

#include <iostream>
#include <fstream>

using namespace std;

const int BUFSIZE = 256;

static void ErrorAndQuit(const char *myString)
{
   cerr << "\"" << myString << "\" :File access error!\n";
   exit(-1);
}

int AppendFile(const char *inFile, const char *outFile)
{
   // Buffer Variable to hold file contents
   char buf[BUFSIZE];

   // open inFile in "read" and binary mode
   ifstream source(inFile, ios_base::binary);
   if (!source.is_open())
      ErrorAndQuit(inFile);

   // open outFile file in "append" and binary mode
   ofstream destination(outFile, ios_base::app | ios_base::binary);
   if (!destination.is_open())
      ErrorAndQuit(outFile);

   // Read each line from source into buffer
   while (source.read(buf, sizeof(buf)) && !source.eof())
      // write buffer into destination file
      if (!(destination.write(buf, sizeof(buf))))
         ErrorAndQuit(outFile);
   destination.put('\n');

   // Close open files
   if (source.is_open())
      source.close();
   if (destination.is_open())
      destination.close();

   return(0);
}
