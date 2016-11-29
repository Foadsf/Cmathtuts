#include <stdio.h>

extern void dscal_(const int *N, const double *alpha, double *X,
                   const int *incX);

int main() {
  int i, n, one;
  double coefficient;
  double x[] = {1, 1, 1};

  coefficient = 4.323;
  one = 1;
  n = 3;

  dscal_(&n, &coefficient, &x[0], &one);

  for (i = 0; i < 3; ++i)
    printf("%f\n", x[i]);

  return 0;
}
