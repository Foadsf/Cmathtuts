#include <stdio.h>

void fortfunc_(int *ii, float *ff);

int main() {

  int ii = 5;
  float ff = 5.5;

  fortfunc_(&ii, &ff);

  return 0;
}
