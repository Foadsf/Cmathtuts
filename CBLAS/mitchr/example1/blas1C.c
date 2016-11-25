/* -*- Mode:C; Coding:us-ascii-unix; fill-column:132 -*- */
/* ******************************************************************************************************************************
 */
/**
   @file      blas1C.c
   @author    Mitch Richling <https://www.mitchr.me/>
   @Copyright Copyright 1997 by Mitch Richling.  All rights reserved.
   @breif     Demonstrate Level 1 BLAS.@EOL
   @Keywords  blas cblas C FORTRAN numerical linear algebra vector matrix
   @Std       C89

   This is a simple program intended to illustrate how to make use of several
   level 1 blas functions found in the cblas (ATLAS).
   Functions illustrated:

      - dswap
      - dcopy
      - daxpy
      - ddotu
      - ddot
      - dnrm2
      - dasum
      - dscal
      - ddotc
      - idmax

*/

/* ------------------------------------------------------------------------------------------------------------------------------
 */

#include "blaio.h"  /* Basic Linear Algebra I/O */
#include <stdio.h>  /* I/O lib         ISOC     */
#include <stdlib.h> /* Standard Lib    ISOC     */

int main(int argc, char **argv) {
  double x[4] = {2, 3, 4, 5};
  double y[4] = {5, 4, 9, 2};
  double d[4];

  printVector(4, x, 3, 1, NULL, NULL, NULL, "            x = ");
  printVector(4, y, 3, 1, NULL, NULL, NULL, "            y = ");

  /* lenX X  incX Y  incY*/
  cblas_dswap(4, x, 1, y, 1);

  printf("After Swap..\n");
  printVector(4, x, 3, 1, NULL, NULL, NULL, "            x = ");
  printVector(4, y, 3, 1, NULL, NULL, NULL, "            y = ");

  /* lenX X  incX Y  incY*/
  cblas_dcopy(4, x, 1, d, 1);
  printf("After Copy (d=x)..\n");
  printVector(4, d, 3, 1, NULL, NULL, NULL, "       d <- x = ");

  /* lenX alpha X  incX */
  cblas_dscal(4, 2.0, y, 1);
  printf("After Scale (2*y)..\n");
  printVector(4, y, 3, 1, NULL, NULL, NULL, "        2.0*y = ");

  /* lenX alpha X  incX y  incY*/
  cblas_daxpy(4, 3.0, x, 1, y, 1);
  printf("After Add (y=3*x+y)..\n");
  printVector(4, y, 3, 1, NULL, NULL, NULL, " y <- 3.0*x+y = ");

  /* lenX X  incX */
  printf("2-norm   of y = %0.2f\n", (float)cblas_dnrm2(4, y, 1));
  printf("sum-norm of y = %0.2f\n", (float)cblas_dasum(4, y, 1));

  /* Note, the i#amax norm returns the INDEX of the element that corresponds to
   * the max-norm value. */
  /* lenX X  incX */
  printf("max-norm of y = |y[%d]|\n", (int)cblas_idamax(4, y, 1));

  /* lenX X  incX Y  incY */
  printf("      y dot y = %0.2f\n", (float)cblas_ddot(4, y, 1, y, 1));

  return 0;
} /* end func main */
