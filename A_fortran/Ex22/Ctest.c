#include <stdio.h>

typedef struct {
  float real;
  float imag;
} complex;

extern struct {
  float a;
  double b;
  int i;
  complex c;
} mycom_;

void getval_() {
  printf("a = %f\n", mycom_.a);
  printf("b = %f\n", mycom_.b);
  printf("i = %d\n", mycom_.i);
  printf("c.real = %f\n", mycom_.c.real);
  printf("c.imag = %f\n", mycom_.c.imag);
}
