#include <stdio.h>
#include <stdlib.h>

#define N 10

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

void fortran_func_(type1_t *, int);

int main() {

  type1_t A;

  A.idx = 0;
  A.params.idx = 0;
  A.params.size = 0;
  A.status = (type3_t *)malloc(sizeof(type3_t) * N);
  for (int i = 0; i < N; ++i) {
    A.status[i].idx = 0;
    A.status[i].size = 0;
  }

  fortran_func_(&A, N);

  printf("%d %d %d\n", A.idx, A.params.idx, A.params.size);
  for (int i = 0; i < N; ++i) {
    printf("%d %d\n", A.status[i].idx, A.status[i].size);
  }

  free(A.status);
}
