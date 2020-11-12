//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// Time.h
// Win10
// Visual C++ 19.0
//
// File contains the class definition for the Time class
//

#ifndef PROJECT2_TIME_H
#define PROJECT2_TIME_H

#include<iostream>

using std::ostream;

namespace Project2
{
   class Time
   {
      friend ostream &operator<<(ostream &os, const Time &value);

   public:
      Time(int hours, int minute, int seconds);
      int getTotalTimeAsSeconds();
      Time operator+=(Time const rhs);

   private:
      int seconds;
   };
}
#endif
