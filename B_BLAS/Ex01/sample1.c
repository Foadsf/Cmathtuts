#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dgemm_(char *transa, char *transb, int *m, int *n, int *k, double *alpha,
            double *a, int *lda, double *b, int *ldb, double *beta, double *c,
            int *ldc);

void init(double *matrix, int row, int column) {
  for (int j = 0; j < column; j++) {
    for (int i = 0; i < row; i++) {
      matrix[j * row + i] = ((double)rand()) / RAND_MAX;
    }
  }
}

void print(const char *name, const double *matrix, int row, int column) {
  printf("Matrix %s has %d rows and %d columns:\n", name, row, column);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      printf("%.3f ", matrix[j * row + i]);
    }
    printf("\n");
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  int rowsA, colsB, common;
  int i, j, k;

  if (argc != 4) {
    printf("Using defaults\n");
    rowsA = 2;
    colsB = 4;
    common = 6;
  } else {
    rowsA = atoi(argv[1]);
    colsB = atoi(argv[2]);
    common = atoi(argv[3]);
  }

  double A[rowsA * common];
  double B[common * colsB];
  double C[rowsA * colsB];
  double D[rowsA * colsB];

  char transA = 'N', transB = 'N';
  double one = 1.0, zero = 0.0;

  srand(time(NULL));

  init(A, rowsA, common);
  init(B, common, colsB);

  dgemm_(&transA, &transB, &rowsA, &colsB, &common, &one, A, &rowsA, B, &common,
         &zero, C, &rowsA);

  for (i = 0; i < colsB; i++) {
    for (j = 0; j < rowsA; j++) {
      D[i * rowsA + j] = 0;
      for (k = 0; k < common; k++) {
        D[i * rowsA + j] += A[k * rowsA + j] * B[k + common * i];
      }
    }
  }

  print("A", A, rowsA, common);
  print("B", B, common, colsB);
  print("C", C, rowsA, colsB);
  print("D", D, rowsA, colsB);

  return 0;
}
