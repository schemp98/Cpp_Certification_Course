//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// MonitoringSystem.cpp
// Win10
// Visual C++ 19.0
//
// File contains the member functions for the class MonitoringSystem
//

#include "MonitoringSystem.h"

namespace Project2
{
   // Constructor
   MonitoringSystem::MonitoringSystem(ostream &out)
      :recorder(out) {}

   void MonitoringSystem::addSensor(Sensor * s)
   {
      for (int sensorIdx = 0; sensorIdx < MAX_SENSORS; sensorIdx++)
      {
         // if pointer is NULL add sensor
         if (sensors[sensorIdx] == 0)
         {
            sensors[sensorIdx] = s;
            break;
         }
      }
   }

   void MonitoringSystem::takeReading(Time t)
   {
      for (int sensorIdx = 0; sensorIdx < MAX_SENSORS; sensorIdx++)
      {
         // if pointer is NULL no more sensors to take a reading from
         if (sensors[sensorIdx] == 0)
            break;

         // Otherwise Take a reading
         sensors[sensorIdx]->takeReading(t, recorder);
      }
   }
}
