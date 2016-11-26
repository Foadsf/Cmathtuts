#include <stdio.h>
#include <stdlib.h>

#include "blaswrap.h"
#include "f2c.h"
#include "clapack.h"

#include <math.h>

#define NDIM 2 

int main (){

int i, j, info2;
long int N, NRHS, LDA, LDB;
doublecomplex *A;
doublecomplex *B;
static long int IPIV, INFO;

A = (doublecomplex*) malloc(NDIM*NDIM*sizeof(doublecomplex));
B = (doublecomplex*) malloc(NDIM*sizeof(doublecomplex));

N=NDIM; NRHS=1; LDA=NDIM; LDB=NDIM;

    for (i=0;i<N;i++){
       for (j=0;j<N;j++) {
          A[i+N*j].r = cos(M_PI*(i+1)*3.0/4.0);  
          A[i+N*j].i = sin(M_PI*(j+1)/5.0);  
          printf("   %f + %fi \n",A[i+N*j].r, A[i+N*j].i);
       }
    }

   B[0].r = 1.0; 
   B[0].i = 1.0; 
   B[1].r = 2.0;
   B[1].i = 3.0;


   info2 = zgesv_(&N, &NRHS, A, &LDA, &IPIV, B, &LDB, &INFO);

   printf("info %ld \n",INFO);
 
   for (i=0;i<N;i++)
      printf("   %f + %fi \n",B[i].r, B[i].i);
}
