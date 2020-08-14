//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 08 / 10 / 2020
// C2A5E4_DetectFloats.cpp
// Win10
// Visual C++ 19.0
//
// File contains DetectFloats function, which determines if the string at chPtr
// represents a syntactically legal hexadecimal floating literal, and returns
// its data type,  This is architected via a state machine
//

#include <fstream>
#include "C2A5E4_StatusCode-Driver.h"

using namespace std;

StatusCode DetectFloats(const char *chPtr)
{
   // Define State Variable
   enum States
   {
      START, PREFIX_START, PREFIX, NO_WHOLE, WHOLE, FRACT, BIN_EXP_START,
      BIN_EXP_SIGN, BIN_EXP, FLOAT, LONG
   } state = START;

   do
   {
      // Enter Current State
      switch (state)
      {
         case START:
            switch (*chPtr++)
            {
               case '0':
                  state = PREFIX_START;
                  break;

               default:
                  return(NO_MATCH);
            }
            break;

         case PREFIX_START:
            switch (*chPtr++)
            {
               case 'X': case 'x':
                  state = PREFIX;
                  break;

               default:
                  return(NO_MATCH);
            }
            break;

         case PREFIX:
            switch (*chPtr++)
            {
               // HEX DIGIT
               case '0': case '1': case '2':case '3': case '4': case '5':
               case '6': case '7': case '8':case '9': case 'A': case 'B':
               case 'C': case 'D': case 'E':case 'F':case 'a': case 'b':
               case 'c': case 'd': case 'e':case 'f':
                  state = WHOLE;
                  break;

               case '.':
                  state = NO_WHOLE;
                  break;

               default:
                  return(NO_MATCH);
            }
            break;

         case  NO_WHOLE:
            switch (*chPtr++)
            {
               // HEX DIGIT
               case '0': case '1': case '2':case '3': case '4': case '5':
               case '6': case '7': case '8':case '9': case 'A': case 'B':
               case 'C': case 'D': case 'E':case 'F':case 'a': case 'b':
               case 'c': case 'd': case 'e':case 'f':
                  state = FRACT;
                  break;

               case 'P':case 'p':
                  state = BIN_EXP_START;
                  break;

               default:
                  return(NO_MATCH);
            }
            break;

         case  WHOLE:
            switch (*chPtr++)
            {
               // HEX DIGIT
               case '0': case '1': case '2':case '3': case '4': case '5':
               case '6': case '7': case '8':case '9': case 'A': case 'B':
               case 'C': case 'D': case 'E':case 'F':case 'a': case 'b':
               case 'c': case 'd': case 'e':case 'f':
                  state = WHOLE;
                  break;

               case '.':
                  state = FRACT;
                  break;

               case 'P':case 'p':
                  state = BIN_EXP_START;
                  break;

               default:
                  return(NO_MATCH);
            }
            break;

         case  FRACT:
            switch (*chPtr++)
            {
               // HEX DIGIT
               case '0': case '1': case '2':case '3': case '4': case '5':
               case '6': case '7': case '8':case '9': case 'A': case 'B':
               case 'C': case 'D': case 'E':case 'F':case 'a': case 'b':
               case 'c': case 'd': case 'e':case 'f':
                  state = FRACT;
                  break;

               case 'P':case 'p':
                  state = BIN_EXP_START;
                  break;

               default:
                  return(NO_MATCH);
            }
            break;

         case  BIN_EXP_START:
            switch (*chPtr++)
            {
               // DIGIT
               case '0': case '1': case '2':case '3': case '4': case '5':
               case '6': case '7': case '8':case '9':
                  state = BIN_EXP;
                  break;

               case '+': case '-':
                  state = BIN_EXP_SIGN;
                  break;

               default:
                  return(NO_MATCH);
            }
            break;

         case  BIN_EXP_SIGN:
            switch (*chPtr++)
            {
               // DIGIT
               case '0': case '1': case '2':case '3': case '4': case '5':
               case '6': case '7': case '8':case '9':
                  state = BIN_EXP;
                  break;

               default:
                  return(NO_MATCH);
            }
            break;

         case  BIN_EXP:
            switch (*chPtr++)
            {
               // DIGIT
               case '0': case '1': case '2':case '3': case '4': case '5':
               case '6': case '7': case '8':case '9':
                  state = BIN_EXP;
                  break;

               case '\0':
                  return(TYPE_DOUBLE);

               case 'L':case 'l':
                  state = LONG;
                  break;

               case 'F':case 'f':
                  state = FLOAT;
                  break;

               default:
                  return(NO_MATCH);
            }
            break;

         case FLOAT:
            switch (*chPtr++)
            {
               case '\0':
                  return(TYPE_FLOAT);

               default:
                  return(NO_MATCH);
            }

         case LONG:
            switch (*chPtr++)
            {
               case '\0':
                  return(TYPE_LDOUBLE);

               default:
                  return(NO_MATCH);
            }
      }
   } while (chPtr);

   // Unexpected condition
   return(NO_MATCH);
}
