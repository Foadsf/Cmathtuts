#include <stdio.h>

void fortfunc_(int *, float *);

int main() {

  int ii = 5;
  float ff = 6.345;

  fortfunc_(&ii, &ff);

  return 0;
}
