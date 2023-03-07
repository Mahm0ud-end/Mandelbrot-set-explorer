/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_mandelbrot_mex.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 25-Feb-2020 16:56:49
 */

/* Include Files */
#include "_coder_mandelbrot_mex.h"
#include "_coder_mandelbrot_api.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void mandelbrot_mexFunction(int32_T nlhs, mxArray *plhs[3],
  int32_T nrhs, const mxArray *prhs[5]);

/* Function Definitions */

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[3]
 *                int32_T nrhs
 *                const mxArray *prhs[5]
 * Return Type  : void
 */
void mandelbrot_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs, const
  mxArray *prhs[5])
{
  const mxArray *outputs[3];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 5, 4,
                        10, "mandelbrot");
  }

  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 10,
                        "mandelbrot");
  }

  /* Call the function. */
  mandelbrot_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[]
 *                int32_T nrhs
 *                const mxArray *prhs[]
 * Return Type  : void
 */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(mandelbrot_atexit);

  /* Module initialization. */
  mandelbrot_initialize();

  /* Dispatch the entry-point. */
  mandelbrot_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  mandelbrot_terminate();
}

/*
 * Arguments    : void
 * Return Type  : emlrtCTX
 */
emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/*
 * File trailer for _coder_mandelbrot_mex.c
 *
 * [EOF]
 */
