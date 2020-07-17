//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 07 / 16 / 2020
// C2A2E1_CountBitsM.h
// Win10
// Visual C++ 19.0
//
// Header File contains CountBitsM macro definition
//

#ifndef C2A2E1_COUNTBITSM_H
#define C2A2E1_COUNTBITSM_H

#include <limits.h>

// Macro that determines the bits of storage for the input data type
#define CountBitsM(objectOrType) ((int)sizeof(objectOrType)*CHAR_BIT)

#endif
