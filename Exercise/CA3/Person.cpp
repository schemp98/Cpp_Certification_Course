//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// Person.cpp
// Win10
// Visual C++ 19.0
//
// File contains the member functions for the Person class
//

#include "Person.h"

namespace ShaunChemplavil
{
   //place contents of a Person object into an output stream
   ostream &operator<<(ostream &out, const Person &person)
   {
      out << person.firstName << " "
         << person.lastName << " "
         << person.ageYears << " "
         << person.heightInches << " "
         << person.weightPounds;

      return out;
   }
   //place from input stream into a Person object
   istream &operator>>(istream &in, Person &person)
   {
      in >> person.firstName
         >> person.lastName
         >> person.ageYears
         >> person.heightInches
         >> person.weightPounds;

      return in;
   }
}
