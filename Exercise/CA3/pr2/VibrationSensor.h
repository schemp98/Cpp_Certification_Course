//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// VibrationSensor.h
// Win10
// Visual C++ 19.0
//
// File contains the class definition for the class VibrationSensor
//

#ifndef PROJECT2_VIBRATIONSENSOR_H
#define PROJECT2_VIBRATIONSENSOR_H

#include "Sensor.h"

namespace Project2
{
   class VibrationSensor : public Sensor
   {
   public:
      // Constructor
      VibrationSensor(string name, Signal &source);
      // need virtual destructor for memory clean up
      virtual ~VibrationSensor() {}

   protected:
      virtual string getUnits() const;
   };
}

#endif
