//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L. Mitchell Jr.
// 05 / 08 / 2020
// C1A8E3_main.cpp
// Win10
// Visual C++ 19.0
//
// This program will take command line arguments to 'find and replace' items
// within a text file the output will be in a new text file
//

#include <iostream>
#include <fstream>

using namespace std;

const int BUFSIZE = 256;
const int EXPECTED_ARGS = 5;
const int SOURCE_ARG = 1;
const int DESTIN_ARG = 2;
const int SEARCH_ARG = 3;
const int REPLAC_ARG = 4;

void ErrorAndQuit(const char *myString)
{
   cerr << "\"" << myString << "\" :File access error!\n";
   exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
   // Check to make ensure correct amount of arguments,
   if (argc != EXPECTED_ARGS)
   {
      cerr << "Unexpected number of arguments!\n";
      exit(EXIT_FAILURE);
   }

   char buf[BUFSIZE], *sourceFile, *destFile, *searchString, *replaceString;

   size_t numOff;

   sourceFile = argv[SOURCE_ARG];
   destFile = argv[DESTIN_ARG];
   searchString = argv[SEARCH_ARG];
   replaceString = argv[REPLAC_ARG];

   // open SOURCE_FILE in "read" mode
   ifstream source(sourceFile);
   if (!source.is_open())
      ErrorAndQuit(sourceFile);

   // open destination file in "append" mode
   ofstream destination(destFile, ios_base::app);
   if (!destination.is_open())
      ErrorAndQuit(destFile);

   // Determine to offset applied to "write" pointer when searchString found
   numOff = strlen(searchString);

   // Read each line from source
   while (source.getline(buf, sizeof(buf)) && !source.eof())
   {
      char *pSrch, *pline;

      // Place character from beginning of line until searchString location
      for (pline = &buf[0]; pSrch = strstr(pline, searchString);)
      {
         // Write characters up to searchString
         destination.write(pline, pSrch - pline);

         // Write replaceString instead
         destination << replaceString;
         //Offset pline to location after searchString
         pline = pSrch + numOff;
      }

      // Write remaining character of line and include '\n'
      destination << pline << '\n';
   }

   // Close open files
   source.close();
   destination.close();

   return(EXIT_SUCCESS);
}
