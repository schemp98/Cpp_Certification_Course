//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 07 / 27 / 2020
// C2A4E3_pointerArray4D.cpp
// Win10
// Visual C++ 19.0
//
// File containing declaration of a 4 dimensional pointer array
//

// declare array size for each dimension
extern const int DIM0 = 2, DIM1 = 3, DIM2 = 4, DIM3 = 5;

// 4th dimension, we need DIM0*DIM1*DIM2 = 24 arrays of DIM3
static float xa0[DIM3], xb0[DIM3], xc0[DIM3], xd0[DIM3], xe0[DIM3], xf0[DIM3],
xa1[DIM3], xb1[DIM3], xc1[DIM3], xd1[DIM3], xe1[DIM3], xf1[DIM3],
xa2[DIM3], xb2[DIM3], xc2[DIM3], xd2[DIM3], xe2[DIM3], xf2[DIM3],
xa3[DIM3], xb3[DIM3], xc3[DIM3], xd3[DIM3], xe3[DIM3], xf3[DIM3];

// 3rd dimension DIM0*DIM1 = 6 arrays of DIM2
static float *ya0[DIM2] = {xa0, xa1, xa2, xa3},
*yb0[DIM2] = {xb0, xb1, xb2, xb3},
*yc0[DIM2] = {xc0, xc1, xc2, xc3},
*yd0[DIM2] = {xd0, xd1, xd2, xd3},
*ye0[DIM2] = {xe0, xe1, xe2, xe3},
*yf0[DIM2] = {xf0, xf1, xf2, xf3};
// 2nd dimension DIM0 = 2 arrays of DIM1
static float **za[DIM1] = {ya0, yb0, yc0}, **zb[DIM1] = {yd0, ye0, yf0};

// 1st dimension 1 array of DIM0
float ***pointerArray4D[DIM0] = {za, zb};
