/* -*- Mode:C; Coding:us-ascii-unix; fill-column:132 -*- */
/* ******************************************************************************************************************************
 */
/**
   @file      blas3C.c
   @author    Mitch Richling <https://www.mitchr.me/>
   @Copyright Copyright 1997 by Mitch Richling.  All rights reserved.
   @brief     Demonstrate several cblas (level 1) functions. @EOL
   @Keywords  blas cblas C fortran numerical linear algebra vector matrix gemv
   ger
   @Std       C89

   This is a simple program intended to illistrate how to make use of #gemv and
   #ger blas routines (as implimented in the cblas).

*/

/* ------------------------------------------------------------------------------------------------------------------------------
 */

#include "blaio.h"  /* Basic Linear Algebra I/O */
#include <stdio.h>  /* I/O lib         ISOC     */
#include <stdlib.h> /* Standard Lib    ISOC     */

int main(int argc, char **argv) {
  double a[4 * 5] = {1, 2, 3, 4, 5, /* CblasRowMajor */
                     6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  double b[5 * 4] = {1, 0, 0, 0, /* CblasRowMajor */
                     0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0};
  double c[4 * 4];

  double d[4 * 4] = {1, 2, 3, 4, /* CblasRowMajor */
                     6, 7, 8, 9, 11, 12, 13, 14, 16, 17, 18, 19};
  double e[4 * 4] = {1, 0, 0, 0, /* CblasRowMajor */
                     0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1};

  printMatrix(CblasRowMajor, 4, 5, a, 8, 3, NULL, NULL, NULL, NULL, NULL,
              "              a = ");
  printMatrix(CblasRowMajor, 5, 4, b, 8, 3, NULL, NULL, NULL, NULL, NULL,
              "              b = ");
  /* row_order      transform     transform     rowsA colsB K  alpha  a  lda  b
   * ldb beta c   ldc */
  cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 4, 4, 5, 1.0, a, 5, b,
              4, 0.0, c, 4);
  printMatrix(CblasRowMajor, 4, 4, c, 8, 3, NULL, NULL, NULL, NULL, NULL,
              "c <- 1.0*a*b+0.0*c = ");

  printMatrix(CblasRowMajor, 4, 4, d, 8, 3, NULL, NULL, NULL, NULL, NULL,
              "              d = ");
  printMatrix(CblasRowMajor, 4, 4, e, 8, 3, NULL, NULL, NULL, NULL, NULL,
              "              e = ");
  /* row_order      transform     transform     rowsA colsB K  alpha  a  lda  b
   * ldb beta c   ldc */
  cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 4, 4, 4, 1.0, d, 4, e,
              4, 0.0, c, 4);
  printMatrix(CblasRowMajor, 4, 4, c, 8, 3, NULL, NULL, NULL, NULL, NULL,
              "c <- 1.0*d*e+0.0*c = ");

  return 0;
} /* end func main */
