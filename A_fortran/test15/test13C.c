#include <stdio.h>
#include <string.h>

typedef struct { double real, imag; } cpx8;

cpx8 fsub8_(cpx8 *);

int main() {
  cpx8 inp = {-3.333, -5.555};
  // cpx8 oup = {0.0, 0.0};
  cpx8 oup;
  printf("testing fsub8...");
  oup = fsub8_(&inp);
  if (inp.real == oup.real && inp.imag == oup.imag)
    printf("Ok\n");
  else
    printf("Nope\n");
  return 0;
}
