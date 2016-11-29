#include "lapacke.h"
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double A[36] = {4, 3, 0, 4, 0, 3, 2, 3, 3, 2, 2, 0, 0, 3, 2, 2, 0, 3,
                3, 3, 2, 3, 0, 0, 1, 2, 3, 4, 0, 2, 2, 4, 2, 4, 3, 2};

double Arow[36] = {
    4, 2, 0, 3, 1, 2, 3, 3, 3, 3, 2, 4, 0, 3, 2, 2, 3, 2,
    4, 2, 2, 3, 4, 4, 0, 2, 0, 0, 0, 3, 3, 0, 3, 0, 2, 2,
};

double B[24] = {2, 2, 3, 2, 4, 0, 3, 1, 3, 2, 1, 0,
                2, 4, 3, 4, 2, 0, 1, 4, 2, 4, 0, 4};

double Brow[24] = {
    2, 3, 2, 1, 2, 1, 4, 4, 3, 3, 3, 2, 2, 2, 4, 4, 4, 1, 2, 0, 0, 0, 0, 4,
};

/* Auxiliary routine: printing a matrix */
void print_matrix(char *desc, char major, int m, int n, double *a, int lda) {
  int i, j;
  printf("\n %s (%c major)\n", desc, major);
  if (major == 'C')
    for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++)
        printf(" %6.2f", a[i + j * lda]);
      printf("\n");
    }

  else {
    printf("m=%d,n=%d\n", m, n);
    for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++)
        printf(" %6.2f", a[j + i * lda]);
      printf("\n");
    }
  }
}

void eq_solve(double *a, double *b, int n, int nrhs, char major) {
  int info, i;
  // char trans = 'n';
  lapack_int lda, ldb, *ipiv;
  lda = n;
  ipiv = malloc(sizeof(int) * n);
  /* Print A */
  print_matrix("A", major, n, n, a, lda);

  if (major == 'C') {
    ldb = n;
    /* Print B */
    print_matrix("B", major, n, nrhs, b, ldb);
    // EQUIVALENT STATEMENT
    info = LAPACKE_dgesv(LAPACK_COL_MAJOR, (lapack_int)n, (lapack_int)nrhs, a,
                         lda, ipiv, b, ldb);
    // dgesv_( &n, &nrhs, a, &lda, ipiv, b, &ldb, &info );
  } else {
    ldb = nrhs;
    /* Print B */
    print_matrix("B", major, n, nrhs, b, ldb);
    info = LAPACKE_dgesv(LAPACK_ROW_MAJOR, (lapack_int)n, (lapack_int)nrhs, a,
                         lda, ipiv, b, ldb);
  }

  if (info != 0) {
    fprintf(stderr, "dgesv: info = %d\n", info);
  }
  assert(info == 0);
  printf("dgesv passed\n");
  // debug_print("b using lapacke", b,n,nrhs,0);
  // print answer here
  print_matrix("Answer", major, n, nrhs, b, ldb);

  free(ipiv);
}

int main(void) {
  printf("==============================\n");
  printf("\tSOLVING IN COL MAJOR\n");
  printf("==============================\n");
  eq_solve(A, B, 6, 4, 'C');
  printf("\n==============================\n");
  printf("\tSOLVING IN ROW MAJOR\n");
  printf("==============================\n");
  eq_solve(Arow, Brow, 6, 4, 'R');

  return 0;
}
