//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// Array.h
// Win10
// Visual C++ 19.0
//
// File contains the class definition for Array template class
//

#ifndef SHAUNCHEMPLAVIL_ARRAY_H
#define SHAUNCHEMPLAVIL_ARRAY_H

#include<iostream>
#include <stdexcept>

using std::invalid_argument;
using std::cerr;

namespace ShaunChemplavil
{
   template <typename ElemType = int, int SIZE = 3>
   class Array
   {
   public:
      // Default Constructor
      Array() {}

      // Copy Constructor
      Array(const Array &source)
      {
         for (int idx = 0; idx < SIZE; idx++)
            elements[idx] = source.elements[idx];
      }

      // Copy Assignment Operator
      const Array &operator=(const Array &source)
      {
         // Prevent Self-Assignment
         if (this == &source)
            return *this;

         for (int idx = 0; idx < SIZE; idx++)
            elements[idx] = source.elements[idx];

         //*this = source;

         return *this;
      }

      bool operator==(const Array &other) const
      {
         for (int idx = 0; idx < SIZE; idx++)
            if (elements[idx] != other.elements[idx])
               return false;

         return true;
      }

      bool operator!=(const Array &other) const
      {
         return(!(*this == other));
      }

      // Subscript operator (L-value version)
      ElemType& operator[](int index)
      {
         try
         {
            // check if valid index
            if ((index < 0) || (index >= SIZE))
               throw invalid_argument{"Subscript out of range (L-Value)"};

            return elements[index];
         }
         catch (invalid_argument &ex)
         {
            cerr << "Invalid Argument: " << ex.what() << "\n";
            return elements[0];
         }
      }

      // Subscript operator (R-value version)
      ElemType operator[](int index) const
      {
         try
         {
            // check if valid index
            if ((index < 0) || (index >= SIZE))
               throw invalid_argument{"Subscript out of range (R-Value)"};

            return elements[index];
         }
         catch (invalid_argument &ex)
         {
            cerr << "Invalid Argument: " << ex.what() << "\n";
            return elements[0];
         }
      }

   private:
      ElemType elements[SIZE];
   };
}

#endif
