#include <stdio.h>

#include <cblas.h>

typedef struct {
  double re;
  double im;
} complex16;

#define N 5

int main()

{

  int n, inca = 1, incb = 1, i;

  complex16 a[N], b[N], c;

  n = N;

  for (i = 0; i < n; i++) {

    a[i].re = (double)i;
    a[i].im = (double)i * 2.0;

    b[i].re = (double)(n - i);
    b[i].im = (double)i * 2.0;
  }

  cblas_zdotc_sub(n, a, inca, b, incb, &c);

  printf("The complex dot product is: ( %6.2f, %6.2f)\n", c.re, c.im);

  return 0;
}
