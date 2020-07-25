//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 07 / 17 / 2020
// C2A1E1_Macros.h
// Win10
// Visual C++ 19.0
//
// File containing 3 marcos
// 1) calculate the product of two numbers
// 2) Negate the input
// 3) determine the number of elements in an array
//

#ifndef C2A1E1_MACROS_H
#define C2A1E1_MACROS_H

// Macro that returns the product of 2 Inputs
#define Product(in1, in2) ((in1) * (in2))
// Macro that negates the input value
#define Negate(in) (-(in))

// Macro that returns the number of elements in an array
#define Elements(in) (sizeof(in)/sizeof((in)[0]))

#endif
