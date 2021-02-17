/*===========================================================================
 * Homework #1 - CSE40478
 *
 * File:    UnitTests.h
 * Author:  Ray Mitchell
 * Date:    4/16/2011
 *===========================================================================*/
#ifndef RAYMITCHELL_HOMEWORK1_UNITTESTS_H
#define RAYMITCHELL_HOMEWORK1_UNITTESTS_H

namespace RayMitchell { namespace Homework1
{
   class UnitTests
   {
   public:
      static void Test1();
      static void Test2();
      static void Test3();
      static void TestAll();

   private:
      // Private constructor prevents instantiation
      UnitTests() {}
   };
}}

#endif