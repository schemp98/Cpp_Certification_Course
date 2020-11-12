//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L.Mitchell III
// hw2.h
// Win10
// Visual C++ 19.0
//
// File contains the Date class definition, and a test suite of its member
// functions
//
#ifndef SHAUNCHEMPLAVIL_DATE_H
#define SHAUNCHEMPLAVIL_DATE_H

#include <iostream>
#include <ctime>
using std::cerr;

const int defaultMonth = 1;
namespace ShaunChemplavil
{
   class Date
   {
   public:

      // Constructor
      Date(int month, int day, int year)
      {
         setMonth(month); setDay(day); setYear(year);
      }

      // Default constructor using current system time
      Date()
      {
         time_t currTime = time(0);
         tm *sysTime = localtime(&currTime);
         setMonth(sysTime->tm_mon);
         setDay(sysTime->tm_mday);
         setYear(sysTime->tm_year);
      }
      void setMonth(int month)
      {
         // Check if input is valid
         // Error Case
         if ((month < 1) || (month > 12))
         {
            this->month = defaultMonth; // Default Value
            cerr << "\nERROR: INVALID MONTH VALUE, setting month to "
               << defaultMonth << "\n";
         }
         // Valid inputs
         else
            this->month = month;
      }

      int getMonth()
      {
         return this->month;
      }

      void setDay(int day)
      {
         this->day = day;
      }

      int getDay()
      {
         return this->day;
      }
      void setYear(int year)
      {
         this->year = year;
      }

      int getYear()
      {
         return this->year;
      }

      // Print Date in "standard" US calendar format
      void display();

   private:
      int month, day, year;
   };
}
#endif
