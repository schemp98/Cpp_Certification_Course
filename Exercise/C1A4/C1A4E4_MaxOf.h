//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L. Mitchell Jr.
// 04 / 16 / 2020
// C1A4E4_MaxOf.h
// Win10
// Visual C++ 19.0
//
// Header file containing prototype of C1A4E4 Functions
//

// include guard
#ifndef  C1A4E4_MAXOF_H
#define C1A4E4_MAXOF_H

// Macro that Returns Maximum of 2 Inputs
#define mMaxOf2(in1, in2) ((in1) > (in2) ? (in1) : (in2))
// Macro that Returns Maximum of 3 Inputs
#define mMaxOf3(in1, in2, in3) (mMaxOf2(mMaxOf2((in1), (in2)), (in3)))

// Inline function that Returns Maximum of 2 Inputs
inline long double fMaxOf2(long double in1, long double in2)
{
   return in1 > in2 ? in1 : in2;
}

// Inline function that Returns Maximum of 3 Inputs
inline long double fMaxOf3(long double in1, long double in2, long double in3)
{
   return fMaxOf2(fMaxOf2(in1, in2), in3);
}

#endif
