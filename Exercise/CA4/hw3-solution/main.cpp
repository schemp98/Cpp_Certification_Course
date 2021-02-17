/*===========================================================================
 * Homework #3 - CSE40478
 *
 * File:    main.cpp
 * Author:  Ray Mitchell
 * Date:    4/30/2012
 *
 * Program Output:
 *    Success: 2 tests passed.
 *    Test time: 0.00 seconds.
 *===========================================================================*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
using namespace std;

#include "DigitStrippingSPA.h"
#include "StreamProcessorAlgorithm.h"
#include "UppercasingSPA.h"
using namespace RayMitchell::Homework3;

#include "UnitTest++.h"

TEST(UppercasingSPA)
{
   const string INPUT("abc def  ghi\t1jk 2lm  no3\n456");
   const string EXPECTED_OUTPUT("ABCDEFGHI1JK2LMNO3456");

   istringstream in(INPUT);
   ostringstream out;

   UppercasingSPA spa(in, out);
   spa.process();

   CHECK_EQUAL(EXPECTED_OUTPUT, out.str());
}

TEST(DigitStrippingSPA)
{
   const string INPUT("abc def  ghi\t1jk 2lm  no3\n456");
   const string EXPECTED_OUTPUT("jklmno");

   istringstream in(INPUT);
   ostringstream out;

   DigitStrippingSPA spa(in, out);
   spa.process();

   CHECK_EQUAL(EXPECTED_OUTPUT, out.str());
}

int main()
{
   return UnitTest::RunAllTests();
}