#include <stdio.h>
#include <string.h>

typedef char fstr_16[16];

void prt_(fstr_16, float *, fstr_16, int, int);

int main() {
  float val = 2.1828e0;
  fstr_16 bef, aft;
  strncpy(bef, "Before..........", sizeof(bef));
  strncpy(aft, "...........After", sizeof(aft));
  prt_(bef, &val, aft, sizeof(bef), sizeof(aft));
  return 0;
}
