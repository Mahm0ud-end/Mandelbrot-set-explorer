//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mandelbrot_emxutil.h
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 25-Feb-2020 16:56:49
//
#ifndef MANDELBROT_EMXUTIL_H
#define MANDELBROT_EMXUTIL_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "mandelbrot_types.h"

// Function Declarations
extern void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray, int
  oldNumel);
extern void emxEnsureCapacity_creal_T(emxArray_creal_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);
extern void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);
extern void emxFree_creal_T(emxArray_creal_T **pEmxArray);
extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int numDimensions);
extern void emxInit_creal_T(emxArray_creal_T **pEmxArray, int numDimensions);
extern void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#endif

//
// File trailer for mandelbrot_emxutil.h
//
// [EOF]
//
