/*===========================================================================
 * Homework #3 - CSE40478
 *
 * File:    StreamProcessorAlgorithm.h
 * Author:  Ray Mitchell
 * Date:    4/30/2012
 *===========================================================================*/
#ifndef RAYMITCHELL_HOMEWORK3_STREAMPROCESSORALGORITHM_H
#define RAYMITCHELL_HOMEWORK3_STREAMPROCESSORALGORITHM_H

#include <iostream>
#include <string>
using namespace std;

namespace RayMitchell { namespace Homework3
{
   class StreamProcessorAlgorithm
   {
   public:
      StreamProcessorAlgorithm(istream &in, ostream &out);
      virtual ~StreamProcessorAlgorithm();
      void process();

   private:
      virtual bool filterToken(const string &token) const = 0;
      virtual void processToken(string &token) const = 0;

      istream &in_;
      ostream &out_;
   };
}}

#endif