#include <stdio.h>

int fact_(int *n);
void pythagoras_(float *a, float *b, float *c);

int main() {

  int nn = 7;
  printf("Factorial of 7 is: %d\n", fact_(&nn));

  float cc;
  float aa = 30.0;
  float bb = 40.0;
  pythagoras_(&aa, &bb, &cc);
  printf("Hypotenuse if sides 30, 40 is: %f\n", cc);

  return 0;
}
