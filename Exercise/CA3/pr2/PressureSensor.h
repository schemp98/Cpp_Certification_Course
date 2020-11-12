//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// PressureSensor.h
// Win10
// Visual C++ 19.0
//
// File contains the class definition for the class PressureSensor
//

#ifndef PROJECT2_PRESSURESENSOR_H
#define PROJECT2_PRESSURESENSOR_H

#include "Sensor.h"

namespace Project2
{
   class PressureSensor : public Sensor
   {
   public:
      // Constructor
      PressureSensor(string name, Signal &source);
      // need virtual destructor for memory clean up
      virtual ~PressureSensor() {}

   protected:
      virtual string getUnits() const;
   };
}

#endif
