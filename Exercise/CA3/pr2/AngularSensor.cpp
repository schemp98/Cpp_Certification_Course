//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// AngularSensor.cpp
// Win10
// Visual C++ 19.0
//
// File contains the member functions for the class AngularSensor
//

#include "AngularSensor.h"
const string angularSensorUnits = "Radians";

namespace Project2
{
   // Constructor
   AngularSensor::AngularSensor(string name, Signal &source)
      :Sensor(name, source) {}

   string AngularSensor::getUnits() const
   {
      return angularSensorUnits;
   }
}
