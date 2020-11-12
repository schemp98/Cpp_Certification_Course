//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// Complex.cpp
// Win10
// Visual C++ 19.0
//
// File contains the member functions for Circle, Square, Sphere and Cube class
//

#include <iostream>
#include "Shape.h"

using std::cout;

const double  PI = 3.141592653589793238462;

using ShaunChemplavil::Shape;
using ShaunChemplavil::TwoDimensionalShape;
using ShaunChemplavil::ThreeDimensionalShape;

using ShaunChemplavil::Circle;
using ShaunChemplavil::Square;
using ShaunChemplavil::Sphere;
using ShaunChemplavil::Cube;

// Default Constructor
Circle::Circle(double radius)
   : radius(radius) {}

double Circle::getArea() const
{
   // area = pi*radius^2
   return (radius * radius * PI);
}

void Circle::display() const
{
   cout << "Circle with radius " << radius << " has area " << getArea() << "\n";
}

// Default Constructor
Square::Square(double lengthOfSide)
   : lengthOfSide(lengthOfSide) {}

double Square::getArea() const
{
   // area = lengthOfSide^2
   return (lengthOfSide * lengthOfSide);
}

void Square::display() const
{
   cout << "Square with length of side " << lengthOfSide
      << " has area " << getArea() << "\n";
}

Sphere::Sphere(double radius)
   : radius(radius) {}

double Sphere::getSurfaceArea() const
{
   // surface area = 4*pi*r^2
   return (4.0 * PI * radius * radius);
}

double Sphere::getVolume() const
{
   // volume = 4/3*pi*r^3
   return (getSurfaceArea() * radius / 3.0);
}

void Sphere::display() const
{
   cout << "Sphere with radius " << radius << " has area "
      << getSurfaceArea() << " and volume " << getVolume() << "\n";
}

// Default Constructor
Cube::Cube(double lengthOfSide)
   : lengthOfSide(lengthOfSide) {}

double Cube::getSurfaceArea() const
{
   // surface area = 6*lengthofSide^2
   return (lengthOfSide * lengthOfSide * 6.0);
}

double Cube::getVolume() const
{// surface area = lengthofSide^3
   return (lengthOfSide * lengthOfSide * lengthOfSide);
}
void Cube::display() const
{
   cout << "Cube with length of side " << lengthOfSide << " has area " << getSurfaceArea()
      << " and volume " << getVolume() << "\n";
}
