#include <stdio.h>

int fact_(int *);
void pythagoras_(float *, float *, float *);

int main() {

  int nn = 4;
  printf("Factorial of %d is: %d\n", nn, fact_(&nn));

  float cc;
  float aa = 30.0;
  float bb = 40.0;
  pythagoras_(&aa, &bb, &cc);
  printf("Hypotenuse if sides %f, %f is: %f\n", aa, bb, cc);

  return 0;
}
