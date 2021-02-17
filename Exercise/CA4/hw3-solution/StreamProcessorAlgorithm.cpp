/*===========================================================================
 * Homework #3 - CSE40478
 *
 * File:    StreamProcessorAlgorithm.cpp
 * Author:  Ray Mitchell
 * Date:    4/30/2012
 *===========================================================================*/
#include <iostream>
#include <string>
using namespace std;

#include "StreamProcessorAlgorithm.h"
using namespace RayMitchell::Homework3;

StreamProcessorAlgorithm::StreamProcessorAlgorithm(istream &in, ostream &out)
   : in_(in), out_(out)
{}

StreamProcessorAlgorithm::~StreamProcessorAlgorithm()
{}

void
StreamProcessorAlgorithm::process()
{
   // For each whitespace separated string (token) read from the input stream
   string s;
   while (in_ >> s)
   {
      // If the token passes through the filter
      if (filterToken(s))
      {
         // Process the token and output it to the output stream
         processToken(s);
         out_ << s;
      }
   }
}
