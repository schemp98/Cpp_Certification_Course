//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L.Mitchell, Jr., M.S.
// 04 / 01 / 2020
// C1A1E1_main.cpp
// Win10
// Visual C++ 19.0
//
// This file contains the most appropriate form of expressions
//

#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
   int d, o, h;
   //char o = d;
   //char h = d;
   // 1-6
   //d = "16";
   d = 7;
   cout << "in decimal: " << d << " | in octal : " << oct << d
      << " | in hex: " << hex << d << dec << endl;
   d = 8;
   cout << "in decimal: " << d << " | in octal : " << oct << d
      << " | in hex: " << hex << d << dec << endl;
   d = 15;
   cout << "in decimal: " << d << " | in octal : " << oct << d
      << " | in hex: " << hex << d << dec << endl;
   d = 16;
   cout << "in decimal: " << d << " | in octal : " << oct << d
      << " | in hex: " << hex << d << dec << endl;
   d = -1;
   cout << "in decimal: " << d << " | in octal : " << oct << d
      << " | in hex: " << hex << d << dec << endl;
   d = 1024;
   cout << "in decimal: " << d << " | in octal : " << oct << d
      << " | in hex: " << hex << d << dec << endl;

   d = -1024;
   cout << "in decimal: " << d << " | in octal : " << oct << d
      << " | in hex: " << hex << d << dec << endl;

   cout << "\nThis is Problem 1-7\n";
   cout << "Please enter the same number three times: ";
   //cin >> oct;
   cin >> d >> oct >> o >> hex >> h >> dec;

   cout << d << " Oct: " << o << " Hex : " << h << endl;

   return 0;
}
