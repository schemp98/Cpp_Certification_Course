//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 08 / 06 / 2020
// C2A5E4_DetectFloats.cpp
// Win10
// Visual C++ 19.0
//
// File contains DetectFloats function, which determines if the string at chPtr
// represents a syntactically legal hexadecimal floating literal, and returns
// its data type
//
#include <iostream>
#include <fstream>
#include "C2A5E4_StatusCode-Driver.h"

using namespace std;

StatusCode DetectFloats(const char *chPtr)
{
   // Define State Variable
   enum States {
      START, PREFIX_START, PREFIX, NO_WHOLE, WHOLE, FRACT, BIN_EXP_START,
      BIN_EXP_SIGN, BIN_EXP, SUFFIX
   } state = START;
   char currChar;

   while ((currChar = *chPtr) != '\0')
   {
      switch (state)
      {
         case START:
            switch (currChar)
            {
               case '0':
                  state = PREFIX_START;
                  break;
            }
            break;

         case PREFIX_START:
            switch (toupper(currChar))
            {
               case 'X':
                  state = PREFIX;
                  break;
            }
            break;
         case PREFIX:
            switch (currChar)
            {
               case '.':
                  state = NO_WHOLE;
                  break;
               case 'F': // HEX-DIGIT
                  state = WHOLE;
                  break;
            }
            break;
         case  NO_WHOLE:

            switch (currChar)
            {
               case 'F': // HEX-DIGIT
                  state = FRACT;
                  break;
               case 'p': // Binary EXP Start
                  state = BIN_EXP_START;
                  break;
               case 'P': // Binary EXP Start
                  state = BIN_EXP_START;
                  break;
            }
            break;
         case  WHOLE:
            switch (currChar)
            {
               case '.':
                  state = FRACT;
                  break;
               case 'F': // HEX-DIGIT
                  state = WHOLE;
                  break;
               case 'p': // Binary EXP Start
                  state = BIN_EXP_START;
                  break;
               case 'P': // Binary EXP Start
                  state = BIN_EXP_START;
                  break;
            }
            break;
         case  FRACT:
            switch (currChar)
            {
               case 'F': // HEX-DIGIT
                  state = FRACT;
                  break;
               case 'p': // Binary EXP Start
                  state = BIN_EXP_START;
                  break;
               case 'P': // Binary EXP Start
                  state = BIN_EXP_START;
                  break;
            }
            break;
         case  BIN_EXP_START:
            switch (currChar)
            {
               case '+': // Binary EXP Start
                  state = BIN_EXP_SIGN;
                  break;
               case '-': // Binary EXP Start
                  state = BIN_EXP_SIGN;
                  break;
               case 'D': // DIGIT
                  state = BIN_EXP;
                  break;
            }
            break;
         case  BIN_EXP_SIGN:
            switch (currChar)
            {
               case 'D': // DIGIT
                  state = BIN_EXP;
                  break;
            }
            break;
         case  BIN_EXP:
            switch (currChar)
            {
               case 'D': // DIGIT
                  state = BIN_EXP;
                  break;

               case '': // double
                  return(TYPE_DOUBLE);
               case 'l': // long double
                  return(TYPE_LDOUBLE);

               case 'L': // long double
                  return(TYPE_LDOUBLE);
               case 'f': // float
                  return(TYPE_FLOAT);

               case 'F': // float
                  return(TYPE_FLOAT);
            }
            break;
      }
   }
   return(NO_MATCH)
}
