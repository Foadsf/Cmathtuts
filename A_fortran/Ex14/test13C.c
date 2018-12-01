#include <stdio.h>
#include <string.h>

void prt_(char const *, float *, char const *, int, int);

int main() {
  float val = 2.1828e0;
  char const *bef = "Start:";
  char const *aft = ":End";
  prt_(bef, &val, aft, strlen(bef), strlen(aft));
  return 0;
}
