//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 25-Feb-2020 16:56:49
//

//***********************************************************************
// This automatically generated example C++ main file shows how to call
// entry-point functions that MATLAB Coder generated. You must customize
// this file for your application. Do not modify this file directly.
// Instead, make a copy of this file, modify it, and integrate it into
// your development environment.
//
// This file initializes entry-point function arguments to a default
// size and value before calling the entry-point functions. It does
// not store or use any values returned from the entry-point functions.
// If necessary, it does pre-allocate memory for returned values.
// You can use this file as a starting point for a main function that
// you can deploy in your application.
//
// After you copy the file, and before you deploy it, you must make the
// following changes:
// * For variable-size function arguments, change the example sizes to
// the sizes that your application requires.
// * Change the example values of function arguments to the values that
// your application requires.
// * If the entry-point functions return values, store these values or
// otherwise use them as required by your application.
//
//***********************************************************************

// Include Files
// #include "matplotlibcpp.h"
#include "main.h"
#include "mandelbrot.h"
#include "mandelbrot_emxAPI.h"
#include "mandelbrot_terminate.h"
#include "rt_nonfinite.h"
#include <iostream>
#include <time.h>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

// Function Declarations
static double argInit_real_T();
static void main_mandelbrot();
static void printemx_mat(emxArray_real_T *k);
// Function Definitions

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : void
// Return Type  : void
//
static void main_mandelbrot()
{
  emxArray_real_T *k;
  emxArray_real_T *X;
  emxArray_real_T *Y;
  double N_tmp_tmp;
  emxInitArray_real_T(&k, 2);
  emxInitArray_real_T(&X, 2);
  emxInitArray_real_T(&Y, 2);

  // Initialize function 'mandelbrot' input arguments.
  N_tmp_tmp = argInit_real_T();

  // Call the entry-point 'mandelbrot'.
  //mandelbrot(N_tmp_tmp, N_tmp_tmp, N_tmp_tmp, argInit_real_T(), argInit_real_T(),
//             k, X, Y);
mandelbrot(300, 100, 0,0, 1, k, X, Y);

  // std::cout << k->size[0] << std::endl;
  // std::cout << k->size[1] << std::endl;
// printemx_mat(k);
// QImage image(k->size[0], k->size[1], QImage::Format_RGB32);
// QRgb value;
// for (int i=0;i<k->size[0];++i) {
//     for (int j=0;j<k->size[1];++j) {
//         value = getColor(k->data[j*k->size[0]+i]); //a function that returns color based on value
//         image.setPixel(i, j, value);
//     }
// }
  emxDestroyArray_real_T(Y);
  emxDestroyArray_real_T(X);
  emxDestroyArray_real_T(k);
}

//
// Arguments    : int argc
//                const char * const argv[]
// Return Type  : int
static void trytry()
{
std::cout << "lol start: " << std::endl;

}
//
int main(int, const char * const [])
{
  // The initialize function is being called automatically from your entry-point function. So, a call to initialize is not included here.
  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  std::chrono::high_resolution_clock::time_point t0;
  std::chrono::high_resolution_clock::time_point ti;
  float t1;
  t0= std::chrono::high_resolution_clock::now();
  main_mandelbrot();

  // Terminate the application.
  // You do not need to do this more than one time.
  mandelbrot_terminate();
  // std::this_thread::sleep_for (std::chrono::milliseconds(1000));
  ti= std::chrono::high_resolution_clock::now();
  t1= 1.e-6*std::chrono::duration_cast<std::chrono::microseconds>(ti-t0).count();
  std::cout << "time = " << t1 << std::endl;
  trytry();
  return 0;
}

static void printemx_mat(emxArray_real_T *k)
{
  for(int i=0 ;i<k->size[0];i++){for(int j=0 ;j<k->size[1];j++)
    {
      std::cout << k->data[j*k->size[0]+i] << " ";
    }
  std::cout <<std::endl;
  }
}
//
// File trailer for main.cpp
//
// [EOF]
//
