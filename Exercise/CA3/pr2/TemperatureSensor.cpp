//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// TemperatureSensor.cpp
// Win10
// Visual C++ 19.0
//
// File contains the member functions for the class TemperatureSensor
//

#include "TemperatureSensor.h"
const string TemperatureSensorUnits = "Degrees Celsius";

namespace Project2
{
   // Constructor
   TemperatureSensor::TemperatureSensor(string name, Signal &source)
      :Sensor(name, source) {}

   string TemperatureSensor::getUnits() const
   {
      return TemperatureSensorUnits;
   }
}
