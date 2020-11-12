//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// ConstantSignal.cpp
// Win10
// Visual C++ 19.0
//
// File contains the member functions for the  class ConstantSignal
//

#include "ConstantSignal.h"
namespace Project2
{
   // Constructor
   ConstantSignal::ConstantSignal(double voltageOffset, Time timeOffset)
      : Signal(voltageOffset, timeOffset) {}

   double ConstantSignal::getVoltageAtTime(Time t) const
   {
      // Because Constant Signal is constant, merely return Voltage Offset
      return getVoltageOffset();
   }
}
