#include <stdio.h>

struct {
  int i;
  double a[10];
  long double d;
} st_;

void fctn_();

int main() {

  int i;

  /* initialize st_ruct st_ */
  st_.i = 12345;

  for (i = 0; i < 10; i++)
    st_.a[i] = i;

  st_.d = 1234567890.1234567890L;

  /* print out the members of st_ruct st_ */
  printf("In C: st_.i = %d, st_.d = %20.10Lf\n", st_.i, st_.d);
  printf("In C: st_.a = ");
  for (i = 0; i < 10; i++)
    printf("%4.1f", st_.a[i]);
  printf("\n\n");

  /* call the fortran function */
  fctn_();
  return 0;
}
