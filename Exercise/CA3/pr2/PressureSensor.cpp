//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// PressureSensor.cpp
// Win10
// Visual C++ 19.0
//
// File contains the member functions for the class PressureSensor
//

#include "PressureSensor.h"
const string PressureSensorUnits = "Pounds per square inch (PSI)";

namespace Project2
{
   // Constructor
   PressureSensor::PressureSensor(string name, Signal &source)
      :Sensor(name, source) {}

   string PressureSensor::getUnits() const
   {
      return PressureSensorUnits;
   }
}
