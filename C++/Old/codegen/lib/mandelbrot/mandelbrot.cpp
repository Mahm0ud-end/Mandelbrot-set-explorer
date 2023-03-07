//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mandelbrot.cpp
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 25-Feb-2020 01:32:19
//

// Include Files
#include "mandelbrot.h"
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
  unsigned int unnamed_idx_0;
  unsigned int unnamed_idx_1;
  emxArray_boolean_T *r;
  emxArray_boolean_T *r1;
  emxArray_int32_T *r2;
  emxArray_creal_T *z1;
  int ii;
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
  j = x->size[0] * x->size[1];
  for (i = 0; i < j; i++) {
    c->data[i].re = x->data[i] + 0.0 * y->data[i];
    c->data[i].im = y->data[i];
  }

  emxFree_real_T(&x);
  emxInit_creal_T(&z, 2);
  unnamed_idx_0 = static_cast<unsigned int>(c->size[0]);
  unnamed_idx_1 = static_cast<unsigned int>(c->size[1]);
  i = z->size[0] * z->size[1];
  z->size[0] = static_cast<int>(unnamed_idx_0);
  z->size[1] = static_cast<int>(unnamed_idx_1);
  emxEnsureCapacity_creal_T(z, i);
  j = static_cast<int>(unnamed_idx_0) * static_cast<int>(unnamed_idx_1);
  for (i = 0; i < j; i++) {
    z->data[i].re = 0.0;
    z->data[i].im = 0.0;
  }

  unnamed_idx_0 = static_cast<unsigned int>(c->size[0]);
  unnamed_idx_1 = static_cast<unsigned int>(c->size[1]);
  i = k->size[0] * k->size[1];
  k->size[0] = static_cast<int>(unnamed_idx_0);
  k->size[1] = static_cast<int>(unnamed_idx_1);
  emxEnsureCapacity_real_T(k, i);
  j = static_cast<int>(unnamed_idx_0) * static_cast<int>(unnamed_idx_1);
  for (i = 0; i < j; i++) {
    k->data[i] = 0.0;
  }

  i = static_cast<int>(MaxIteration);
  emxInit_boolean_T(&r, 2);
  emxInit_boolean_T(&r1, 2);
  emxInit_int32_T(&r2, 1);
  emxInit_creal_T(&z1, 2);
  for (ii = 0; ii < i; ii++) {
    unnamed_idx_0 = static_cast<unsigned int>(z->size[0]);
    unnamed_idx_1 = static_cast<unsigned int>(z->size[1]);
    ny = z1->size[0] * z1->size[1];
    z1->size[0] = static_cast<int>(unnamed_idx_0);
    z1->size[1] = static_cast<int>(unnamed_idx_1);
    emxEnsureCapacity_creal_T(z1, ny);
    nx = static_cast<int>(unnamed_idx_0) * static_cast<int>(unnamed_idx_1);
    for (j = 0; j < nx; j++) {
      z1->data[j].re = z->data[j].re * z->data[j].re - z->data[j].im * z->data[j]
        .im;
      z1->data[j].im = z->data[j].re * z->data[j].im + z->data[j].im * z->data[j]
        .re;
    }

    ny = z->size[0] * z->size[1];
    z->size[0] = z1->size[0];
    z->size[1] = z1->size[1];
    emxEnsureCapacity_creal_T(z, ny);
    j = z1->size[0] * z1->size[1];
    for (ny = 0; ny < j; ny++) {
      z->data[ny].re = z1->data[ny].re + c->data[ny].re;
      z->data[ny].im = z1->data[ny].im + c->data[ny].im;
    }

    nx = z->size[0] * z->size[1];
    ny = y->size[0] * y->size[1];
    y->size[0] = z->size[0];
    y->size[1] = z->size[1];
    emxEnsureCapacity_real_T(y, ny);
    for (j = 0; j < nx; j++) {
      y->data[j] = rt_hypotd_snf(z->data[j].re, z->data[j].im);
    }

    ny = r->size[0] * r->size[1];
    r->size[0] = y->size[0];
    r->size[1] = y->size[1];
    emxEnsureCapacity_boolean_T(r, ny);
    j = y->size[0] * y->size[1];
    for (ny = 0; ny < j; ny++) {
      r->data[ny] = (y->data[ny] > 2.0);
    }

    ny = r1->size[0] * r1->size[1];
    r1->size[0] = k->size[0];
    r1->size[1] = k->size[1];
    emxEnsureCapacity_boolean_T(r1, ny);
    j = k->size[0] * k->size[1];
    for (ny = 0; ny < j; ny++) {
      r1->data[ny] = (k->data[ny] == 0.0);
    }

    nx = r->size[0] * r->size[1] - 1;
    j = 0;
    for (b_i = 0; b_i <= nx; b_i++) {
      if (r->data[b_i] && r1->data[b_i]) {
        j++;
      }
    }

    ny = r2->size[0];
    r2->size[0] = j;
    emxEnsureCapacity_int32_T(r2, ny);
    j = 0;
    for (b_i = 0; b_i <= nx; b_i++) {
      if (r->data[b_i] && r1->data[b_i]) {
        r2->data[j] = b_i + 1;
        j++;
      }
    }

    j = r2->size[0] - 1;
    for (ny = 0; ny <= j; ny++) {
      k->data[r2->data[ny] - 1] = MaxIteration - (static_cast<double>(ii) + 1.0);
    }
  }

  emxFree_creal_T(&z1);
  emxFree_int32_T(&r2);
  emxFree_boolean_T(&r1);
  emxFree_boolean_T(&r);
  emxFree_real_T(&y);
  emxFree_creal_T(&z);
  emxFree_creal_T(&c);

  //      k(abs(z) > 2 & k == 0) = 1;
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
