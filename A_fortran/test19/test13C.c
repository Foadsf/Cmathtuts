#include <stdio.h>
#include <stdlib.h>

typedef struct TYPE3_T {
  int idx;
  int size;
} type3_t;

typedef struct TYPE2_T {
  int idx;
  int size;
} type2_t;

typedef struct TYPE1_T {
  type2_t params;
  type3_t *status;
  int idx;
} type1_t;

void init_data(type1_t *A, int N) {

  A->idx = 1;
  A->params.idx = 10;
  A->params.size = 100;

  A->status = (type3_t *)malloc(sizeof(type3_t) * N);
  for (int i = 0; i < N; ++i) {
    A->status[i].idx = i + 1;
    A->status[i].size = N - i;
  }
}
