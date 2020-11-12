// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// Time.cpp
// Win10
// Visual C++ 19.0
//
// File contains the member functions for the Time class
//

#include "Time.h"
const int hour2sec = 3600;
const int min2sec = 60;

namespace Project2
{
   // Constructor, converts hours, minutes, seconds to seconds
   Time::Time(int hours, int minutes, int seconds)
      : seconds(hours * hour2sec + min2sec * minutes + seconds) {}

   // Displays seconds in hours, minutes, seconds
   ostream &operator<<(ostream &out, const Time &value)
   {
      int h = value.seconds / hour2sec;
      int m = (value.seconds - h * hour2sec) / min2sec;
      int s = value.seconds - (h * hour2sec + m * min2sec);
      out << h << "h:" << m << "m:" << s << "s";
      return out;
   }

   int Time::getTotalTimeAsSeconds()
   {
      return(seconds);
   }

   Time Time::operator+=(Time const rhs)
   {
      seconds += rhs.seconds;
      return(*this);
   }
}
