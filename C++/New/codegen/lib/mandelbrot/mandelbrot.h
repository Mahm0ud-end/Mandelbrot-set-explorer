//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mandelbrot.h
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 25-Feb-2020 16:56:49
//
#ifndef MANDELBROT_H
#define MANDELBROT_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "mandelbrot_types.h"

// Function Declarations
extern void mandelbrot(double N, double MaxIteration, double c_x, double c_y,
  double half_range, emxArray_real_T *k, emxArray_real_T *X, emxArray_real_T *Y);

#endif

//
// File trailer for mandelbrot.h
//
// [EOF]
//
