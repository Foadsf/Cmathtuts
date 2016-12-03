# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>

# include "kronrod.h"

/******************************************************************************/

void abwe1 ( int n, int m, double eps, double coef2, int even, double b[], 
  double *x, double *w )

/******************************************************************************/
/*
  Purpose:

    ABWE1 calculates a Kronrod abscissa and weight.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 August 2010

  Author:

    Original FORTRAN77 version by Robert Piessens, Maria Branders.
    C version by John Burkardt.

  Reference:

    Robert Piessens, Maria Branders,
    A Note on the Optimal Addition of Abscissas to Quadrature Formulas
    of Gauss and Lobatto,
    Mathematics of Computation,
    Volume 28, Number 125, January 1974, pages 135-139.

  Parameters:

    Input, int N, the order of the Gauss rule.

    Input, int M, the value of ( N + 1 ) / 2.

    Input, double EPS, the requested absolute accuracy of the
    abscissas.

    Input, double COEF2, a value needed to compute weights.

    Input, int EVEN, is TRUE if N is even.

    Input, double B[M+1], the Chebyshev coefficients.

    Input/output, double *X; on input, an estimate for
    the abscissa, and on output, the computed abscissa.

    Output, double *W, the weight.
*/
{
  double ai;
  double b0;
  double b1;
  double b2;
  double d0;
  double d1;
  double d2;
  double delta;
  double dif;
  double f;
  double fd;
  int i;
  int iter;
  int k;
  int ka;
  double yy;

  if ( *x == 0.0 )
  {
    ka = 1;
  }
  else
  {
    ka = 0;
  }
/*
  Iterative process for the computation of a Kronrod abscissa.
*/
  for ( iter = 1; iter <= 50; iter++ )
  {
    b1 = 0.0;
    b2 = b[m];
    yy = 4.0 * (*x) * (*x) - 2.0;
    d1 = 0.0;

    if ( even )
    {
      ai = m + m + 1;
      d2 = ai * b[m];
      dif = 2.0;
    }
    else
    {
      ai = m + 1;
      d2 = 0.0;
      dif = 1.0;
    }

    for ( k = 1; k <= m; k++ )
    {
      ai = ai - dif;
      i = m - k + 1;
      b0 = b1;
      b1 = b2;
      d0 = d1;
      d1 = d2;
      b2 = yy * b1 - b0 + b[i-1];
      if ( !even )
      {
        i = i + 1;
      }
      d2 = yy * d1 - d0 + ai * b[i-1];
    }

    if ( even )
    {
      f = ( *x ) * ( b2 - b1 );
      fd = d2 + d1;
    }
    else
    {
      f = 0.5 * ( b2 - b0 );
      fd = 4.0 * ( *x ) * d2;
    }
/*
  Newton correction.
*/
    delta = f / fd;
    *x = *x - delta;

    if ( ka == 1 )
    {
      break;
    }

    if ( r8_abs ( delta ) <= eps )
    {
      ka = 1;
    }
  }
/*
  Catch non-convergence.
*/
  if ( ka != 1 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "ABWE1 - Fatal error!\n" );
    fprintf ( stderr, "  Iteration limit reached.\n" );
    fprintf ( stderr, "  EPS was %e\n", eps );
    fprintf ( stderr, "  Last DELTA was %e\n", delta );
    exit ( 1 );
  }
/*
  Computation of the weight.
*/
  d0 = 1.0;
  d1 = *x;
  ai = 0.0;
  for ( k = 2; k <= n; k++ )
  {
    ai = ai + 1.0;
    d2 = ( ( ai + ai + 1.0 ) * ( *x ) * d1 - ai * d0 ) / ( ai + 1.0 );
    d0 = d1;
    d1 = d2;
  }

  *w = coef2 / ( fd * d2 );

  return;
}
/******************************************************************************/

void abwe2 ( int n, int m, double eps, double coef2, int even, double b[], 
  double *x, double *w1, double *w2 )

/******************************************************************************/
/*
  Purpose:

    ABWE2 calculates a Gaussian abscissa and two weights.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 August 2010

  Author:

    Original FORTRAN77 version by Robert Piessens, Maria Branders.
    C version by John Burkardt.

  Reference:

    Robert Piessens, Maria Branders,
    A Note on the Optimal Addition of Abscissas to Quadrature Formulas
    of Gauss and Lobatto,
    Mathematics of Computation,
    Volume 28, Number 125, January 1974, pages 135-139.

  Parameters:

    Input, int N, the order of the Gauss rule.

    Input, int M, the value of ( N + 1 ) / 2.

    Input, double EPS, the requested absolute accuracy of the
    abscissas.

    Input, double COEF2, a value needed to compute weights.

    Input, int EVEN, is TRUE if N is even.

    Input, double B[M+1], the Chebyshev coefficients.

    Input/output, double *X; on input, an estimate for
    the abscissa, and on output, the computed abscissa.

    Output, double *W1, the Gauss-Kronrod weight.

    Output, double *W2, the Gauss weight.
*/
{
  double ai;
  double an;
  double delta;
  int i;
  int iter;
  int k;
  int ka;
  double p0;
  double p1;
  double p2;
  double pd0;
  double pd1;
  double pd2;
  double yy;

  if ( *x == 0.0 )
  {
    ka = 1;
  }
  else
  {
    ka = 0;
  }
/*
  Iterative process for the computation of a Gaussian abscissa.
*/
  for ( iter = 1; iter <= 50; iter++ )
  {
    p0 = 1.0;
    p1 = *x;
    pd0 = 0.0;
    pd1 = 1.0;
    ai = 0.0;
    for ( k = 2; k <= n; k++ )
    {
      ai = ai + 1.0;
      p2 = ( ( ai + ai + 1.0 ) * (*x) * p1 - ai * p0 ) / ( ai + 1.0 );
      pd2 = ( ( ai + ai + 1.0 ) * ( p1 + (*x) * pd1 ) - ai * pd0 ) 
        / ( ai + 1.0 );
      p0 = p1;
      p1 = p2;
      pd0 = pd1;
      pd1 = pd2;
    }
/*
  Newton correction.
*/
    delta = p2 / pd2;
    *x = *x - delta;

    if ( ka == 1 )
    {
      break;
    }

    if ( r8_abs ( delta ) <= eps )
    {
      ka = 1;
    }
  }
/*
  Catch non-convergence.
*/
  if ( ka != 1 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "ABWE2 - Fatal error/!\n" );
    fprintf ( stderr, "  Iteration limit reached.\n" );
    fprintf ( stderr, "  EPS was %e\n", eps );
    fprintf ( stderr, "  Last DELTA was %e\n", delta );
    exit ( 1 );
  }
/*
  Computation of the weight.
*/
  an = n;

  *w2 = 2.0 / ( an * pd2 * p0 );

  p1 = 0.0;
  p2 = b[m];
  yy = 4.0 * (*x) * (*x) - 2.0;
  for ( k = 1; k <= m; k++ )
  {
    i = m - k + 1;
    p0 = p1;
    p1 = p2;
    p2 = yy * p1 - p0 + b[i-1];
  }

  if ( even )
  {
    *w1 = *w2 + coef2 / ( pd2 * (*x) * ( p2 - p1 ) );
  }
  else
  {
    *w1 = *w2 + 2.0 * coef2 / ( pd2 * ( p2 - p0 ) );
  }

  return;
}
/******************************************************************************/

void kronrod ( int n, double eps, double x[], double w1[], double w2[] )

/******************************************************************************/
/*
  Purpose:

    KRONROD adds N+1 points to an N-point Gaussian rule.

  Discussion:

    This subroutine calculates the abscissas and weights of the 2N+1
    point Gauss Kronrod quadrature formula which is obtained from the 
    N point Gauss quadrature formula by the optimal addition of N+1 points.

    The optimally added points are called Kronrod abscissas.  The 
    abscissas and weights for both the Gauss and Gauss Kronrod rules
    are calculated for integration over the interval [-1,+1].

    Since the quadrature formula is symmetric with respect to the origin,
    only the nonnegative abscissas are calculated.

    Note that the code published in Mathematics of Computation 
    omitted the definition of the variable which is here called COEF2.

  Storage:

    Given N, let M = ( N + 1 ) / 2.  

    The Gauss-Kronrod rule will include 2*N+1 points.  However, by symmetry,
    only N + 1 of them need to be listed.

    The arrays X, W1 and W2 contain the nonnegative abscissas in decreasing
    order, and the weights of each abscissa in the Gauss-Kronrod and
    Gauss rules respectively.  This means that about half the entries
    in W2 are zero.

    For instance, if N = 3, the output is:

    I      X               W1              W2

    1    0.960491        0.104656         0.000000   
    2    0.774597        0.268488         0.555556    
    3    0.434244        0.401397         0.000000
    4    0.000000        0.450917         0.888889

    and if N = 4, (notice that 0 is now a Kronrod abscissa)
    the output is

    I      X               W1              W2

    1    0.976560        0.062977        0.000000   
    2    0.861136        0.170054        0.347855    
    3    0.640286        0.266798        0.000000   
    4    0.339981        0.326949        0.652145    
    5    0.000000        0.346443        0.000000

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 August 2010

  Author:

    Original FORTRAN77 version by Robert Piessens, Maria Branders.
    C version by John Burkardt.

  Reference:

    Robert Piessens, Maria Branders,
    A Note on the Optimal Addition of Abscissas to Quadrature Formulas
    of Gauss and Lobatto,
    Mathematics of Computation,
    Volume 28, Number 125, January 1974, pages 135-139.

  Parameters:

    Input, int N, the order of the Gauss rule.

    Input, double EPS, the requested absolute accuracy of the
    abscissas.

    Output, double X[N+1], the abscissas.

    Output, double W1[N+1], the weights for 
    the Gauss-Kronrod rule.

    Output, double W2[N+1], the weights for 
    the Gauss rule.
*/
{
  double ak;
  double an;
  double *b;
  double bb;
  double c;
  double coef;
  double coef2;
  double d;
  int even;
  int i;
  int k;
  int l;
  int ll;
  int m;
  double s;
  double *tau;
  double x1;
  double xx;
  double y;

  b = ( double * ) malloc ( (((n+1)/2)+1) * sizeof ( double ) );
  tau = ( double * ) malloc ( ( (n+1)/2 ) * sizeof ( double ) );
  
  m = ( n + 1 ) / 2;
  even = ( 2 * m == n );

  d = 2.0;
  an = 0.0;
  for ( k = 1; k <= n; k++ )
  {
    an = an + 1.0;
    d = d * an / ( an + 0.5 );
  }
/*
  Calculation of the Chebyshev coefficients of the orthogonal polynomial.
*/
  tau[0] = ( an + 2.0 ) / ( an + an + 3.0 );
  b[m-1] = tau[0] - 1.0;
  ak = an;

  for ( l = 1; l < m; l++ )
  {
    ak = ak + 2.0;
    tau[l] = ( ( ak - 1.0 ) * ak 
      - an * ( an + 1.0 ) ) * ( ak + 2.0 ) * tau[l-1] 
      / ( ak * ( ( ak + 3.0 ) * ( ak + 2.0 ) 
      - an * ( an + 1.0 ) ) );
    b[m-l-1] = tau[l];

    for ( ll = 1; ll <= l; ll++ )
    {
      b[m-l-1] = b[m-l-1] + tau[ll-1] * b[m-l+ll-1];
    }
  }

  b[m] = 1.0;
/*
  Calculation of approximate values for the abscissas.
*/
  bb = sin ( 1.570796 / ( an + an + 1.0 ) );
  x1 = sqrt ( 1.0 - bb * bb );
  s = 2.0 * bb * x1;
  c = sqrt ( 1.0 - s * s );
  coef = 1.0 - ( 1.0 - 1.0 / an ) / ( 8.0 * an * an );
  xx = coef * x1;
/*
  Coefficient needed for weights.
 
  COEF2 = 2^(2*n+1) * n * n / (2n+1)
*/
  coef2 = 2.0 / ( double ) ( 2 * n + 1 );
  for ( i = 1; i <= n; i++ )
  {
    coef2 = coef2 * 4.0 * ( double ) ( i ) / ( double ) ( n + i );
  }
/*
  Calculation of the K-th abscissa (a Kronrod abscissa) and the
  corresponding weight.
*/
  for ( k = 1; k <= n; k = k + 2 )
  {
    abwe1 ( n, m, eps, coef2, even, b, &xx, w1+k-1 );
    w2[k-1] = 0.0;

    x[k-1] = xx;
    y = x1;
    x1 = y * c - bb * s;
    bb = y * s + bb * c;

    if ( k == n )
    {
      xx = 0.0;
    }
    else
    {
      xx = coef * x1;
    }
/*
  Calculation of the K+1 abscissa (a Gaussian abscissa) and the
  corresponding weights.
*/
    abwe2 ( n, m, eps, coef2, even, b, &xx, w1+k, w2+k );

    x[k] = xx;
    y = x1;
    x1 = y * c - bb * s;
    bb = y * s + bb * c;
    xx = coef * x1;
  }
/*
  If N is even, we have one more Kronrod abscissa to compute,
  namely the origin.
*/
  if ( even )
  {
    xx = 0.0;
    abwe1 ( n, m, eps, coef2, even, b, &xx, w1+n );
    w2[n] = 0.0;
    x[n] = xx;
  }

  free ( b );
  free ( tau );

  return;
}
/******************************************************************************/

double r8_abs ( double x )

/******************************************************************************/
/*
  Purpose:

    R8_ABS returns the absolute value of an R8.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 November 2006

  Author:

    John Burkardt

  Parameters:

    Input, double X, the quantity whose absolute value is desired.

    Output, double R8_ABS, the absolute value of X.
*/
{
  double value;

  if ( 0.0 <= x )
  {
    value = x;
  } 
  else
  {
    value = - x;
  }
  return value;
}
/******************************************************************************/

void timestamp ( void )

/******************************************************************************/
/*
  Purpose:

    TIMESTAMP prints the current YMDHMS date as a time stamp.

  Example:

    31 May 2001 09:45:54 AM

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    24 September 2003

  Author:

    John Burkardt

  Parameters:

    None
*/
{
# define TIME_SIZE 40

  static char time_buffer[TIME_SIZE];
  const struct tm *tm;
  size_t len;
  time_t now;

  now = time ( NULL );
  tm = localtime ( &now );

  len = strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm );

  printf ( "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}
