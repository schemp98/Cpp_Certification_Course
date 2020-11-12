//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// Sensor.cpp
// Win10
// Visual C++ 19.0
//
// File contains the member functions for the abstract class Sensor
//

#include "Sensor.h"
namespace Project2
{
   // Constructor
   Sensor::Sensor(string name, Signal &source)
      :name(name), source(source) {}

   void Sensor::takeReading(Time t, DataRecorder &recorder)
   {
      recorder.log(t, getName(), getSource().getVoltageAtTime(t), getUnits());
   }

   string Sensor::getName() const
   {
      return name;
   }

   Signal & Sensor::getSource() const
   {
      return source;
   }
}
