//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L.Mitchell III
// hw2.cpp
// Win10
// Visual C++ 19.0
//
// Test Program for the Date class
//

#include <iostream>
#include "Date.h"
using std::cout;
using std::cerr;

int main()
{
   // declare original date variables (arbitrary values)
   int month = 6, day = 1, year = 2015;

   // exercise all of Date's public functions
   ShaunChemplavil::Date validDate(month, day, year), todaysDate;

   //exercising the display function
   cout << "The today's date is: ";
   todaysDate.display();

   //exercising the display function
   cout << "The declared date is: ";
   validDate.display();

   // exercising all of the get functions
   cout << "Declared Month is " << validDate.getMonth() << "\n"
      << "Declared Day is " << validDate.getDay() << "\n"
      << "Declared Year is " << validDate.getYear() << "\n";

   // testing setMonth error handling;
   cout << "\n\nTest error handling of invalid Month:\n";
   ShaunChemplavil::Date badMonth(year, day, year);
   cout << "Confirm that garbage is in object\n";
   badMonth.display();

   cout << "\nTest error handling of invalid Day:\n";
   ShaunChemplavil::Date badDay(month, year, year);
   cout << "Confirm that garbage is in object\n";
   badDay.display();

   cout << "\nTest error handling of invalid Year:\n";
   ShaunChemplavil::Date badYear(month, day, -year);
   cout << "Confirm that garbage is in object\n";
   badYear.display();
}
