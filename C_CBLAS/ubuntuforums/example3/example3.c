#include <stdio.h>
#include <stdlib.h> //for malloc

#ifdef __APPLE__
#include <Accelerate/Accelerate.h> /* The MacOS X blas/lapack */
#else
#include <cblas.h> /* C BLAS          BLAS  */
#endif

int main(int argc, char **argv) {
  // you can define the arrays in one of two ways
  // on the heap
  double *a = (double *)malloc(3 * sizeof(double));
  a[0] = 1.0;
  a[1] = 2.0;
  a[2] = 3.0;
  // on the stack
  double b[3] = {4.0, 5.0, 6.0};

  double dot_product = cblas_ddot(3, a, 1, b, 1);
  printf(" The dot product is: %f \n", dot_product);

  return 0;
};
