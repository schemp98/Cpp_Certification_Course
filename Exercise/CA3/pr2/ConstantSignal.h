//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// ConstantSignal.h
// Win10
// Visual C++ 19.0
//
// File contains the class definition for the class ConstantSignal
//

#ifndef PROJECT2_CONSTANTSIGNAL_H
#define PROJECT2_CONSTANTSIGNAL_H

#include "Signal.h"

namespace Project2
{
   class ConstantSignal : public Signal
   {
   public:
      // Constructor
      ConstantSignal(double voltageOffset, Time timeOffset);

      // need virtual destructor for memory clean up
      virtual ~ConstantSignal() {}
      virtual double getVoltageAtTime(Time t) const;
   };
}

#endif
