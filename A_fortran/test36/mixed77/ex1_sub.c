#include <stdlib.h>
#include <stdio.h>


float double_add_func ( double *r1, double *r2 );
void  double_add_sub ( double *r1, double *r2, double *r3 );
int  int_add_func ( int *i1, int *i2 );
void int_add_sub ( int *i1, int *i2, int *i3 );
float real_add_func ( float *r1, float *r2 );
void  real_add_sub ( float *r1, float *r2, float *r3 );

/********************************************************************/

void int_add_sub ( int *i1, int *i2, int *i3 )

/********************************************************************/
/*
  Purpose:

    INT_ADD_SUB adds two integers, returning the result as an argument.
*/
{
  printf ( "\n" );
  printf ( "INT_ADD_SUB:\n" );
  printf ( "  Input I1 = %d.\n", *i1 );
  printf ( "  Input I2 = %d.\n", *i2 );

  *i3 = *i1 + *i2;

  printf ( "  Output I3 = %d.\n", *i3 );
}
/********************************************************************/

int int_add_func ( int *i1, int *i2 )

/********************************************************************/
/*
  Purpose:

    INT_ADD_FUNC adds two integers, returning the result as a function value.
*/
{
  return ( *i1 + *i2 );
}
/********************************************************************/

void real_add_sub ( float *r1, float *r2, float *r3 )

/********************************************************************/
/*
  Purpose:

    REAL_ADD_SUB adds two real values, returning the result as an argument.
*/
{
  printf ( "\n" );
  printf ( "REAL_ADD_SUB:\n" );
  printf ( "  Input R1 = %f.\n", *r1 );
  printf ( "  Input R2 = %f.\n", *r2 );

  *r3 = *r1 + *r2;

  printf ( "  Output R3 = %f.\n", *r3 );
}
/********************************************************************/

float real_add_func ( float *r1, float *r2 )

/********************************************************************/
/*
  Purpose:

    REAL_ADD_FUNC adds two reals, returning the result as a function value.
*/
{
  return ( *r1 + *r2 );
}
/********************************************************************/

void double_add_sub ( double *r1, double *r2, double *r3 )

/********************************************************************/
/*
  Purpose:

    DOUBLE_ADD_SUB adds two double precision reals, returning the result as an argument.
*/
{
  printf ( "\n" );
  printf ( "DOUBLE_ADD_SUB:\n" );
  printf ( "  Input R1 = %f.\n", *r1 );
  printf ( "  Input R2 = %f.\n", *r2 );

  *r3 = *r1 + *r2;

  printf ( "  Output R3 = %f.\n", *r3 );
}
/********************************************************************/

float double_add_func ( double *r1, double *r2 )

/********************************************************************/
/*
  Purpose:

    DOUBLE_ADD_FUNC adds two double precision reals, returning the result as an function value.
*/
{
  return ( *r1 + *r2 );
}
