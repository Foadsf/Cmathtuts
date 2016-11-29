/* solving the matrix equation A*x=b using LAPACK */

#include <stdio.h>
#define size 3 /* dimension of matrix */

void sgesv_(int *n, int *nrhs, float *a, int *lda, int *ipiv, float *b,
            int *ldb, int *info);

int main() {
  int i, j, c1, c2, pivot[size], ok;
  float A[size][size], b[size], AT[size * size]; /* single precision!!! */

  A[0][0] = 3.1;
  A[0][1] = 1.3;
  A[0][2] = -5.7; /* matrix A */
  A[1][0] = 1.0;
  A[1][1] = -6.9;
  A[1][2] = 5.8;
  A[2][0] = 3.4;
  A[2][1] = 7.2;
  A[2][2] = -8.8;

  b[0] = -1.3; /* if you define b as a matrix then you */
  b[1] = -0.1; /* can solve multiple equations with */
  b[2] = 1.8;  /* the same A but different b */

  for (i = 0; i < size; i++) /* to call a Fortran routine from C we */
  {                          /* have to transform the matrix */
    for (j = 0; j < size; j++)
      AT[j + size * i] = A[j][i];
  }

  c1 = size; /* and put all numbers we want to pass */
  c2 = 1;    /* to the routine in variables */

  /* find solution using LAPACK routine SGESV, all the arguments have to */
  /* be pointers and you have to add an underscore to the routine name */
  sgesv_(&c1, &c2, AT, &c1, pivot, b, &c1, &ok);

  /*
   parameters in the order as they appear in the function call
      order of matrix A, number of right hand sides (b), matrix A,
      leading dimension of A, array that records pivoting,
      result vector b on entry, x on exit, leading dimension of b
      return value */

  for (j = 0; j < size; j++)
    printf("%e\n", b[j]); /* print vector x */
  return 0;
}
