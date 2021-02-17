/*===========================================================================
 * Homework #3 - CSE40478
 *
 * File:    DigitStrippingSPA.cpp
 * Author:  Ray Mitchell
 * Date:    4/30/2012
 *===========================================================================*/
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

#include "DigitStrippingSPA.h"
#include "StreamProcessorAlgorithm.h"
using namespace RayMitchell::Homework3;

DigitStrippingSPA::DigitStrippingSPA(istream &in, ostream &out)
   : StreamProcessorAlgorithm(in, out)
{}

bool
DigitStrippingSPA::filterToken(const string &token) const
{
   // Only allow tokens containin at least one digit to pass through
   return find_if(token.begin(), token.end(), isdigit) != token.end();
}

void
DigitStrippingSPA::processToken(string &token) const
{
   // Strip out all digits from the tokens that pass through
   token.erase(remove_if(token.begin(), token.end(), isdigit), token.end());
}
