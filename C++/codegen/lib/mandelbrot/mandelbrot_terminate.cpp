//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mandelbrot_terminate.cpp
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 25-Feb-2020 16:56:49
//

// Include Files
#include "mandelbrot_terminate.h"
#include "mandelbrot.h"
#include "mandelbrot_data.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : void
// Return Type  : void
//
void mandelbrot_terminate()
{
  omp_destroy_nest_lock(&emlrtNestLockGlobal);
  isInitialized_mandelbrot = false;
}

//
// File trailer for mandelbrot_terminate.cpp
//
// [EOF]
//
