/*===========================================================================
 * Homework #3 - CSE40478
 *
 * File:    UppercasingSPA.cpp
 * Author:  Ray Mitchell
 * Date:    4/30/2012
 *===========================================================================*/
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

#include "UppercasingSPA.h"
#include "StreamProcessorAlgorithm.h"
using namespace RayMitchell::Homework3;

UppercasingSPA::UppercasingSPA(istream &in, ostream &out)
   : StreamProcessorAlgorithm(in, out)
{}

bool
UppercasingSPA::filterToken(const string &token) const
{
   // Allow all tokens to pass through
   return true;
}

void
UppercasingSPA::processToken(string &token) const
{
   // Uppercase all letters in the token
   transform(token.begin(), token.end(), token.begin(), toupper);
}
