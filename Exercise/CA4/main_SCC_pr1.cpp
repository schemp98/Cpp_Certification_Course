#include "BigInt.h";
#include <iostream>     // std::cout
#include <sstream>      // std::istringstream
#include <string>       // std::string

using namespace Project1;

int main(void)
{
   BigInt temp(340935);
   BigInt temp2(temp);
   string input("-0");
   BigInt temp3(input);
   cout << temp3 << "\n";
   //cout << temp << "\n"
   //   << temp2 << "\n"
   //   << temp3 << "\n";

   //cout << bi1 << "\n"
   //   << bi2 << "\n"
   //   << bi3 << "\n"
   //   << "enter a BigInt you big shot: ";
   //BigInt tempIn;// = bi1 + bi3;
   //cin >> tempIn;
   //cout << "You entered the BigInt:" << tempIn << "\n";
   BigInt left(-4567), right(7678);

   //BigInt bi1("123");
   //BigInt bi2("123");
   //bi1 -= bi2;
   ////ostringstream out;
   //cout << bi1 << "\n";
   BigInt bi1("-899");
   BigInt bi2("-901");
   bi1 -= bi2;
   ostringstream out;/*
   out << bi1;
   CHECK_EQUAL("2", out.str());*/
   //ostringstream out;

   cout << bi1 << " should be 2\n";
}
