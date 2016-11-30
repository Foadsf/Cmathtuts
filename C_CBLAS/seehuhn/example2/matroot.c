/* matroot.c - calculate the square root of a matrix
 *
 * Copyright (C) 2004  Jochen Voss.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * $Id: matroot.c 7208 2006-09-03 16:11:08Z voss $
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <cblas.h>


static const int N = 7;


static void
set_entry(double *A, int i, int j, double val)
{
  A[j*N+i] = val;
}

static double
get_entry(const double *A, int i, int j)
{
  return A[j*N+i];
}

static int
dsyevr(char JOBZ, char RANGE, char UPLO, int N,
       double *A, int LDA, double VL, double VU,
       int IL, int IU, double ABSTOL, int *M,
       double *W, double *Z, int LDZ, int *ISUPPZ,
       double *WORK, int LWORK, int *IWORK, int LIWORK)
{
  extern void dsyevr_(char *JOBZp, char *RANGEp, char *UPLOp, int *Np,
                      double *A, int *LDAp, double *VLp, double *VUp,
                      int *ILp, int *IUp, double *ABSTOLp, int *Mp,
                      double *W, double *Z, int *LDZp, int *ISUPPZ,
                      double *WORK, int *LWORKp, int *IWORK, int *LIWORKp,
                      int *INFOp);
  int INFO;
  dsyevr_(&JOBZ, &RANGE, &UPLO, &N, A, &LDA, &VL, &VU,
          &IL, &IU, &ABSTOL, M, W, Z, &LDZ, ISUPPZ,
          WORK, &LWORK, IWORK, &LIWORK, &INFO);
  return INFO;
}

static double
dlamch(char CMACH)
{
  extern double dlamch_(char *CMACHp);
  return dlamch_(&CMACH);
}

int
main()
{
  double *A, *B, *W, *Z, *WORK;
  int *ISUPPZ, *IWORK;
  int  i, j;
  int  M;

  /* allocate and initialise the matrix */
  A = malloc(N*N*sizeof(double));
  for (i=0; i<N; ++i) {
    for (j=0; j<i-1; ++j) {
      set_entry(A, i, j, 0);
    }
  }
  for (i=0; i<N-1; ++i)  set_entry(A, i+1, i, -1);
  for (i=1; i<N-1; ++i)  set_entry(A, i, i, 2);
  set_entry(A, 0, 0, 1);
  set_entry(A, N-1, N-1, 1);

  /* allocate space for the output parameters and workspace arrays */
  W = malloc(N*sizeof(double));
  Z = malloc(N*N*sizeof(double));
  ISUPPZ = malloc(2*N*sizeof(int));
  WORK = malloc(26*N*sizeof(double));
  IWORK = malloc(10*N*sizeof(int));

  /* get the eigenvalues and eigenvectors */
  dsyevr('V', 'A', 'L', N, A, N, 0, 0, 0, 0, dlamch('S'), &M,
         W, Z, N, ISUPPZ, WORK, 26*N, IWORK, 10*N);

  /* allocate and initialise a new matrix B=Z*D */
  B = malloc(N*N*sizeof(double));
  for (j=0; j<N; ++j) {
    double  lambda=sqrt(W[j]);
    for (i=0; i<N; ++i) {
      set_entry(B, i, j, get_entry(Z,i,j)*lambda);
    }
  }

  /* calculate the square root A=B*Z^T */
  cblas_dgemm(CblasColMajor, CblasNoTrans, CblasTrans, N, N, N,
              1, B, N, Z, N, 0, A, N);

  /* emit the result */
  for (i=0; i<N; ++i) {
    for (j=0; j<N; ++j) {
      double  x = get_entry(A, i, j);
      printf("%6.2f", x);
    }
    putchar('\n');
  }
  putchar('\n');

  /* check the result by calculating A*A */
  memcpy(B, A, N*N*sizeof(double));
  cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, N, N, N,
              1, A, N, B, N, 0, Z, N);

  for (i=0; i<N; ++i) {
    for (j=0; j<N; ++j) {
      double  x = get_entry(Z, i, j);
      printf("%6.2f", x);
    }
    putchar('\n');
  }

  return 0;
}
