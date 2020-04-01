//
// Shaun Chemplavil U08713628
// schemp98@hotmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L.Mitchell, Jr., M.S.
// 04 / 01 / 2020
// C1A1E1_Main.cpp
// Win10
// Visual C++ 15.0
// This file contains the most appropriate form of expressions

#include <iostream>
using namespace std;

int main()
{
   cout << "\"ax = ax + bx\"  should be  \"ax += bx\"\n"
           "\"ax = ax / -bx\" should be  \"ax /= -bx\"\n"
           "\"ax = bx / ax\"  should be  \"ax = bx / ax\"\n"  // Already in most appropriate form
           "\"ax = -1 * ax\"  should be  \"ax = -ax\"\n"
           "\"ax = -ax * ax\" should be  \"ax *= -ax\"\n"
           "\"ax = -bx * ax\" should be  \"ax *= -bx\"\n"
           "\"ax = bx - ax\"  should be  \"ax = bx - ax\"\n"  // Already in most appropriate form
           "\"ax = 2 + ax\"   should be  \"ax += 2\"\n"
           "\"ax = 1 + ax\"   should be  \"ax++\"\n"          // Alternate form "++ax"
           "\"ax = ax - 37\"  should be  \"ax -= 37\"\n"
           "\"ax = ax - 1\"   should be  \"ax--\"\n"          // Alternate form "--ax"
           "\"ax *= -1\"      should be  \"ax = -ax\"\n"
           "\"ax /= -1\"      should be  \"ax = -ax\"\n"
           "\"ax = 0 - ax\"   should be  \"ax = -ax\"" << endl;
   return 0;
}