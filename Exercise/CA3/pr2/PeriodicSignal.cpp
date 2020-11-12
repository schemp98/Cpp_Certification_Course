//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// PeriodicSignal.cpp
// Win10
// Visual C++ 19.0
//
// File contains the member functions for the abstract class PeriodicSignal
//

#include "PeriodicSignal.h"
namespace Project2
{
   // Constructor
   PeriodicSignal::PeriodicSignal(double voltageOffset, Time timeOffset
      , double minVoltage, double maxVoltage, Time period)
      : Signal(voltageOffset, timeOffset), minVoltage(minVoltage),
      maxVoltage(maxVoltage), period(period) {}

   double PeriodicSignal::getMinVoltage() const
   {
      return minVoltage;
   }

   double PeriodicSignal::getMaxVoltage() const
   {
      return maxVoltage;
   }

   Time PeriodicSignal::getPeriod() const
   {
      return period;
   }
}
