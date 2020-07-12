//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 07 / 11 / 2020
// C2A1E7_Employee.h
// Win10
// Visual C++ 19.0
//
// Header File Employee Class definition and Get Member Function
//

#ifndef C2A1E7_EMPLOYEE_H
#define C2A1E7_EMPLOYEE_H

class Employee
{
   char *name;
   int    age;
   float raise;
   double salary;

public:

   // Definition of this prototype in C2A1E7_Employee.cpp
   // used to set member variable name
   void Set(const char *input);

   // Set Member Variable raise
   void Set(int input = 25)
   {
      age = input;
   }

   // Set Member Variable raise
   void Set(const float &input)
   {
      raise = input;
   }

   // Set Member Variable salary
   void Set(const double *input)
   {
      salary = *input;
   }

   // Constant Member Functions //

   // Get Member Variable name
   char *Get(char **input) const
   {
      *input = name;

      return name;
   }

   // Get Member Variable age
   int Get(int &input) const
   {
      input = age;

      return age;
   }
   // Get Member Variable raise
   float &Get(float &input)
   {
      input = raise;

      return raise;
   }

   // Definition of this member function prototype below
   inline double Get(double *input) const;
};

// Member function to get salary information
double Employee::Get(double *input) const
{
   *input = salary;
   return salary;
}

#endif
