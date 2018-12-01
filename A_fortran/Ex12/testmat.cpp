
extern "C" {
    void testmat_( int *N, float *mat1, float *mat2, float *mat3);
    }


void testmat_(  int *N, float *mat1, float *mat2, float *mat3 ) 
{
    int i,j,k;
    float dot;

    // Assign stuff to mat3 from mat1 and mat2
    for (i=0; i<*N; i++) { 
      for (j=0; j<*N; j++) {
         dot = 0.0;
         for (k=0; k<*N; k++ ) {
           dot = dot + *(mat1+(*N*j+k)) * *(mat2+(*N*i+j));
         }
         *(mat3+(*N*j+i)) = dot;
       }
    }

}

