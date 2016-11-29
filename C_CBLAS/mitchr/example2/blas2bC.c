/* -*- Mode:C; Coding:us-ascii-unix; fill-column:132 -*- */
/* ******************************************************************************************************************************
 */
/**
   @file      blas2bC.c
   @author    Mitch Richling <https://www.mitchr.me/>
   @Copyright Copyright 1997 by Mitch Richling.  All rights reserved.
   @brief     Demonstrate several cblas (level 1) functions. @EOL
   @Keywords  blas cblas C fortran numerical linear algebra vector matrix gemv
   ger
   @Std       C89

   This is a simple program intended to illustrate how to make use of #gemv and
   #ger blas routines (as implemented in the cblas).

   This is almost precisely the same as example program blas2.c; however, this
   one uses the column major order of Fortran.

*/

/* ------------------------------------------------------------------------------------------------------------------------------
 */

#include "blaio.h"  /* Basic Linear Algebra I/O */
#include <stdio.h>  /* I/O lib         ISOC     */
#include <stdlib.h> /* Standard Lib    ISOC     */

int main(int argc, char **argv) {
  double a[4 * 5] = {1,  6,  11, 16, 2,  7,  12, 17, 3,  8,
                     13, 18, 4,  9,  14, 19, 5,  10, 15, 20};
  double x[5] = {2, 3, 4, 5, 6};
  double y[4];

  printMatrix(CblasColMajor, 4, 5, a, 8, 3, NULL, NULL, NULL, NULL, NULL,
              "              a = ");
  printVector(5, x, 8, 3, NULL, NULL, NULL, "              x = ");

  /* row_order      transform     lenY lenX alpha  a  lda  X  incX  beta  Y,
   * incY */
  cblas_dgemv(CblasColMajor, CblasNoTrans, 4, 5, 1, a, 4, x, 1, 0, y, 1);
  printVector(4, y, 8, 3, NULL, NULL, NULL, "       y<-1.0*a*xT+0.0*y= ");

  /* row_order       lenY lenX alpha  X  incX  Y, incY A  LDA */
  cblas_dger(CblasColMajor, 4, 5, 1, y, 1, x, 1, a, 4);
  printMatrix(CblasColMajor, 4, 5, a, 8, 3, NULL, NULL, NULL, NULL, NULL,
              "a <- 1.0*x.yT+a = ");

  return 0;
} /* end func main*/
