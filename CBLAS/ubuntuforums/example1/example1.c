#include <cblas.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// using namespace::std;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: mm dim1 dim2 dim3\n");
    printf("Please specify matrix dimensions\n");
    return 1;
  }
  int dim1, dim2, dim3;
  dim1 = atoi(argv[1]);
  if (argc < 3)
    dim2 = dim1;
  else
    dim2 = atoi(argv[2]);
  if (argc < 4)
    dim3 = dim1;
  else
    dim3 = atoi(argv[3]);
  double A[dim1][dim2], B[dim2][dim3], C[dim1][dim3];
  srand(12345);
  double maxr = RAND_MAX;
  int i, j;
  for (i = 0; i < dim1; i++)
    for (j = 0; j < dim2; j++)
      A[i][j] = rand() / maxr;
  for (i = 0; i < dim2; i++)
    for (j = 0; j < dim3; j++)
      B[i][j] = rand() / maxr;
  double alpha = 1.;
  double beta = 0.;
  double start;
  start = clock();
  cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, dim1, dim3, dim2,
              alpha, *A, dim1, *B, dim2, beta, *C, dim1);
  double finish = clock();
  printf("time for C(%d,%d) = A(%d,%d) B(%d,%d) is %f s\n", dim1, dim3, dim1,
         dim2, dim2, dim3, (finish - start) / CLOCKS_PER_SEC);
  return 0;
}
