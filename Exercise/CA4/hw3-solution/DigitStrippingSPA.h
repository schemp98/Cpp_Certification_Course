/*===========================================================================
 * Homework #3 - CSE40478
 *
 * File:    DigitStrippingSPA.h
 * Author:  Ray Mitchell
 * Date:    4/30/2012
 *===========================================================================*/
#ifndef RAYMITCHELL_HOMEWORK3_DIGITSTRIPPINGSPA_H
#define RAYMITCHELL_HOMEWORK3_DIGITSTRIPPINGSPA_H

#include <iostream>
#include <string>
using namespace std;

#include "StreamProcessorAlgorithm.h"
using RayMitchell::Homework3::StreamProcessorAlgorithm;

namespace RayMitchell { namespace Homework3
{
   class DigitStrippingSPA : public StreamProcessorAlgorithm
   {
   public:
      DigitStrippingSPA(istream &in, ostream &out);

   private:
      bool filterToken(const string &token) const;
      void processToken(string &token) const;
   };
}}

#endif