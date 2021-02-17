/*===========================================================================
 * Homework #3 - CSE40478
 *
 * File:    UppercasingSPA.h
 * Author:  Ray Mitchell
 * Date:    4/30/2012
 *===========================================================================*/
#ifndef RAYMITCHELL_HOMEWORK3_UPPERCASINGSPA_H
#define RAYMITCHELL_HOMEWORK3_UPPERCASINGSPA_H

#include <iostream>
#include <string>
using namespace std;

#include "StreamProcessorAlgorithm.h"
using RayMitchell::Homework3::StreamProcessorAlgorithm;

namespace RayMitchell { namespace Homework3
{
   class UppercasingSPA : public StreamProcessorAlgorithm
   {
   public:
      UppercasingSPA(istream &in, ostream &out);

   private:
      bool filterToken(const string &token) const;
      void processToken(string &token) const;
   };
}}

#endif