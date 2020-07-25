//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 07 / 17 / 2020
// C2A1E6_AppendFile.cpp
// Win10
// Visual C++ 19.0
//
// File containing definition of the AppendFile function, which appends the
// contents of 'inFile' to 'outFile', this is done in binary mode
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
   // Keep track of the bytes read from binary files
   streamsize bytesRead;

   // open inFile in "read" and binary mode
   ifstream source(inFile, ios_base::binary);
   if (!source.is_open())
      ErrorAndQuit(inFile);

   // open outFile in "append" and binary mode
   ofstream destination(outFile, ios_base::app | ios_base::binary);
   if (!destination.is_open())
   {
      // close all open files because an error has occurred
      source.close();
      ErrorAndQuit(outFile);
   }

   do
   {
      // Buffer to hold file contents
      char buf[BUFSIZE];

      // Read block of data from source into buffer
      source.read(buf, sizeof(buf));

      if (bytesRead = source.gcount())
         // write buffer into destination file
         destination.write(buf, bytesRead);
   } while (bytesRead == BUFSIZE);

   // Close open files
   source.close();
   destination.close();

   return(0);
}
