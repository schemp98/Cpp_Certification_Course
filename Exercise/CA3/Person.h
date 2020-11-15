//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// Person.h
// Win10
// Visual C++ 19.0
//
// File contains the Person class definition
//
#ifndef SHAUNCHEMPLAVIL_PERSON_H
#define SHAUNCHEMPLAVIL_PERSON_H

#include<iostream>
#include<string>
using std::istream;
using std::ostream;
using std::string;

namespace ShaunChemplavil
{
   class Person
   {
      friend istream &operator>>(istream & in, Person & person);
      friend ostream &operator<<(ostream & out, const Person & person);

   private:
      string firstName;
      string lastName;
      int ageYears;
      double heightInches;
      double weightPounds;
   };
}
#endif
