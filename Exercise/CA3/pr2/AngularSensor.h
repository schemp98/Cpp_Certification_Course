//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// AngularSensor.h
// Win10
// Visual C++ 19.0
//
// File contains the class definition for the class AngularSensor
//

#ifndef PROJECT2_ANGULARSENSOR_H
#define PROJECT2_ANGULARSENSOR_H

#include "Sensor.h"

namespace Project2
{
   class AngularSensor : public Sensor
   {
   public:
      // Constructor
      AngularSensor(string name, Signal &source);
      // need virtual destructor for memory clean up
      virtual ~AngularSensor() {}

   protected:
      virtual string getUnits() const;
   };
}

#endif
