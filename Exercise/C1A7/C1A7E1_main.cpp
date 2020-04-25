//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L. Mitchell Jr.
// 04 / 25 / 2020
// C1A7E1_main.cpp
// Win10
// Visual C++ 19.0
//
// This file will take user inputs varies calls to an overloaded function
//

#include <iostream>
#include <iomanip>
using namespace std;

#include "C1A7E1_MyTime.h"

MyTime *DetermineElapsedTime(const MyTime *start, const MyTime *stop);

// Define the number of times we repeat the main body
const int REPEAT = 3;

int main()
{
   // Need to setfill, to properly display single digit hour/min/sec
   cout << setfill('0');

   // Repeat main Block REPEAT times
   for (int reps = 0; reps < REPEAT; reps++)
   {
      char delim;
      MyTime start, stop, *elapse;

      // Request and Store User Input
      cout <<
         "Enter the space separated stop and start time in HH:MM:SS format :\n";

      cin >> start.hours >> delim >> start.minutes >> delim >> start.seconds
         >> stop.hours >> delim >> stop.minutes >> delim >> stop.seconds;

      elapse = DetermineElapsedTime(&start, &stop);

      cout << "The time elapsed from "
         << setw(2) << start.hours << delim << setw(2) << start.minutes << delim
         << setw(2) << start.seconds
         << " to " << setw(2) << stop.hours << delim << setw(2) << stop.minutes
         << delim << setw(2) << stop.seconds
         << " is " << setw(2) << elapse->hours << delim << setw(2)
         << elapse->minutes << delim << setw(2) << elapse->seconds << "\n";
   }
   return 0;
}
