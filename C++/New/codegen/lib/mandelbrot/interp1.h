//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: interp1.h
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 25-Feb-2020 16:56:49
//
#ifndef INTERP1_H
#define INTERP1_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "mandelbrot_types.h"

// Function Declarations
extern void interp1Linear(const double y[2], const emxArray_real_T *xi,
  emxArray_real_T *yi, const double varargin_1[2]);

#endif

//
// File trailer for interp1.h
//
// [EOF]
//
