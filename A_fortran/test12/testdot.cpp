
extern "C" {
    float testdot_( int *N, float *vec1, float *vec2);
    }


float testdot_(  int *N, float *vec1, float *vec2 ) 
{
    int i;
    float dot;

    dot = 0.0;

    for (i=0; i<*N; i++) { 
      dot = dot + *(vec1+i) * *(vec2+i);
      }
    return dot;
}

