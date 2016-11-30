#include <stdio.h>

struct {
  int i;
  double a[10];
  long double d;
} ST;

void fctn_();

int main() {
  int i;

  /* initialize struct ST */
  ST.i = 12345;

  for (i = 0; i < 10; i++)
    ST.a[i] = i;

  ST.d = 1234567890.1234567890L;

  /* print out the members of struct ST */
  printf("In C: ST.i = %d, ST.d = %20.10Lf\n", ST.i, ST.d);
  printf("In C: ST.a = ");
  for (i = 0; i < 10; i++)
    printf("%4.1f", ST.a[i]);
  printf("\n\n");

  /* call the fortran function */
  fctn_();
  return 0;
}
