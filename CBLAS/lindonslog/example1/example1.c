#include <stdio.h>

// #ifdef __APPLE__
// #include <Accelerate/Accelerate.h> /* The MacOS X blas/lapack */
// #else
#include <cblas.h> /* C BLAS          BLAS  */
// #endif

int main() {
  int i;
  double x[] = {1, 1, 1};

  cblas_dscal(3, 4.323, x, 1);

  for (i = 0; i < 3; ++i)
    printf("%f\n", x[i]);

  return 0;
}
