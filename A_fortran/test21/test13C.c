#include <stdio.h>

typedef struct {
  int len;
  float *data;
} obj;

void subr_struct(const obj *);

int main(int argc, char **argv) {
  float data1[] = {0.12, 0.15, 0.18, 0.23, 0.29};
  obj obj1 = {5, data1};

  subr_struct(&obj1);

  return 0;
}
