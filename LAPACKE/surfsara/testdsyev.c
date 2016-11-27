/*
subroutine dsyev 	( 	character  	JOBZ,
                character  	UPLO,
                integer  	N,
                double precision, dimension( lda, * )  	A,
                integer  	LDA,
                double precision, dimension( * )  	W,
                double precision, dimension( * )  	WORK,
                integer  	LWORK,
                integer  	INFO
        )

DSYEV computes the eigenvalues and, optionally, the left and/or right
eigenvectors for SY matrices
Download DSYEV + dependencies [TGZ] [ZIP] [TXT]

Purpose:

     DSYEV computes all eigenvalues and, optionally, eigenvectors of a
     real symmetric matrix A.

Parameters:
    [in]	JOBZ

              JOBZ is CHARACTER*1
              = 'N':  Compute eigenvalues only;
              = 'V':  Compute eigenvalues and eigenvectors.

    [in]	UPLO

              UPLO is CHARACTER*1
              = 'U':  Upper triangle of A is stored;
              = 'L':  Lower triangle of A is stored.

    [in]	N

              N is INTEGER
              The order of the matrix A.  N >= 0.

    [in,out]	A

              A is DOUBLE PRECISION array, dimension (LDA, N)
              On entry, the symmetric matrix A.  If UPLO = 'U', the
              leading N-by-N upper triangular part of A contains the
              upper triangular part of the matrix A.  If UPLO = 'L',
              the leading N-by-N lower triangular part of A contains
              the lower triangular part of the matrix A.
              On exit, if JOBZ = 'V', then if INFO = 0, A contains the
              orthonormal eigenvectors of the matrix A.
              If JOBZ = 'N', then on exit the lower triangle (if UPLO='L')
              or the upper triangle (if UPLO='U') of A, including the
              diagonal, is destroyed.

    [in]	LDA

              LDA is INTEGER
              The leading dimension of the array A.  LDA >= max(1,N).

    [out]	W

              W is DOUBLE PRECISION array, dimension (N)
              If INFO = 0, the eigenvalues in ascending order.

    [out]	WORK

              WORK is DOUBLE PRECISION array, dimension (MAX(1,LWORK))
              On exit, if INFO = 0, WORK(1) returns the optimal LWORK.

    [in]	LWORK

              LWORK is INTEGER
              The length of the array WORK.  LWORK >= max(1,3*N-1).
              For optimal efficiency, LWORK >= (NB+2)*N,
              where NB is the blocksize for DSYTRD returned by ILAENV.

              If LWORK = -1, then a workspace query is assumed; the routine
              only calculates the optimal size of the WORK array, returns
              this value as the first entry of the WORK array, and no error
              message related to LWORK is issued by XERBLA.

    [out]	INFO

              INFO is INTEGER
              = 0:  successful exit
              < 0:  if INFO = -i, the i-th argument had an illegal value
              > 0:  if INFO = i, the algorithm failed to converge; i
                    off-diagonal elements of an intermediate tridiagonal
                    form did not converge to zero.

*/

#include "unistd.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/times.h>

#include <lapacke.h>

double wallclock(void);
double cputime(void);
double wallclock() {
  struct timeval tt;
  struct timezone pt;
  double r;

  gettimeofday(&tt, &pt);
  r = tt.tv_sec + 0.000001 * (double)tt.tv_usec;
  return (r);
}
double cputime() {
  struct tms b;
  clock_t r;
  times(&b);
  r = b.tms_utime + b.tms_stime;
  return ((double)r / (double)sysconf(_SC_CLK_TCK));
}

int main() {
  char jobz;
  char uplo;
  int n;
  double *a;
  int lda;
  double *w;

  int info;
  double t1;
  double t2;

  int i;

  jobz = 'V';
  uplo = 'U';
  n = 1000;
  lda = n;
  a = (double *)malloc(sizeof(double) * lda * n);
  w = (double *)malloc(sizeof(double) * n);
  // initialize a
  for (i = 0; i < n * n; i++)
    a[i] = (double)random() / RAND_MAX;

  t1 = cputime();
  info = LAPACKE_dsyev(LAPACK_COL_MAJOR, jobz, uplo, n, a, lda, w);
  // Note: the handling of work-arrays is done inside LAPACKE
  t2 = cputime() - t1;
  printf(" n=%d: info=%d time=%lf\n", n, info, t2);

  free(a);
  free(w);
  return 0;
}
