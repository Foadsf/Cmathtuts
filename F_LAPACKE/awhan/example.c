#include <lapacke.h>
int main() {
  double a[] = {1, 2, 3, 4};     // NO need for column-major mode
  double b[] = {19, 22, 43, 50}; // NO need for column-major mode
  int n = 2;
  int nrhs = 2;
  int lda = n;
  int ipiv[n];
  int ldb = n;

  int info = LAPACKE_dgesv(LAPACK_ROW_MAJOR, n, nrhs, a, lda, ipiv, b, ldb);

  return 0;
}
