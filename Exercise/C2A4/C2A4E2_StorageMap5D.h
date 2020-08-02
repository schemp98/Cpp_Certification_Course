//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 07 / 27 / 2020
// C2A4E2_StorageMap5D.h
// Win10
// Visual C++ 19.0
//
// Header File containing macro for the storage map equation of a 5-d array
//

#ifndef C2A4E2_STORAGEMAP5D_H
#define C2A4E2_STORAGEMAP5D_H

// The storage map equation for a 5 dimensional array
#define StorageMap5D(ptr, idx0, idx1, idx2, idx3, idx4, dim1, dim2, dim3, dim4)\
(*((ptr) + (idx0)*(dim1)*(dim2)*(dim3)*(dim4)\
        + (idx1)*(dim2)*(dim3)*(dim4)\
        + (idx2)*(dim3)*(dim4)\
        + (idx3)*(dim4)\
        + (idx4)))

#endif
