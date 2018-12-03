#include <stdio.h>
#include <stdlib.h> //for malloc

// FORTRAN adds _ after all the function names
// and all variables are called by reference
double ddot_(const int *N, const double *a, const int *inca, const double *b,
             const int *incb);

int main(int argc, char **argv) {
  // you can define the arrays in one of two ways
  // on the heap
  double *a = (double *)malloc(3 * sizeof(double));
  a[0] = 1.0;
  a[1] = 2.0;
  a[2] = 3.0;
  // on the stack
  double b[3] = {4.0, 5.0, 6.0};

  int N = 3, one = 1; // one really doesn't look good in C

  double dot_product = ddot_(&N, a, &one, b, &one);
  printf(" The dot product is: %f \n", dot_product);

  return 0;
};
