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

void ErrorAndQuit(const char *myString)
{
   cerr << "\"" << myString << "\" :File access error!\n";
   exit(EXIT_FAILURE);
}

int AppendFile(const char *inFile, const char *outFile)
{
   char buf[BUFSIZE];

   // open SOURCE_FILE in "read" mode
   ifstream source(inFile, ios_base::in || ios_base::binary);
   if (!source.is_open())
      ErrorAndQuit(inFile);

   // open destination file in "append" mode
   ofstream destination(outFile, ios_base::app);
   if (!destination.is_open())
      ErrorAndQuit(outFile);

   //// Read each line from source
   while (source.getline(buf, sizeof(buf)) && !source.eof())
   {
      // Write line into destination file
      destination.write(&buf[0], sizeof(buf));

      // Add new line character;
      destination << '\n';
   }

   // Close open files
   source.close();
   destination.close();

   return(0);
}
