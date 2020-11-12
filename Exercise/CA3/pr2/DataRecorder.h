//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// DataRecorder.h
// Win10
// Visual C++ 19.0
//
// File contains the class definition for the Data Recorder class
//

#ifndef PROJECT2_DATARECORDER_H
#define PROJECT2_DATARECORDER_H

#include<iostream>
#include<string>

#include "Time.h"

using std::ostream;
using std::string;

namespace Project2
{
   class DataRecorder
   {

   public:
      DataRecorder(ostream & out);
      void log(Time timestamp, string sensorName,
         double sensorVoltage, string sensorUnits);

   private:
      ostream& out;
   };
}
#endif
