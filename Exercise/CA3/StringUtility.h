//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// StringUtility.h
// Win10
// Visual C++ 19.0
//
// File contains the StringUtility class definition
//
#ifndef SHAUNCHEMPLAVIL_STRINGUTILITY_H
#define SHAUNCHEMPLAVIL_STRINGUTILITY_H

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace ShaunChemplavil
{
   class StringUtility
   {

   public:
      string join(const vector<string> &strings, char delimiter);
      vector<string> reverse(const vector<string> &strings);
      vector<string> combine(const vector<string> &left, const vector<string> &right);
      vector<string> leftPad(const vector<string> &strings, char pad);
   };
}
#endif