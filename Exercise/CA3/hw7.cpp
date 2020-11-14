//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// hw7.cpp
// Win10
// Visual C++ 19.0
//
// Test Program for the StringUtility class
//

#include "StringUtility.h"
#include <iostream>

using std::cout;
using ShaunChemplavil::StringUtility;
using std::string;
using std::vector;

int main()
{
   vector<string> strings, right, left;
   strings = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
   left = {"Mr.", "Mrs."};
   right = {"Jones", "Smith", "Williams"};

   char delimiter = ',';
   StringUtility testUtility;
   string output;

   // Test join member function of StringUtility class
   cout << "6) Testing join member function \n";
   output = testUtility.join(strings, delimiter);
   cout << output << "\n";

   // Test reverse member function of StringUtility class
   vector<string> outVec;
   cout << "\n7) Testing reverse member function\n";
   outVec = testUtility.reverse(strings);

   for (size_t i = 0; i < outVec.size(); i++)
      cout << outVec[i] << "\n";

   // Test combine member function of StringUtility class
   cout << "\n8) Testing combine member function\n";
   outVec = testUtility.combine(left, right);
   for (size_t i = 0; i < outVec.size(); i++)
      cout << outVec[i] << "\n";

   // Test leftPad member function of StringUtility class
   delimiter = '*';
   cout << "\n9) Testing leftPad member function\n";
   outVec = testUtility.leftPad(strings, delimiter);
   for (size_t i = 0; i < outVec.size(); i++)
      cout << outVec[i] << "\n";
}
