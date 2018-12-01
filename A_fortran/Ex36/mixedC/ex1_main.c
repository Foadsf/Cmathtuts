#include <stdlib.h>
#include <stdio.h>
 
/*
  Declarations of routines.
  Sometimes the FORTRAN routines need to have an underscore appended to their names.
*/
double double_add_func ( double *d1, double *d2 );
void double_add_sub ( double *d1, double *d2, double *d3 );
int int_add_func ( int *i1, int *i2 );
void int_add_sub ( int *i1, int *i2, int *i3 );
int main ( void );
float real_add_func ( float *r1, float *r2 );
void real_add_sub ( float *i1, float *i2, float *i3 );

/********************************************************************/

int main ( void )

/********************************************************************/
/*
  Purpose:

    MAIN is the main program for the C-calling-Fortran90 example.

  Modified:

    22 July 2003

  Author:

    John Burkardt
*/
{
  double d1;
  double d2;
  double d3;
  int i1;
  int i2;
  int i3;
  float r1;
  float r2;
  float r3;

  printf ( "\n" );
  printf ( "MAIN\n" );
  printf ( "\n" );
  printf ( "  Demonstrate how a C main program\n" );
  printf ( "  may call a FORTRAN subroutine, and live!\n" );
  printf ( "\n" );
  printf ( "  The C main program will now call the FORTRAN subroutine.\n" );

/*

  Here's where we call the FORTRAN routine.  

  We are passing all arguments by address, using the "&" prefix.  
  This is necessary to satisfy the expectations of the FORTRAN routine.

  The FORTRAN compiler turns the user's routine name into an internal
  symbolic name with an underscore appended.  Thus, in order for a C
  routine to find a FORTRAN routine named INT_ADD, it actually has to call
  "INT_ADD_".  Some FORTRAN compilers have an option that suppresses this
  underline appending.
*/
  printf ( "\n" );
  printf ( "MAIN:\n" );
  printf ( "  Set integers I1 and I2, then call the FORTRAN subroutine \n" );
  printf ( "  INT_ADD_SUB to compute I3 = I1 + I2.\n" );
  i1 = 42;
  i2 = 22;
  i3 = 0;
  printf ( "\n" );
  printf ( "  I1 = %d\n", i1 );
  printf ( "  I2 = %d\n", i2 );

  int_add_sub ( &i1, &i2, &i3 );

  printf ( "\n" );
  printf ( "  INT_ADD_SUB returned I3 = %d\n", i3 );

  printf ( "\n" );
  printf ( "  Now repeat, but using a FORTRAN function.\n" );

  i3 = int_add_func ( &i1, &i2 );

  printf ( "\n" );
  printf ( "  INT_ADD_FUNC returned I3 = %d\n", i3 );

  printf ( "\n" );
  printf ( "MAIN:\n" );
  printf ( "  Set floats R1 and R2, then call the FORTRAN subroutine \n" );
  printf ( "  REAL_ADD_SUB to compute R3 = R1 + R2.\n" );
  r1 = 42.0;
  r2 = 22.0;
  r3 = 0.0;

  real_add_sub ( &r1, &r2, &r3 );

  printf ( "\n" );
  printf ( "  REAL_ADD_SUB returned R3 = %f\n", r3 );

  printf ( "\n" );
  printf ( "  Now repeat, but using a FORTRAN function.\n" );

  r3 = real_add_func ( &r1, &r2 );

  printf ( "\n" );
  printf ( "  REAL_ADD_FUNC returned R3 = %f\n", r3 );

  printf ( "\n" );
  printf ( "MAIN:\n" );
  printf ( "  Set doubles D1 and D2, then call the FORTRAN subroutine \n" );
  printf ( "  DOUBLE_ADD_SUB to compute D3 = D1 + D2.\n" );
  d1 = 42.0;
  d2 = 22.0;
  d3 = 0.0;

  double_add_sub ( &d1, &d2, &d3 );

  printf ( "\n" );
  printf ( "  DOUBLE_ADD_SUB returned D3 = %f\n", d3 );

  printf ( "\n" );
  printf ( "  Now repeat, but using a FORTRAN function.\n" );

  d3 = double_add_func ( &d1, &d2 );

  printf ( "\n" );
  printf ( "  REAL_ADD_FUNC returned R3 = %f\n", d3 );

  return 0;
}
