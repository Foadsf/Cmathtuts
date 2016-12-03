#include <stdio.h>

double add_(int *, double[], int *, double[]);

double ar1[4] = {1.0, 2.0, 3.0, 4.0};
double ar2[4] = {5.0, 6.0, 7.0, 8.0};

int main() {
  int x, y;
  double z;

  x = 3;
  y = 3;

  z = add_(&x, ar1, &y, ar2); /* Call Fortran add routine */
  /* Note: Fortran indexes arrays 1..n */
  /* C indexes arrays 0..(n-1) */

  printf("The sum of %1.0f and %1.0f is %2.0f \n", ar1[x - 1], ar2[y - 1], z);
  return 0;
}
