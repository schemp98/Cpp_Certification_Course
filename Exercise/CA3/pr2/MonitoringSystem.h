//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// MonitoringSystem.h
// Win10
// Visual C++ 19.0
//
// File contains the member functions for the class MonitoringSystem
//

#ifndef PROJECT2_MONITORINGSYSTEM_H
#define PROJECT2_MONITORINGSYSTEM_H

#include "Sensor.h"
#include "DataRecorder.h"

const int MAX_SENSORS = 10;

namespace Project2
{
   class MonitoringSystem
   {
   public:
      // Constructor
      MonitoringSystem(ostream &out);

      void addSensor(Sensor * s);
      void takeReading(Time t);
   private:
      DataRecorder recorder;
      // Initialize an Array of Null pointers
      Sensor* sensors[MAX_SENSORS] = {0};
   };
}

#endif
