#include <stdio.h>

void ranvec_(double *, int *);

int main() {
  int n = 5;
  double a[5];

  ranvec_(a, &n);

  printf("a = %f, %f, %f, %f, %f\n", a[0], a[1], a[2], a[3], a[4]);

  return 0;
}
