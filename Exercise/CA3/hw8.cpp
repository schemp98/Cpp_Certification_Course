//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// hw8.cpp
// Win10
// Visual C++ 19.0
//
// Test Program for the Person class
//

#include "Person.h"
#include<fstream>
#include<sstream>

using std::cerr;

using std::cout;
using std::ostringstream;
using std::string;
using std::ifstream;
using std::ios;

using ShaunChemplavil::Person;

const string INPUT_FILE = "hw8-input.txt";

int main()
{
   ifstream in(INPUT_FILE, ios::in);
   ostringstream out;
   Person person;

   //check if file open was successful
   if (!in)
   {
      cerr << "Error opening file\n";
      return(1);
   }

   // Extract next person from file, add newline char, and insert this into a
   // stringstream
   while (in >> person)
      out << person << "\n";

   // Output the contents of the stringstream to the display
   cout << out.str();
}
