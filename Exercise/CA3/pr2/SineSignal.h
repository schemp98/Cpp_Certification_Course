//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// SineSignal.h
// Win10
// Visual C++ 19.0
//
// File contains the class definition for the class SineSignal
//

#ifndef PROJECT2_SINESIGNAL_H
#define PROJECT2_SINESIGNAL_H

#include "PeriodicSignal.h"

namespace Project2
{
   class SineSignal : public PeriodicSignal
   {
   public:
      // Constructor
      SineSignal(double voltageOffset, Time timeOffset
         , double minVoltage, double maxVoltage, Time period);

      // need virtual destructor for memory clean up
      virtual ~SineSignal() {}

      virtual double getVoltageAtTime(Time t) const;
   };
}

#endif
