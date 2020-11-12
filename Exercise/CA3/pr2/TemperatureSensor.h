//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// TemperatureSensor.h
// Win10
// Visual C++ 19.0
//
// File contains the class definition for the class TemperatureSensor
//

#ifndef PROJECT2_TEMPERATURESENSOR_H
#define PROJECT2_TEMPERATURESENSOR_H

#include "Sensor.h"

namespace Project2
{
   class TemperatureSensor : public Sensor
   {
   public:
      // Constructor
      TemperatureSensor(string name, Signal &source);
      // need virtual destructor for memory clean up
      virtual ~TemperatureSensor() {}

   protected:
      virtual string getUnits() const;
   };
}

#endif
