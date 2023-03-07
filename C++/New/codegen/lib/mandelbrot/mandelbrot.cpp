//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mandelbrot.cpp
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 25-Feb-2020 16:56:49
//

// Include Files
#include "mandelbrot.h"
#include "interp1.h"
#include "linspace.h"
#include "mandelbrot_data.h"
#include "mandelbrot_emxutil.h"
#include "mandelbrot_initialize.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Declarations
static double rt_hypotd_snf(double u0, double u1);

// Function Definitions

//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_hypotd_snf(double u0, double u1)
{
  double y;
  double a;
  a = std::abs(u0);
  y = std::abs(u1);
  if (a < y) {
    a /= y;
    y *= std::sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = a * std::sqrt(y * y + 1.0);
  } else {
    if (!rtIsNaN(y)) {
      y = a * 1.4142135623730951;
    }
  }

  return y;
}

//
// c_y= c_y;
// Arguments    : double N
//                double MaxIteration
//                double c_x
//                double c_y
//                double half_range
//                emxArray_real_T *k
//                emxArray_real_T *X
//                emxArray_real_T *Y
// Return Type  : void
//
void mandelbrot(double N, double MaxIteration, double c_x, double c_y, double
                half_range, emxArray_real_T *k, emxArray_real_T *X,
                emxArray_real_T *Y)
{
  emxArray_real_T *x;
  emxArray_real_T *y;
  int nx;
  int ny;
  int i;
  int j;
  emxArray_creal_T *c;
  int b_i;
  emxArray_creal_T *z;
  emxArray_boolean_T *r;
  emxArray_boolean_T *r1;
  emxArray_int32_T *r2;
  emxArray_creal_T *z1;
  int ii;
  emxArray_real_T *minval;
  double ex;
  double a;
  boolean_T exitg1;
  double b;
  double varargin_1[2];
  double b_x[2];
  double b_y[2];
  unsigned int outsize_idx_0;
  unsigned int outsize_idx_1;
  int exitg2;
  if (isInitialized_mandelbrot == false) {
    mandelbrot_initialize();
  }

  emxInit_real_T(&x, 2);
  emxInit_real_T(&y, 2);
  linspace(c_x - half_range, c_x + half_range, N, X);
  linspace(c_y - half_range, c_y + half_range, N, Y);
  nx = X->size[1];
  ny = Y->size[1];
  i = x->size[0] * x->size[1];
  x->size[0] = Y->size[1];
  x->size[1] = X->size[1];
  emxEnsureCapacity_real_T(x, i);
  i = y->size[0] * y->size[1];
  y->size[0] = Y->size[1];
  y->size[1] = X->size[1];
  emxEnsureCapacity_real_T(y, i);
  if ((X->size[1] != 0) && (Y->size[1] != 0)) {
    for (j = 0; j < nx; j++) {
      for (b_i = 0; b_i < ny; b_i++) {
        x->data[b_i + x->size[0] * j] = X->data[j];
        y->data[b_i + y->size[0] * j] = Y->data[b_i];
      }
    }
  }

  emxInit_creal_T(&c, 2);
  i = c->size[0] * c->size[1];
  c->size[0] = x->size[0];
  c->size[1] = x->size[1];
  emxEnsureCapacity_creal_T(c, i);
  ny = x->size[0] * x->size[1];
  for (i = 0; i < ny; i++) {
    c->data[i].re = x->data[i] + 0.0 * y->data[i];
    c->data[i].im = y->data[i];
  }

  emxInit_creal_T(&z, 2);
  i = c->size[0];
  b_i = z->size[0] * z->size[1];
  z->size[0] = i;
  ny = c->size[1];
  z->size[1] = ny;
  emxEnsureCapacity_creal_T(z, b_i);
  ny *= i;
  for (i = 0; i < ny; i++) {
    z->data[i].re = 0.0;
    z->data[i].im = 0.0;
  }

  i = c->size[0];
  b_i = k->size[0] * k->size[1];
  k->size[0] = i;
  ny = c->size[1];
  k->size[1] = ny;
  emxEnsureCapacity_real_T(k, b_i);
  ny *= i;
  for (i = 0; i < ny; i++) {
    k->data[i] = 0.0;
  }

  i = static_cast<int>(MaxIteration);
  emxInit_boolean_T(&r, 2);
  emxInit_boolean_T(&r1, 2);
  emxInit_int32_T(&r2, 1);
  emxInit_creal_T(&z1, 2);
  for (ii = 0; ii < i; ii++) {
    b_i = z->size[0];
    ny = z1->size[0] * z1->size[1];
    z1->size[0] = b_i;
    j = z->size[1];
    z1->size[1] = j;
    emxEnsureCapacity_creal_T(z1, ny);
    nx = b_i * j;
    for (j = 0; j < nx; j++) {
      z1->data[j].re = z->data[j].re * z->data[j].re - z->data[j].im * z->data[j]
        .im;
      z1->data[j].im = z->data[j].re * z->data[j].im + z->data[j].im * z->data[j]
        .re;
    }

    b_i = z->size[0] * z->size[1];
    z->size[0] = z1->size[0];
    z->size[1] = z1->size[1];
    emxEnsureCapacity_creal_T(z, b_i);
    ny = z1->size[0] * z1->size[1];
    for (b_i = 0; b_i < ny; b_i++) {
      z->data[b_i].re = z1->data[b_i].re + c->data[b_i].re;
      z->data[b_i].im = z1->data[b_i].im + c->data[b_i].im;
    }

    nx = z->size[0] * z->size[1];
    b_i = y->size[0] * y->size[1];
    y->size[0] = z->size[0];
    y->size[1] = z->size[1];
    emxEnsureCapacity_real_T(y, b_i);
    for (j = 0; j < nx; j++) {
      y->data[j] = rt_hypotd_snf(z->data[j].re, z->data[j].im);
    }

    b_i = r->size[0] * r->size[1];
    r->size[0] = y->size[0];
    r->size[1] = y->size[1];
    emxEnsureCapacity_boolean_T(r, b_i);
    ny = y->size[0] * y->size[1];
    for (b_i = 0; b_i < ny; b_i++) {
      r->data[b_i] = (y->data[b_i] > 2.0);
    }

    b_i = r1->size[0] * r1->size[1];
    r1->size[0] = k->size[0];
    r1->size[1] = k->size[1];
    emxEnsureCapacity_boolean_T(r1, b_i);
    ny = k->size[0] * k->size[1];
    for (b_i = 0; b_i < ny; b_i++) {
      r1->data[b_i] = (k->data[b_i] == 0.0);
    }

    j = r->size[0] * r->size[1] - 1;
    ny = 0;
    for (b_i = 0; b_i <= j; b_i++) {
      if (r->data[b_i] && r1->data[b_i]) {
        ny++;
      }
    }

    b_i = r2->size[0];
    r2->size[0] = ny;
    emxEnsureCapacity_int32_T(r2, b_i);
    ny = 0;
    for (b_i = 0; b_i <= j; b_i++) {
      if (r->data[b_i] && r1->data[b_i]) {
        r2->data[ny] = b_i + 1;
        ny++;
      }
    }

    ny = r2->size[0] - 1;
    for (b_i = 0; b_i <= ny; b_i++) {
      k->data[r2->data[b_i] - 1] = MaxIteration - (static_cast<double>(ii) + 1.0);
    }
  }

  emxFree_creal_T(&z1);
  emxFree_int32_T(&r2);
  emxFree_boolean_T(&r1);
  emxFree_boolean_T(&r);
  emxFree_real_T(&y);
  emxFree_creal_T(&z);
  emxFree_creal_T(&c);
  emxInit_real_T(&minval, 2);

  //      k(abs(z) > 2 & k == 0) = 1;
  ny = k->size[0];
  nx = k->size[1];
  i = minval->size[0] * minval->size[1];
  minval->size[0] = 1;
  minval->size[1] = k->size[1];
  emxEnsureCapacity_real_T(minval, i);
  if (k->size[1] >= 1) {
    for (j = 0; j < nx; j++) {
      minval->data[j] = k->data[k->size[0] * j];
      for (b_i = 2; b_i <= ny; b_i++) {
        a = minval->data[j];
        b = k->data[(b_i + k->size[0] * j) - 1];
        if ((!rtIsNaN(b)) && (rtIsNaN(a) || (a > b))) {
          minval->data[j] = b;
        }
      }
    }
  }

  nx = minval->size[1];
  if (minval->size[1] <= 2) {
    if (minval->size[1] == 1) {
      ex = minval->data[0];
    } else if ((minval->data[0] > minval->data[1]) || (rtIsNaN(minval->data[0]) &&
                (!rtIsNaN(minval->data[1])))) {
      ex = minval->data[1];
    } else {
      ex = minval->data[0];
    }
  } else {
    if (!rtIsNaN(minval->data[0])) {
      ny = 1;
    } else {
      ny = 0;
      j = 2;
      exitg1 = false;
      while ((!exitg1) && (j <= minval->size[1])) {
        if (!rtIsNaN(minval->data[j - 1])) {
          ny = j;
          exitg1 = true;
        } else {
          j++;
        }
      }
    }

    if (ny == 0) {
      ex = minval->data[0];
    } else {
      ex = minval->data[ny - 1];
      i = ny + 1;
      for (j = i; j <= nx; j++) {
        a = minval->data[j - 1];
        if (ex > a) {
          ex = a;
        }
      }
    }
  }

  ny = k->size[0];
  nx = k->size[1];
  i = minval->size[0] * minval->size[1];
  minval->size[0] = 1;
  minval->size[1] = k->size[1];
  emxEnsureCapacity_real_T(minval, i);
  if (k->size[1] >= 1) {
    for (j = 0; j < nx; j++) {
      minval->data[j] = k->data[k->size[0] * j];
      for (b_i = 2; b_i <= ny; b_i++) {
        a = minval->data[j];
        b = k->data[(b_i + k->size[0] * j) - 1];
        if ((!rtIsNaN(b)) && (rtIsNaN(a) || (a < b))) {
          minval->data[j] = b;
        }
      }
    }
  }

  nx = minval->size[1];
  if (minval->size[1] <= 2) {
    if (minval->size[1] == 1) {
      b = minval->data[0];
    } else if ((minval->data[0] < minval->data[1]) || (rtIsNaN(minval->data[0]) &&
                (!rtIsNaN(minval->data[1])))) {
      b = minval->data[1];
    } else {
      b = minval->data[0];
    }
  } else {
    if (!rtIsNaN(minval->data[0])) {
      ny = 1;
    } else {
      ny = 0;
      j = 2;
      exitg1 = false;
      while ((!exitg1) && (j <= minval->size[1])) {
        if (!rtIsNaN(minval->data[j - 1])) {
          ny = j;
          exitg1 = true;
        } else {
          j++;
        }
      }
    }

    if (ny == 0) {
      b = minval->data[0];
    } else {
      b = minval->data[ny - 1];
      i = ny + 1;
      for (j = i; j <= nx; j++) {
        a = minval->data[j - 1];
        if (b < a) {
          b = a;
        }
      }
    }
  }

  emxFree_real_T(&minval);
  varargin_1[0] = ex;
  varargin_1[1] = b;
  i = x->size[0] * x->size[1];
  x->size[0] = k->size[0];
  x->size[1] = k->size[1];
  emxEnsureCapacity_real_T(x, i);
  ny = k->size[0] * k->size[1];
  for (i = 0; i < ny; i++) {
    x->data[i] = k->data[i];
  }

  b_x[0] = ex;
  b_y[0] = 0.0;
  outsize_idx_0 = static_cast<unsigned int>(k->size[0]);
  b_x[1] = b;
  b_y[1] = 255.0;
  outsize_idx_1 = static_cast<unsigned int>(k->size[1]);
  i = k->size[0] * k->size[1];
  k->size[0] = static_cast<int>(outsize_idx_0);
  k->size[1] = static_cast<int>(outsize_idx_1);
  emxEnsureCapacity_real_T(k, i);
  ny = static_cast<int>(outsize_idx_0) * static_cast<int>(outsize_idx_1);
  for (i = 0; i < ny; i++) {
    k->data[i] = rtNaN;
  }

  if ((x->size[0] != 0) && (x->size[1] != 0)) {
    j = 0;
    do {
      exitg2 = 0;
      if (j < 2) {
        if (rtIsNaN(varargin_1[j])) {
          exitg2 = 1;
        } else {
          j++;
        }
      } else {
        if (b < ex) {
          b_x[0] = b;
          b_x[1] = ex;
          b_y[0] = 255.0;
          b_y[1] = 0.0;
        }

        interp1Linear(b_y, x, k, b_x);
        exitg2 = 1;
      }
    } while (exitg2 == 0);
  }

  emxFree_real_T(&x);

  //      if nargin==5
  //          imagesc(X,Y,k);
  //          colormap hot
  //          axis square
  //      elseif nargin==6
  //  %         axes(ax);
  //          imagesc(ax,X,Y,k);
  //          axis(ax,'square');
  //          colormap(ax,'hot');
  //          xlim(ax,[X(1) X(end)]);
  //          ylim(ax,[Y(1) Y(end)]);
  //      end
}

//
// File trailer for mandelbrot.cpp
//
// [EOF]
//
