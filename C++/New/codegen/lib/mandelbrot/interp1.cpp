//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: interp1.cpp
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 25-Feb-2020 16:56:49
//

// Include Files
#include "interp1.h"
#include "mandelbrot.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : const double y[2]
//                const emxArray_real_T *xi
//                emxArray_real_T *yi
//                const double varargin_1[2]
// Return Type  : void
//
void interp1Linear(const double y[2], const emxArray_real_T *xi, emxArray_real_T
                   *yi, const double varargin_1[2])
{
  double minx;
  double maxx;
  int ub_loop;
  int k;
  int b_k;
  double r;
  minx = varargin_1[0];
  maxx = varargin_1[1];
  ub_loop = xi->size[0] * xi->size[1] - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(b_k,r)

  for (k = 0; k <= ub_loop; k++) {
    b_k = k + 1;
    if (rtIsNaN(xi->data[b_k - 1])) {
      yi->data[b_k - 1] = rtNaN;
    } else {
      if ((!(xi->data[b_k - 1] > maxx)) && (!(xi->data[b_k - 1] < minx))) {
        r = (xi->data[b_k - 1] - varargin_1[0]) / (varargin_1[1] - varargin_1[0]);
        if (r == 0.0) {
          yi->data[b_k - 1] = y[0];
        } else if (r == 1.0) {
          yi->data[b_k - 1] = y[1];
        } else if (y[0] == y[1]) {
          yi->data[b_k - 1] = y[0];
        } else {
          yi->data[b_k - 1] = (1.0 - r) * y[0] + r * y[1];
        }
      }
    }
  }
}

//
// File trailer for interp1.cpp
//
// [EOF]
//
