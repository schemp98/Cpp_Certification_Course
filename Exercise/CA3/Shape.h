//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 151116  Raymond L. Mitchell III
// Complex.h
// Win10
// Visual C++ 19.0
//
// File contains the class definition for Shape, TwoDimensionalShape,
// ThreeDimensionalShape, Circle, Square, Sphere and Cube
//

#ifndef SHAUNCHEMPLAVIL_SHAPE_H
#define SHAUNCHEMPLAVIL_SHAPE_H

namespace ShaunChemplavil
{
   class Shape
   {
   public:
      // need virtual destructor for memory clean up
      virtual ~Shape() {}
      // pure virtual function
      virtual void display() const = 0;
   };

   class TwoDimensionalShape : public Shape
   {
   public:
      // need virtual destructor for memory clean up
      virtual ~TwoDimensionalShape() {}
      // pure virtual function
      virtual double getArea() const = 0;
   };

   class ThreeDimensionalShape : public Shape
   {
   public:
      // need virtual destructor for memory clean up
      virtual ~ThreeDimensionalShape() {}
      // pure virtual functions
      virtual double getSurfaceArea() const = 0;
      virtual double getVolume() const = 0;
   };

   class Circle : public TwoDimensionalShape
   {
   public:
      Circle(double radius);
      virtual ~Circle() {}  // need virtual destructor for memory clean up
      virtual void display() const;
      virtual double getArea() const;

   private:
      double radius;
   };

   class Square : public TwoDimensionalShape
   {
   public:
      Square(double lengthOfSide);
      virtual ~Square() {}  // need virtual destructor for memory clean up
      virtual void display() const;
      virtual double getArea() const;

   private:
      double lengthOfSide;
   };

   class Sphere : public ThreeDimensionalShape
   {
   public:
      Sphere(double radius);
      virtual ~Sphere() {}  // need virtual destructor for memory clean up
      virtual void display() const;
      virtual double getSurfaceArea() const;
      virtual double getVolume() const;

   private:
      double radius;
   };

   class Cube : public ThreeDimensionalShape
   {
   public:
      Cube(double lengthOfSide);
      virtual ~Cube() {}  // need virtual destructor for memory clean up
      virtual void display() const;
      virtual double getSurfaceArea() const;
      virtual double getVolume() const;

   private:
      double lengthOfSide;
   };
}

#endif
