//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// PeriodicSignal.h
// Win10
// Visual C++ 19.0
//
// File contains the class definition for the abstract class PeriodicSignal
//

#ifndef PROJECT2_PERIODICSIGNAL_H
#define PROJECT2_PERIODICSIGNAL_H

#include "Signal.h"

namespace Project2
{
   class PeriodicSignal : public Signal
   {
   public:
      // Constructor
      PeriodicSignal(double voltageOffset, Time timeOffset
         , double minVoltage, double maxVoltage, Time period);

      // need virtual destructor for memory clean up
      virtual ~PeriodicSignal() {}

   protected:
      double getMinVoltage() const;
      double getMaxVoltage() const;
      Time getPeriod() const;

   private:
      double minVoltage, maxVoltage;
      Time period;
   };
}

#endif
