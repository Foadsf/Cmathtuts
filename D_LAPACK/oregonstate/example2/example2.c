/* finding the eigenvalues of a dcomplex matrix */

#include <stdio.h>
#define size 3 /* dimension of matrix */

/* dcomplex datatype */
struct _dcomplex {
  double re, im;
};
typedef struct _dcomplex dcomplex;

/* ZGEEV prototype */
extern void zgeev_(char *jobvl, char *jobvr, int *n, dcomplex *a, int *lda,
                   dcomplex *w, dcomplex *vl, int *ldvl, dcomplex *vr,
                   int *ldvr, dcomplex *work, int *lwork, double *rwork,
                   int *info);

int main() {
  dcomplex A[3][3], b[3], DUMMY[1][1], WORK[6];
  double AT[2 * size * size]; /* for transformed matrix */
  int i, j, ok, c1, c2, c3;
  char c4;

  A[0][0].re = 3.1;
  A[0][0].im = -1.8; /* the input matrix */
  A[0][1].re = 1.3;
  A[0][1].im = 0.2;
  A[0][2].re = -5.7;
  A[0][2].im = -4.3;
  A[1][0].re = 1.0;
  A[1][0].im = 0;
  A[1][1].re = -6.9;
  A[1][1].im = 3.2;
  A[1][2].re = 5.8;
  A[1][2].im = 2.2;
  A[2][0].re = 3.4;
  A[2][0].im = -4;
  A[2][1].re = 7.2;
  A[2][1].im = 2.9;
  A[2][2].re = -8.8;
  A[2][2].im = 3.2;

  for (i = 0; i < size; i++) /* to call a Fortran routine from C we */
  {                          /* have to transform the matrix */
    for (j = 0; j < 2 * size; j++) {
      AT[2 * (j + size * i)] = A[j][i].re;
      AT[2 * (j + size * i) + 1] = A[j][i].im;
    }
  }

  c1 = size;     /* and put all numbers and characters */
  c2 = 2 * size; /* we want to pass */
  c3 = 1;        /* to the routine in variables */
  c4 = 'N';

  /* find solution using LAPACK routine ZGEEV, all the arguments have to */
  /* be pointers and you have to add an underscore to the routine name */
  zgeev_(&c4, &c4, &c1, AT, &c1, b, DUMMY, &c3, DUMMY, &c3, WORK, &c2, WORK,
         &ok);

  /*
   parameters in the order as they appear in the function call
      no left eigenvectors, no right eigenvectors, order of input matrix A,
      input matrix A, leading dimension of A, array for eigenvalues,
      array for left eigenvalue, leading dimension of DUMMY,
      array for right eigenvalues, leading dimension of DUMMY,
      workspace array dim>=2*order of A, dimension of WORK
      workspace array dim=2*order of A, return value */

  if (ok == 0) /* output of eigenvalues */
  {
    for (i = 0; i < size; i++) {
      printf("%f\t%f\n", b[i].re, b[i].im);
    }
  } else
    printf("An error occured");

  return 0;
}
