//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L. Mitchell Jr.
// 04 / 25 / 2020
// C1A7E1_DetermineElapsedTime.cpp
// Win10
// Visual C++ 19.0
//
// This file calculates the elasped time between two MyTime variables
//

#include "C1A7E1_MyTime.h"

const int HOURS_TO_SECS = 3600;
const int MINUTES_TO_SECS = 60;
const long DAYS_TO_SECS = 86400;

MyTime *DetermineElapsedTime(const MyTime *startTime, const MyTime *stopTime)
{
   long startTimeSec, stopTimeSec, elaspedTimeSec;
   static MyTime elapsedTime;

   // Convert Start and Stop Time to seconds
   startTimeSec = (long)startTime->seconds;
   startTimeSec += (long)(startTime->minutes * MINUTES_TO_SECS);
   startTimeSec += (long)(startTime->hours * HOURS_TO_SECS);

   stopTimeSec = (long)stopTime->seconds;
   stopTimeSec += (long)(stopTime->minutes * MINUTES_TO_SECS);
   stopTimeSec += (long)(stopTime->hours * HOURS_TO_SECS);

   elaspedTimeSec = stopTimeSec - startTimeSec;

   // When elaspedTimeSec is negative, stopTime refers to next day
   // so we must add DAYS_TO_SECS
   if (elaspedTimeSec <= 0)
   {
      elaspedTimeSec += DAYS_TO_SECS;
   }

   // Format result for MyTime structure
   elapsedTime.hours = (int)(elaspedTimeSec / (long)HOURS_TO_SECS);

   // Remove seconds associated with the hours captured above
   elaspedTimeSec %= (long)HOURS_TO_SECS;
   elapsedTime.minutes = (int)(elaspedTimeSec / (long)MINUTES_TO_SECS);

   // Remove seconds associated with the minute captured above
   elaspedTimeSec %= (long)MINUTES_TO_SECS;
   elapsedTime.seconds = (int)elaspedTimeSec;

   return(&elapsedTime);
}
