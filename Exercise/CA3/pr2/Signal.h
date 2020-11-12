//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// Signal.h
// Win10
// Visual C++ 19.0
//
// File contains the class definition for the abstract class Signal
//

#ifndef PROJECT2_SIGNAL_H
#define PROJECT2_SIGNAL_H

#include "Time.h"
namespace Project2
{
   class Signal
   {
   public:
      // Constructor
      Signal(double voltateOffset, Time timeOffset);
      double virtual getVoltageAtTime(Time t) const = 0;
      // need virtual destructor for memory clean up
      virtual ~Signal() {}

   protected:
      double getVoltageOffset() const;
      Time getTimeOffset() const;

   private:
      double voltageOffset;
      Time timeOffset;
   };
}

#endif
