//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 07 / 17 / 2020
// C2A1E7_Employee.cpp
// Win10
// Visual C++ 19.0
//
//  File Contains an overloaded definition of Employee::Set member function
//  which sets the value of the 'name' member variable of the Employee Class
//

#include "C2A1E7_Employee.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Employee::Set(const char *input)
{
   //  When determining the size of the character string need to account for
   // null character by adding one to the output of strlen
   size_t numChar = strlen(input) + 1;
   char *temp;

   // Allocate memory  and verify success
   if ((temp = new (nothrow) char[numChar]) == NULL)
   {
      cerr << "Failed to allocate memory for temp!\n";
      exit(EXIT_FAILURE);
   }

   // set name to temp
   name = temp;

   // copy data located at input pointer into newly allocated memory
   memcpy(temp, input, numChar);
}
