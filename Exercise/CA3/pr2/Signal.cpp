//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// Signal.cpp
// Win10
// Visual C++ 19.0
//
// File contains the member functions for the abstract class Signal
//

#include "Signal.h"
namespace Project2
{
   // Constructor
   Signal::Signal(double voltageOffset, Time timeOffset)
      : voltageOffset(voltageOffset), timeOffset(timeOffset) {}

   double Signal::getVoltageOffset() const
   {
      return voltageOffset;
   }

   Time Signal::getTimeOffset() const
   {
      return timeOffset;
   }
}
