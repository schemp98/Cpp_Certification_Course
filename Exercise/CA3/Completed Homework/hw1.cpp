//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L.Mitchell III
// hw1.cpp
// Win10
// Visual C++ 19.0
//
// File contains the Date class definition, and a test suite of its member
// functions
//

#include <iostream>
using std::cout;
using std::cerr;

const int defaultMonth = 1;

class Date
{
   int month, day, year;

public:

   // Constructor
   Date(int month, int day, int year)
   {
      setMonth(month); setDay(day); setYear(year);
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
   void display()
   {
      cout << getMonth() << "/" << getDay() << "/" << getYear() << "\n";
   }
};

int main()
{
   // declare original date variables
   int month = 10, day = 1, year = 2020;

   Date testDate(month, day, year);

   // exercise all of Date's public functions

   //exercising the display function
   cout << "The original date is: ";
   testDate.display();

   // exercising all of the set functions
   cout << "\n \nIncrement each date value of the object\n";
   testDate.setDay(++day);
   testDate.setMonth(++month);
   testDate.setYear(++year);

   // exercising all of the get functions
   cout << "New Month is " << testDate.getMonth() << "\n"
      << "New Day is " << testDate.getDay() << "\n"
      << "New Year is " << testDate.getYear() << "\n";

   // testing setMonth error handling;
   cout << "\nTest error handling of setMonth member function:\n";
   testDate.setMonth(year);
   testDate.display();
}
