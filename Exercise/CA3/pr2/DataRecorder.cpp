// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// DataRecorder.cpp
// Win10
// Visual C++ 19.0
//
// File contains the member functions for the DataRecorder class
//

#include "DataRecorder.h"
#include<iomanip>

using std::setprecision;
using std::fixed;

namespace Project2
{
   // Constructor
   DataRecorder::DataRecorder(ostream & out)
      : out(out) {}

   void DataRecorder::log(Time timestamp, string sensorName,
      double sensorVoltage, string sensorUnits)
   {
      // We want to set the floating point precision to 2
      out << timestamp << " - " << sensorName << " - "<< setprecision(2)
         << fixed << sensorVoltage << " " << sensorUnits << "\n";
   }
}
