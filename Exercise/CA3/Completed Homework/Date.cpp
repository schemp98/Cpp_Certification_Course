//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L.Mitchell III
// Date.cpp
// Win10
// Visual C++ 19.0
//
// File contains the display member function for the Date class
//

#include <iostream>
#include "Date.h"
using std::cout;

// Print Date in "standard" US calendar format
void ShaunChemplavil::Date::display() const
{
   cout << getMonth() << "/" << getDay() << "/" << getYear() << "\n";
}
