//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// Sensor.h
// Win10
// Visual C++ 19.0
//
// File contains the class definition for the abstract class Sensor
//

#ifndef PROJECT2_SENSOR_H
#define PROJECT2_SENSOR_H

#include <string>
#include "Signal.h"
#include "DataRecorder.h"
using std::string;

namespace Project2
{
   class Sensor
   {
   public:
      // Constructor
      Sensor(string name, Signal &source);
      void takeReading(Time t, DataRecorder &recorder);
      // need virtual destructor for memory clean up
      virtual ~Sensor() {}

   protected:
      // pure virtual
      virtual string getUnits() const = 0;
      string getName() const;
      Signal & getSource() const;

   private:
      string name;
      Signal &source;
   };
}

#endif
