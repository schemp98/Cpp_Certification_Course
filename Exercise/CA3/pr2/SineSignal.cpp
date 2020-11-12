//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// SineSignal.cpp
// Win10
// Visual C++ 19.0
//
// File contains the member functions for the class SineSignal
//

#include<cmath>
#include "SineSignal.h"
const double PI = 3.14159265358979323846;

namespace Project2
{
   // Constructor
   SineSignal::SineSignal(double voltageOffset, Time timeOffset
      , double minVoltage, double maxVoltage, Time period)
      : PeriodicSignal(voltageOffset, timeOffset, minVoltage, maxVoltage, period) {}

   double SineSignal::getVoltageAtTime(Time t) const
   {
      // apply offset to time
      Time t_off = getTimeOffset();
      t += t_off;

      double time_seconds = (double)t.getTotalTimeAsSeconds();
      double period_seconds = (double)(getPeriod().getTotalTimeAsSeconds());

      // Equation for SineSignal Voltage (function of time)
      // V(t) = vOff + min + (max-min)/2 +
      // sine((t+tOff)*2*PI/period)*(max-min)/2

      double voltageSpread = getMaxVoltage() - getMinVoltage();

      double voltage = getVoltageOffset() + getMinVoltage() + (1 + sin(time_seconds * 2.0 * PI / period_seconds)) * voltageSpread / 2.0;

      return voltage;
   }
}
