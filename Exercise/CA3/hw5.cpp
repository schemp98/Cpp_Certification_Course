//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// hw5.cpp
// Win10
// Visual C++ 19.0
//
// Test Program for the Shape class
//

#include "Shape.h"

using ShaunChemplavil::Circle;
using ShaunChemplavil::Square;
using ShaunChemplavil::Sphere;
using ShaunChemplavil::Cube;
using ShaunChemplavil::Shape;

int main()
{
   Shape * shapePtrArray[4];

   // arbitrary input
   double shapeInput = 12.34;

   // set up array of pointers to shapes to exercise virtual functions
   shapePtrArray[0] = new Circle(shapeInput);
   shapePtrArray[1] = new Square(shapeInput);
   shapePtrArray[2] = new Cube(shapeInput);
   shapePtrArray[3] = new Sphere(shapeInput);

   for (int shapeIdx = 0; shapeIdx < 4; shapeIdx++)
   {
      // call display virtual function via call by reference
      shapePtrArray[shapeIdx]->display();
      // Clean up dynamically allocated memory (utilizes virtual destructors)
      delete shapePtrArray[shapeIdx];
   }
}
