#include <stdio.h>
#include <string.h>

typedef char fstr_16[16];

void fs16_(fstr_16, int, int *, int *, fstr_16, int);

int main() {
  char work[64];
  fstr_16 inp, oup;
  int j = 7;
  int k = 11;
  strncpy(inp, "0123456789abcdef", sizeof(inp));
  fs16_(oup, sizeof(oup), &j, &k, inp, sizeof(inp));
  strncpy(work, oup, sizeof(oup));
  work[sizeof(oup)] = '\0';
  printf("FS16 returns <%s>\n", work);
  return 0;
}
