//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// VibrationSensor.cpp
// Win10
// Visual C++ 19.0
//
// File contains the member functions for the class VibrationSensor
//

#include "VibrationSensor.h"
const string VibrationSensorUnits = "Hertz (Hz)";

namespace Project2
{
   // Constructor
   VibrationSensor::VibrationSensor(string name, Signal &source)
      :Sensor(name, source) {}

   string VibrationSensor::getUnits() const
   {
      return VibrationSensorUnits;
   }
}
