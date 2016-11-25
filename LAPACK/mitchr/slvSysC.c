/* -*- Mode:C; Coding:us-ascii-unix; fill-column:132 -*- */
/* ******************************************************************************************************************************
 */
/**
   @file      slvSysC.c
   @author    Mitch Richling <https://www.mitchr.me/>
   @Copyright Copyright 1998 by Mitch Richling.  All rights reserved.
   @brief     Demonstrate LAPACK's sgesv functions.@EOL
   @Keywords  claback cblas sgesv numerical linear algebra
   @Std       C99

*/

/* ------------------------------------------------------------------------------------------------------------------------------
 */

#include <stdio.h>  /* I/O lib         ISOC  */
#include <stdlib.h> /* Standard Lib    ISOC  */
#ifdef __APPLE__
#include <Accelerate/Accelerate.h> /* The MacOS X blas/lapack stuff */
typedef __CLPK_integer CLPKinteger;
typedef __CLPK_doublereal CLPKdoublereal;
#else
#include <clapack.h> /* C LAPACK         */
typedef int CLPKinteger;
typedef double CLPKdoublereal;
#endif
#include "blaio.h" /* Basic Linear Algebra I/O */

int main(int argc, char **argv) {
  CLPKdoublereal a[4 * 4] = {
      1, 2, 3, 4, 6, 7, 9, 9, 11, 12, 19, 14, 16, 17, 18, 12,
  };
  CLPKdoublereal b[4] = {1, 3, 5, 6};
  CLPKinteger pivs[4], inf;
  CLPKinteger n = 4, lda = 4, nrhs = 1, ldb = 4;
  char tbuf[1024];
  int i;

  sprintf(tbuf, " a[%dx%d]= ", 4, 4);
  printMatrix(CblasColMajor, 4, 4, a, 15, 10, NULL, NULL, NULL, NULL, NULL,
              tbuf);

  sprintf(tbuf, " b[%dx%d]= ", 1, 4);
  printMatrix(CblasColMajor, 1, 4, b, 15, 10, NULL, NULL, NULL, NULL, NULL,
              tbuf);

  // sgesv_(&n, &nrhs, a, &lda, pivs, b, &ldb, &inf);
  dgesv_(&n, &nrhs, a, &lda, pivs, b, &ldb, &inf);

  if (inf == 0) {
    printf("Successful Solution\n");
  } else if (inf < 0) {
    printf("Illegal value at: %d\n", -(int)inf);
    exit(1);
  } else if (inf > 0) {
    printf("Matrix was singular\n");
    exit(1);
  } else {
    printf("Unknown Result (Can't happen!)\n");
    exit(1);
  } /* end if/else */

  sprintf(tbuf, "a'[%dx%d]= ", 4, 4);
  printMatrix(CblasColMajor, 4, 4, a, 15, 10, NULL, NULL, NULL, NULL, NULL,
              tbuf);

  sprintf(tbuf, "b'[%dx%d]= ", 1, 4);
  printMatrix(CblasColMajor, 1, 4, b, 15, 10, NULL, NULL, NULL, NULL, NULL,
              tbuf);

  printf("PIV=");
  for (i = 0; i < 4; i++)
    printf("%4d ", (int)(pivs[i]));
  printf("\n");

  // *  IPIV    (output) INTEGER array, dimension (N)
  // *          The pivot indices that define the permutation matrix P;
  // *          row i of the matrix was interchanged with row IPIV(i).
  // *

  return 0;

} /* end func main */
