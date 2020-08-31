//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 08 / 31 / 2020
// C2A8E2_DisplayModifiedSingleReals.c
// Win10
// Visual C++ 19.0
//
// File contains DisplayModifiedSingleReals and the EvalSingleModReal functions,
// EvalSingleModReal takes in an unsigned long length bit pattern, determines
//          the modified single real value and how it is represented
// DisplayModifiedSingleReals takes a pointer to FILE structure representing
//       an open readable binary file, and displays the original hex pattern,
//       the Modified Single Real and its data representation in a table, this
//       is done by calling the EvalSingleModReal function
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F_NORM    1
#define F_DENORM  2
#define F_PZERO   3
#define F_NZERO   (-F_PZERO)
#define F_PINF    4
#define F_NINF    (-F_PINF)
#define F_PNAN    5
#define F_NNAN    (-F_PNAN)

#define SIGN_MASK 0x80000000uL
#define EXP_MASK  0x7FC00000uL
#define FRAC_MASK 0x003FFFFFuL
#define FRAC_BITS 22
#define EXP_NBIAS 255
#define EXP_DBIAS 254
#define EXP_MAX   511

#define BUFSIZE 4
#define BASE    2.0

static int EvalSingleModReal(unsigned long pattern, double *result);

void DisplayModifiedSingleReals(FILE *inFile)
{
   unsigned char buf[BUFSIZE];

   while (fread(buf, sizeof(unsigned char), BUFSIZE, inFile))
   {
      unsigned long pattern = 0;
      int status;
      double result;
      char *formatType;
      char *signDisp;

      // Display warning and break when file ends unexpectedly, i.e. we have
      // read in less than BUFSIZE elements before reaching EOF
      if (feof(inFile))
      {
         printf("Unexpected EOF\n");
         break;
      }

      // print original hex value
      printf("0x");
      for (int byteIx = 0, shiftIx = BUFSIZE - 1; byteIx < BUFSIZE;
         ++byteIx, --shiftIx)
      {
         // print the individual bits from the file
         printf("%02x", buf[byteIx]);
         // bit shifting to place file contents in BIG ENDIAN format
         pattern |= buf[byteIx] << (CHAR_BIT * shiftIx);
      }

      //determines the modified single real value and how it is represented
      status = EvalSingleModReal(pattern, &result);

      // Determine Sign to be displayed to user
      if (status > 0)
         signDisp = "+";
      else
         signDisp = "-";

      // Set Display message to indicate representation
      switch (abs(status))
      {
         case F_NORM:
            formatType = "Normal";
            break;
         case F_DENORM:
            formatType = "Denormal";
            break;
         case F_PZERO:
            formatType = "Zero";
            break;
         case F_PINF:
            formatType = "INF";
            break;
         case F_PNAN:
            formatType = "NAN";
            break;
         default:
            formatType = "ERROR";
      }

      // If the representation was Normal, Denormal or Zero, we must check
      // the sign of result to determine if it is positive or negative
      if (abs(status) <= F_PZERO)
      {
         // Because Negative result will already display minus sign
         // we can merely "empty" the signDisp string
         if (result < 0)
            signDisp = "";

         printf(" %s%e  %s\n", signDisp, result, formatType);
      }
      //  representation is INF or NAN
      else
         printf(" %s%s\n", signDisp, formatType);
   }
}

static int EvalSingleModReal(unsigned long pattern, double *result)
{
   int signIsNegative = !!(SIGN_MASK & pattern);      // True if negative value
   int exponent = (EXP_MASK & pattern) >> FRAC_BITS;  // value of exponent field
   long fraction = FRAC_MASK & pattern;               //value of fraction field
   int status;

   if (exponent == 0 && fraction == 0)                // Test sign of Zeros
   {
      status = signIsNegative ? F_NZERO : F_PZERO;
      *result = 0.;                                   // computed value
   }
   else if (exponent == EXP_MAX && fraction == 0)     // Test sign of infinities
      status = signIsNegative ? F_NINF : F_PINF;
   else if (exponent == EXP_MAX && fraction != 0)     // Test sign of infinities
      status = signIsNegative ? F_NNAN : F_PNAN;
   else                                               // Normalized/Denormalized
   {
      int bias;
      *result = fraction * pow(BASE, -FRAC_BITS);     // Find fractional value

      if (exponent != 0)                              // Normalized Number
      {
         bias = EXP_NBIAS;
         status = F_NORM;
         ++*result;                                   // Add implicit 1 int part
      }
      else                                            // Denormalized Number
      {
         bias = EXP_DBIAS;
         status = F_DENORM;
      }
      *result *= pow(BASE, exponent - bias);          // Mantissa *= base^exp

      if (signIsNegative)
         *result = -*result;                          // Negate Result if Neg
   }
   return(status);
}
