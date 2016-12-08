/*  File CSUBS.C  */

#include <math.h>

int Fact(int n) {
  if (n > 1)
    return (n * Fact(n - 1));
  return 1;
}

void Pythagoras(float a, float b, float *c) { *c = sqrt(a * a + b * b); }
