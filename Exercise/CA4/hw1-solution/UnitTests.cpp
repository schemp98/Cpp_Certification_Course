/*===========================================================================
 * Homework #1 - CSE40478
 *
 * File:    UnitTests.cpp
 * Author:  Ray Mitchell
 * Date:    4/16/2011
 *===========================================================================*/
#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#include "UnitTests.h"
using RayMitchell::Homework1::UnitTests;

//-----------------------------------------------------------------------------
// Helpers
//-----------------------------------------------------------------------------
static int generateNaturalNumbers()
{
   static int i = 1;
   return i++;
}

static bool isEven(int i)
{
   return i % 2 == 0;
}

//-----------------------------------------------------------------------------
// Tests
//-----------------------------------------------------------------------------
void
UnitTests::Test1()
{
   const int EXPECTED_RESULT = 55;

   // Initialize deque
   deque<int> d;
   generate_n(back_inserter(d), 10, generateNaturalNumbers);

   // Sum values in deque
   int sum = accumulate(d.begin(), d.end(), 0);

   // Verify result
   if (sum == EXPECTED_RESULT)
      clog << "Test1 PASSED";
   else
      clog << "Test1 FAILED, expected " << EXPECTED_RESULT << ", saw " << sum;
   clog << "\n";
}

void
UnitTests::Test2()
{
   const string EXPECTED_RESULT("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

   // Initialize string
   string s("abcdefghijklmnopqrstuvwxyz");

   // Convert string to upper case
   transform(s.begin(), s.end(), s.begin(), toupper);

   // Verify result
   if (s == EXPECTED_RESULT)
      clog << "Test2 PASSED";
   else
      clog << "Test2 FAILED, expected " << EXPECTED_RESULT << ", saw " << s;
   clog << "\n";
}

void
UnitTests::Test3()
{
   const string EXPECTED_RESULT("24681013579");

   // Initialize vector
   int data[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
   vector<int> v(data, data + 10);

   // Partition vector into even and odd groups
   vector<int>::iterator i = partition(v.begin(), v.end(), isEven);

   // Sort both partitions
   sort(v.begin(), i);
   sort(i, v.end());

   // Copy contents of vector to in memory stream
   ostringstream out;
   ostream_iterator<int> iout(out);
   copy(v.begin(), v.end(), iout);

   // Verify results
   string s = out.str();
   if (s == EXPECTED_RESULT)
      clog << "Test3 PASSED";
   else
      clog << "Test3 FAILED, expected " << EXPECTED_RESULT << ", saw " << s;
   clog << "\n";
}

void
UnitTests::TestAll()
{
   Test1();
   Test2();
   Test3();
}
