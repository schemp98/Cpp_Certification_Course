//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// SawtoothSignal.h
// Win10
// Visual C++ 19.0
//
// File contains the class definition for the class SawtoothSignal
//

#ifndef PROJECT2_SAWTOOTHSIGNAL_H
#define PROJECT2_SAWTOOTHSIGNAL_H

#include "PeriodicSignal.h"

namespace Project2
{
   class SawtoothSignal : public PeriodicSignal
   {
   public:
      // Constructor
      SawtoothSignal(double voltageOffset, Time timeOffset
         , double minVoltage, double maxVoltage, Time period);

      // need virtual destructor for memory clean up
      virtual ~SawtoothSignal() {}

      virtual double getVoltageAtTime(Time t) const;
   };
}

#endif
