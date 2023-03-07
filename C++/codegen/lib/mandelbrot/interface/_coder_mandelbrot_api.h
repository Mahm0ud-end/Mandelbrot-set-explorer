/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_mandelbrot_api.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 25-Feb-2020 16:56:49
 */

#ifndef _CODER_MANDELBROT_API_H
#define _CODER_MANDELBROT_API_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void mandelbrot(real_T N, real_T MaxIteration, real_T c_x, real_T c_y,
  real_T half_range, emxArray_real_T *k, emxArray_real_T *X, emxArray_real_T *Y);
extern void mandelbrot_api(const mxArray * const prhs[5], int32_T nlhs, const
  mxArray *plhs[3]);
extern void mandelbrot_atexit(void);
extern void mandelbrot_initialize(void);
extern void mandelbrot_terminate(void);
extern void mandelbrot_xil_shutdown(void);
extern void mandelbrot_xil_terminate(void);

#endif

/*
 * File trailer for _coder_mandelbrot_api.h
 *
 * [EOF]
 */
