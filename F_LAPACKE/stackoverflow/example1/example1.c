#include <lapacke.h>
#include <stdio.h>

void print_mtrx(double *mtrx, int n, int m) {
  int i, j;

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("%f ", mtrx[i * m + j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main() {
  double diagonal[5] = {5, 1, 5, 1, 5};
  double subdiagonal[4] = {0, 0, 0, 0};

  double solution[5] = {1, 2, 3, 4, 5};

  LAPACKE_dptsv(LAPACK_ROW_MAJOR, 5 /*size of matrix*/,
                1 /*number of columns in solution*/, diagonal, subdiagonal,
                solution, 1 /*leading dimension of solution vector*/);

  print_mtrx(solution, 5, 1);
}
