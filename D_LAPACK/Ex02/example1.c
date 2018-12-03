
#include <stdio.h>
#include <stdlib.h>

/* Complex datatype */
struct _dcomplex {
  double re, im;
};
typedef struct _dcomplex dcomplex;

/* ZGESV prototype */
extern void zgesv(int *n, int *nrhs, dcomplex *a, int *lda, int *ipiv,
                  dcomplex *b, int *ldb, int *info);
/* Auxiliary routines prototypes */
extern void print_matrix(char *desc, int m, int n, dcomplex *a, int lda);
extern void print_int_vector(char *desc, int n, int *a);

/* Parameters */
#define N 4
#define NRHS 2
#define LDA N
#define LDB N

/* Main program */
int main() {
  /* Locals */
  int n = N, nrhs = NRHS, lda = LDA, ldb = LDB, info;
  /* Local arrays */
  int ipiv[N];
  dcomplex a[LDA * N] = {
      {1.23, -5.50},  {-2.14, -1.12}, {-4.30, -7.10}, {1.27, 7.29},
      {7.91, -5.38},  {-9.92, -0.79}, {-6.47, 2.52},  {8.90, 6.92},
      {-9.80, -4.86}, {-9.18, -1.12}, {-6.51, -2.67}, {-8.82, 1.25},
      {-7.32, 7.57},  {1.37, 0.43},   {-5.86, 7.38},  {5.41, 5.37}};
  dcomplex b[LDB * NRHS] = {{8.33, -7.32}, {-6.18, -4.80}, {-5.71, -2.80},
                            {-1.60, 3.08}, {-6.11, -3.81}, {0.14, -7.71},
                            {1.41, 3.40},  {8.54, -4.05}};
  /* Executable statements */
  printf(" ZGESV Example Program Results\n");
  /* Solve the equations A*X = B */
  zgesv(&n, &nrhs, a, &lda, ipiv, b, &ldb, &info);
  /* Check for the exact singularity */
  if (info > 0) {
    printf("The diagonal element of the triangular factor of A,\n");
    printf("U(%i,%i) is zero, so that A is singular;\n", info, info);
    printf("the solution could not be computed.\n");
    exit(1);
  }
  /* Print solution */
  print_matrix("Solution", n, nrhs, b, ldb);
  /* Print details of LU factorization */
  print_matrix("Details of LU factorization", n, n, a, lda);
  /* Print pivot indices */
  print_int_vector("Pivot indices", n, ipiv);
  exit(0);
} /* End of ZGESV Example */

/* Auxiliary routine: printing a matrix */
void print_matrix(char *desc, int m, int n, dcomplex *a, int lda) {
  int i, j;
  printf("\n %s\n", desc);
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++)
      printf(" (%6.2f,%6.2f)", a[i + j * lda].re, a[i + j * lda].im);
    printf("\n");
  }
}

/* Auxiliary routine: printing a vector of integers */
void print_int_vector(char *desc, int n, int *a) {
  int j;
  printf("\n %s\n", desc);
  for (j = 0; j < n; j++)
    printf(" %6i", a[j]);
  printf("\n");
}
