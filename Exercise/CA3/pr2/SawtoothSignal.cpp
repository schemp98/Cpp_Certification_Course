//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// SawtoothSignal.cpp
// Win10
// Visual C++ 19.0
//
// File contains the member functions for the class SawtoothSignal
//

#include "SawtoothSignal.h"
namespace Project2
{
   // Constructor
   SawtoothSignal::SawtoothSignal(double voltageOffset, Time timeOffset
      , double minVoltage, double maxVoltage, Time period)
      : PeriodicSignal(voltageOffset, timeOffset, minVoltage, maxVoltage, period) {}

   double SawtoothSignal::getVoltageAtTime(Time t) const
   {
      // apply offset to time
      Time t_off = getTimeOffset();
      t += t_off;

      double time_seconds = (double)t.getTotalTimeAsSeconds();
      double period_seconds = (double)(getPeriod().getTotalTimeAsSeconds());

      // Equation for SawtoothSignal Voltage (function of time)
      // V(t) = vOff + min + ((t + tOff)*(max-min)/period)%(max-min)

      double voltageSpread = getMaxVoltage() - getMinVoltage();
      double numerator = time_seconds * voltageSpread / period_seconds;
      // We need to use the fmod c-function for floating point modulus
      double voltage = getVoltageOffset() + getMinVoltage() + fmod(numerator, voltageSpread);
      return voltage;
   }
}
