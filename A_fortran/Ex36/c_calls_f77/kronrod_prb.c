# include <stdlib.h>
# include <stdio.h>
# include <math.h>

int main ( void );
void test01 ( void );
void test02 ( void );
/*
  Interfaces to FORTRAN77 routines.
  The names now have underscores appended, and
  scalar parameters are passed by reference.
*/
extern void kronrod_ ( int *n, double *eps, double x[], double w1[],
  double w2[], int *ier );
extern void timestamp_ ( void );

/******************************************************************************/

int main ( void )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for KRONROD_PRB.

  Discussion:

    KRONROD_PRB tests the KRONROD library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 December 2010

  Author:

    John Burkardt
*/
{
/*
  To call the F77 version of TIMESTAMP, we append an underscore to its name.
*/
  timestamp_ ( );

  printf ( "\n" );
  printf ( "KRONROD_PRB:\n" );
  printf ( "  C + F77 version.\n" );
  printf ( "  The main program is in C, the library is in FORTRAN77.\n" );
  printf ( "  This is an example of how a C program calls a FORTRAN77 routine.\n" );
  test01 ( );
  test02 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "KRONROD_PRB:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp_ ( );

  return 0;
}
/******************************************************************************/

void test01 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST01 tests the code for the odd case N = 3.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 December 2010

  Author:

    John Burkardt
*/
{
  double *b;
  double eps;
  int i;
  int i2;
  int ier;
  int n = 3;
  double s;
  double *tau;
  double *w1;
  double *w2;
  double wg[3] = {
    0.555555555555555555556,
    0.888888888888888888889,
    0.555555555555555555556 };
  double wk[7] = {
    0.104656226026467265194,
    0.268488089868333440729,
    0.401397414775962222905,
    0.450916538658474142345,
    0.401397414775962222905,
    0.268488089868333440729,
    0.104656226026467265194 };
  double *x;
  double xg[3] = {
   -0.77459666924148337704,
    0.0,
    0.77459666924148337704 };
  double xk[7]= {
   -0.96049126870802028342,
   -0.77459666924148337704,
   -0.43424374934680255800,
    0.0,
    0.43424374934680255800,
    0.77459666924148337704,
    0.96049126870802028342 };

  printf ( "\n" );
  printf ( "TEST01\n" );
  printf ( "  Request KRONROD to compute the Gauss rule\n" );
  printf ( "  of order 3, and the Kronrod extension of\n" );
  printf ( "  order 3+4=7.\n" );
  printf ( "\n" );
  printf ( "  Compare to exact data.\n" );

  eps = 0.000001;
  w1 = ( double * ) malloc ( ( n + 1 ) * sizeof ( double ) );
  w2 = ( double * ) malloc ( ( n + 1 ) * sizeof ( double ) );
  x = ( double * ) malloc ( ( n + 1 ) * sizeof ( double ) );
  b = ( double * ) malloc ( ( ( ( n + 1 ) / 2 ) + 1 ) * sizeof ( double ) );
  tau = ( double * ) malloc ( ( ( n + 1 ) / 2 ) * sizeof ( double ) );
/*
  To call the FORTRAN77 subroutine KRONROD, we must append
  an underscore to the name, and pass scalars by reference.
*/
  kronrod_ ( &n, &eps, x, w1, w2, &ier );

  printf ( "\n" );
  printf ( "  KRONROD returns 3 vectors of length %d\n", n + 1 );
  printf ( "\n" );
  printf ( "     I      X               WK              WG\n" );
  printf ( "\n" );
  for ( i = 1; i <= n + 1; i++ )
  {
    printf ( "  %4d  %14f  %14f  %14f\n", i, x[i-1], w1[i-1], w2[i-1] );
  }

  printf ( "\n" );
  printf ( "               Gauss Abscissas\n" );
  printf ( "            Exact           Computed\n" );
  printf ( "\n" );
  for ( i = 1; i <= n; i++ )
  {
    if ( 2 * i <= n + 1 )
    {
      i2 = 2 * i;
      s = -1.0;
    }
    else
    {
      i2 = 2 * ( n + 1 ) - 2 * i;
      s = +1.0;
    }
    printf ( "  %4d  %14f  %14f\n", i, xg[i-1], s * x[i2-1] );
  }
  printf ( "\n" );
  printf ( "               Gauss Weights\n" );
  printf ( "            Exact           Computed\n" );
  printf ( "\n" );
  for ( i = 1; i <= n; i++ )
  {
    if ( 2 * i <= n + 1 )
    {
      i2 = 2 * i;
    }
    else
    {
      i2 = 2 * ( n + 1 ) - 2 * i;
    }
    printf ( "  %4d  %14f  %14f\n", i, wg[i-1], w2[i2-1] );
  }

  printf ( "\n" );
  printf ( "             Gauss Kronrod Abscissas\n" );
  printf ( "            Exact           Computed\n" );
  printf ( "\n" );
  for ( i = 1; i <= 2 * n + 1; i++ )
  {
    if ( i <= n + 1 )
    {
      i2 = i;
      s = -1.0;
    }
    else
    {
      i2 = 2 * ( n + 1 ) - i;
      s = +1.0;
    }
    printf ( "  %4d  %14f  %14f\n", i, xk[i-1], s * x[i2-1] );
  }
  printf ( "\n" );
  printf ( "             Gauss Kronrod Weights\n" );
  printf ( "            Exact           Computed\n" );
  printf ( "\n" );
  for ( i = 1; i <= 2 * n + 1; i++ )
  {
    if ( i <= n + 1 )
    {
      i2 = i;
    }
    else
    {
      i2 = 2 * ( n + 1 ) - i;
    }
    printf ( "  %4d  %14f  %14f\n", i, wk[i-1], w1[i2-1] );
  }

  free ( b );
  free ( tau );
  free ( w1 );
  free ( w2 );
  free ( x );

  return;
}
/******************************************************************************/

void test02 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST02 tests the code for the even case N = 4.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 December 2010

  Author:

    John Burkardt
*/
{
  double *b;
  double eps;
  int i;
  int i2;
  int ier;
  int m;
  int n = 4;
  double s;
  double *tau;
  double *w1;
  double *w2;
  double *x;

  printf ( "\n" );
  printf ( "TEST02\n" );
  printf ( "  Request KRONROD to compute the Gauss rule\n" );
  printf ( "  of order 4, and the Kronrod extension of\n" );
  printf ( "  order 4+5=9.\n" );

  m = ( n + 1 ) / 2;
  eps = 0.000001;
  w1 =  ( double * ) malloc (     ( n + 1 )             * sizeof ( double ) );
  w2 =  ( double * ) malloc (     ( n + 1 )             * sizeof ( double ) );
  x =   ( double * ) malloc (     ( n + 1 )             * sizeof ( double ) );
  b =   ( double * ) malloc ( ( m + 1 ) * sizeof ( double ) );
  tau = ( double * ) malloc (   m      * sizeof ( double ) );
/*
  To call the FORTRAN77 subroutine KRONROD, we must append
  an underscore to the name, and pass scalars by reference.
*/
  kronrod_ ( &n, &eps, x, w1, w2, &ier );

  printf ( "\n" );
  printf ( "  KRONROD returns 3 vectors of length %d\n", n + 1 );
  printf ( "\n" );
  printf ( "     I      X               WK              WG\n" );
  printf ( "\n" );
  for ( i = 1; i <= n + 1; i++ )
  {
    printf ( "  %4d  %14f  %14f  %14f\n", i, x[i-1], w1[i-1], w2[i-1] );
  }

  free ( b );
  free ( tau );
  free ( w1 );
  free ( w2 );
  free ( x );

  return;
}
