//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 08 / 22 / 2020
// C2A7E4_ProcessStructures.c
// Win10
// Visual C++ 19.0
//
// File contains the functions ReverseMembersEndian, ReadStructures, and
// WriteStructures
//   ReverseMembersEndian: reverses each member of the Test structure passed to
//                         it
//   ReadStructures:  Reads a Test Structure within a temporary file and stores
//                      it at the pointer location passed to it
//   WriteStructures:  Writes a Test Structure to a temporary file and stores
//                      from the pointer location passed to it
// 1. Were the results you got correct for your implementation? Yes
// 2. How many padding bytes were in your structure ?  8 padding bytes
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "C2A7E4_Test-Driver.h"

void *ReverseEndian(void *ptr, size_t size);

struct Test *ReverseMembersEndian(struct Test *ptr)
{
   // Reverse Endian of each structure member individually
   ReverseEndian((void *)&ptr->flt, sizeof(ptr->flt));
   ReverseEndian((void *)&ptr->dbl, sizeof(ptr->dbl));
   ReverseEndian(&ptr->vp, sizeof(ptr->vp));

   return(ptr);
}

struct Test *ReadStructures(struct Test *ptr, size_t count, FILE *fp)
{
   // Read 'count' Test structures from contiguous memory within temporary file
   if (fread(ptr, sizeof(*ptr) * count, 1, fp) != 1)
   {
      fprintf(stderr, "Failed to read structures from temporary file\n");
      exit(EXIT_FAILURE);
   }

   return(ptr);
}

struct Test *WriteStructures(const struct Test *ptr, size_t count, FILE *fp)
{
   // Write 'count' Test structures in contiguous memory within temporary file
   if (fwrite(ptr, sizeof(*ptr) * count, 1, fp) != 1)
   {
      fprintf(stderr, "Failed to write structures to temporary file\n");
      exit(EXIT_FAILURE);
   }

   return((struct Test *)ptr);
}
