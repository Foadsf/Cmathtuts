subroutine kronrod ( n, eps, x, w1, w2 )

!*****************************************************************************80
!
!! KRONROD adds N+1 points to an N-point Gaussian rule.
!
!  Discussion:
!
!    This subroutine calculates the abscissas and weights of the 2N+1
!    point Gauss Kronrod quadrature formula which is obtained from the 
!    N point Gauss quadrature formula by the optimal addition of N+1 points.
!
!    The optimally added points are called Kronrod abscissas.  The 
!    abscissas and weights for both the Gauss and Gauss Kronrod rules
!    are calculated for integration over the interval [-1,+1].
!
!    Since the quadrature formula is symmetric with respect to the origin,
!    only the nonnegative abscissas are calculated.
!
!    Note that the code published in Mathematics of Computation 
!    omitted the definition of the variable which is here called COEF2.
!
!  Storage:
!
!    Given N, let M = ( N + 1 ) / 2.  
!
!    The Gauss-Kronrod rule will include 2*N+1 points.  However, by symmetry,
!    only N + 1 of them need to be listed.
!
!    The arrays X, W1 and W2 contain the nonnegative abscissas in decreasing
!    order, and the weights of each abscissa in the Gauss-Kronrod and
!    Gauss rules respectively.  This means that about half the entries
!    in W2 are zero.
!
!    For instance, if N = 3, the output is:
!
!    I      X               W1              W2
!
!    1    0.960491        0.104656         0.000000   
!    2    0.774597        0.268488         0.555556    
!    3    0.434244        0.401397         0.000000
!    4    0.000000        0.450917         0.888889
!
!    and if N = 4, (notice that 0 is now a Kronrod abscissa)
!    the output is
!
!    I      X               W1              W2
!
!    1    0.976560        0.062977        0.000000   
!    2    0.861136        0.170054        0.347855    
!    3    0.640286        0.266798        0.000000   
!    4    0.339981        0.326949        0.652145    
!    5    0.000000        0.346443        0.000000
!
!  Licensing:
!
!    This code is distributed under the GNU LGPL license.
!
!  Modified:
!
!    03 August 2010
!
!  Author:
!
!    Original FORTRAN77 version by Robert Piessens, Maria Branders.
!    FORTRAN90 version by John Burkardt.
!
!  Reference:
!
!    Robert Piessens, Maria Branders,
!    A Note on the Optimal Addition of Abscissas to Quadrature Formulas
!    of Gauss and Lobatto,
!    Mathematics of Computation,
!    Volume 28, Number 125, January 1974, pages 135-139.
!
!  Parameters:
!
!    Input, integer ( kind = 4 ) N, the order of the Gauss rule.
!
!    Input, real ( kind = 8 ) EPS, the requested absolute accuracy of the
!    abscissas.
!
!    Output, real ( kind = 8 ) X(N+1), the abscissas.
!
!    Output, real ( kind = 8 ) W1(N+1), the weights for 
!    the Gauss-Kronrod rule.
!
!    Output, real ( kind = 8 ) W2(N+1), the weights for 
!    the Gauss rule.
!
  implicit none

  integer ( kind = 4 ) n

  real    ( kind = 8 ) ak
  real    ( kind = 8 ) an
  real    ( kind = 8 ) b(((n+1)/2)+1)
  real    ( kind = 8 ) bb
  real    ( kind = 8 ) c
  real    ( kind = 8 ) coef
  real    ( kind = 8 ) coef2
  real    ( kind = 8 ) d
  real    ( kind = 8 ) eps
  logical              even
  integer ( kind = 4 ) i
  integer ( kind = 4 ) k
  integer ( kind = 4 ) l
  integer ( kind = 4 ) ll
  integer ( kind = 4 ) m
  real    ( kind = 8 ) s
  real    ( kind = 8 ) tau(( n + 1 ) / 2 )
  real    ( kind = 8 ) w1(n+1)
  real    ( kind = 8 ) w2(n+1)
  real    ( kind = 8 ) x(n+1)
  real    ( kind = 8 ) x1
  real    ( kind = 8 ) xx
  real    ( kind = 8 ) y

  m = ( n + 1 ) / 2
  even = ( 2 * m == n )

  d = 2.0D+00
  an = 0.0D+00
  do k = 1, n
    an = an + 1.0D+00
    d = d * an / ( an + 0.5D+00 )
  end do
!
!  Calculation of the Chebyshev coefficients of the orthogonal polynomial.
!
  tau(1) = ( an + 2.0D+00 ) / ( an + an + 3.0D+00 )
  b(m) = tau(1) - 1.0D+00
  ak = an

  do l = 1, m - 1

    ak = ak + 2.0D+00
    tau(l+1) = ( ( ak - 1.0D+00 ) * ak &
      - an * ( an + 1.0D+00 ) ) * ( ak + 2.0D+00 ) * tau(l) &
      / ( ak * ( ( ak + 3.0D+00 ) * ( ak + 2.0D+00 ) &
      - an * ( an + 1.0D+00 ) ) )
    b(m-l) = tau(l+1)

    do ll = 1, l
      b(m-l) = b(m-l) + tau(ll) * b(m-l+ll)
    end do

  end do

  b(m+1) = 1.0D+00
!
!  Calculation of approximate values for the abscissas.
!
  bb = sin ( 1.570796D+00 / ( an + an + 1.0D+00 ) )
  x1 = sqrt ( 1.0D+00 - bb * bb )
  s = 2.0D+00 * bb * x1
  c = sqrt ( 1.0D+00 - s * s )
  coef = 1.0D+00 - ( 1.0D+00 - 1.0D+00 / an ) / ( 8.0D+00 * an * an )
  xx = coef * x1
!
!  Coefficient needed for weights.
!
!  COEF2 = 2^(2*n+1) * n! * n! / (2n+1)!
!
  coef2 = 2.0D+00 / real ( 2 * n + 1, kind = 8 )
  do i = 1, n
    coef2 = coef2 * 4.0D+00 * real ( i, kind = 8 ) / real ( n + i, kind = 8 )
  end do
!
!  Calculation of the K-th abscissa (a Kronrod abscissa) and the
!  corresponding weight.
!
  do k = 1, n, 2

    call abwe1 ( n, m, eps, coef2, even, b, xx, w1(k) )
    w2(k) = 0.0D+00

    x(k) = xx
    y = x1
    x1 = y * c - bb * s
    bb = y * s + bb * c

    if ( k == n ) then
      xx = 0.0D+00
    else
      xx = coef * x1
    end if
!
!  Calculation of the K+1 abscissa (a Gaussian abscissa) and the
!  corresponding weights.
!
    call abwe2 ( n, m, eps, coef2, even, b, xx, w1(k+1), w2(k+1) )

    x(k+1) = xx
    y = x1
    x1 = y * c - bb * s
    bb = y * s + bb * c
    xx = coef * x1

  end do
!
!  If N is even, we have one more Kronrod abscissa to compute,
!  namely the origin.
!
  if ( even ) then
    xx = 0.0D+00
    call abwe1 ( n, m, eps, coef2, even, b, xx, w1(n+1) )
    w2(n+1) = 0.0D+00
    x(n+1) = xx
  end if

  return
end
subroutine abwe1 ( n, m, eps, coef2, even, b, x, w )

!*****************************************************************************80
!
!! ABWE1 calculates a Kronrod abscissa and weight.
!
!  Licensing:
!
!    This code is distributed under the GNU LGPL license.
!
!  Modified:
!
!    03 August 2010
!
!  Author:
!
!    Original FORTRAN77 version by Robert Piessens, Maria Branders.
!    FORTRAN90 version by John Burkardt.
!
!  Reference:
!
!    Robert Piessens, Maria Branders,
!    A Note on the Optimal Addition of Abscissas to Quadrature Formulas
!    of Gauss and Lobatto,
!    Mathematics of Computation,
!    Volume 28, Number 125, January 1974, pages 135-139.
!
!  Parameters:
!
!    Input, integer ( kind = 4 ) N, the order of the Gauss rule.
!
!    Input, integer ( kind = 4 ) M, the value of ( N + 1 ) / 2.
!
!    Input, real ( kind = 8 ) EPS, the requested absolute accuracy of the
!    abscissas.
!
!    Input, real ( kind = 8 ) COEF2, a value needed to compute weights.
!
!    Input, logical EVEN, is TRUE if N is even.
!
!    Input, real ( kind = 8 ) B(M+1), the Chebyshev coefficients.
!
!    Input/output, real ( kind = 8 ) X; on input, an estimate for
!    the abscissa, and on output, the computed abscissa.
!
!    Output, real ( kind = 8 ) W, the weight.
!
  implicit none

  integer ( kind = 4 ) m

  real    ( kind = 8 ) ai
  real    ( kind = 8 ) b(m+1)
  real    ( kind = 8 ) b0
  real    ( kind = 8 ) b1
  real    ( kind = 8 ) b2
  real    ( kind = 8 ) coef2
  real    ( kind = 8 ) d0
  real    ( kind = 8 ) d1
  real    ( kind = 8 ) d2
  real    ( kind = 8 ) delta
  real    ( kind = 8 ) dif
  real    ( kind = 8 ) eps
  logical              even
  real    ( kind = 8 ) f
  real    ( kind = 8 ) fd
  integer ( kind = 4 ) i
  integer ( kind = 4 ) iter
  integer ( kind = 4 ) k
  integer ( kind = 4 ) ka
  integer ( kind = 4 ) n
  real    ( kind = 8 ) w
  real    ( kind = 8 ) x
  real    ( kind = 8 ) yy

  if ( x == 0.0D+00 ) then
    ka = 1
  else
    ka = 0
  end if
!
!  Iterative process for the computation of a Kronrod abscissa.
!
  do iter = 1, 50

    b1 = 0.0D+00
    b2 = b(m+1)
    yy = 4.0D+00 * x * x - 2.0D+00
    d1 = 0.0D+00

    if ( even ) then
      ai = m + m + 1
      d2 = ai * b(m+1)
      dif = 2.0D+00
    else
      ai = m + 1
      d2 = 0.0D+00
      dif = 1.0D+00
    end if

    do k = 1, m
      ai = ai - dif
      i = m - k + 1
      b0 = b1
      b1 = b2
      d0 = d1
      d1 = d2
      b2 = yy * b1 - b0 + b(i)
      if ( .not. even ) then
        i = i + 1
      end if
      d2 = yy * d1 - d0 + ai * b(i)
    end do

    if ( even ) then
      f = x * ( b2 - b1 )
      fd = d2 + d1
    else
      f = 0.5D+00 * ( b2 - b0 )
      fd = 4.0D+00 * x * d2
    end if
!
!  Newton correction.
!
    delta = f / fd
    x = x - delta

    if ( ka == 1 ) then
      exit
    end if

    if ( abs ( delta ) <= eps ) then
      ka = 1
    end if

  end do
!
!  Catch non-convergence.
!
  if ( ka /= 1 ) then
    write ( *, '(a)' ) ' '
    write ( *, '(a)' ) 'ABWE1 - Fatal error!'
    write ( *, '(a)' ) '  Iteration limit reached.'
    write ( *, '(a,g14.6)' ) '  EPS is ', eps
    write ( *, '(a,g14.6)' ) '  Last DELTA was ', delta
    stop
  end if
!
!  Computation of the weight.
!
  d0 = 1.0D+00
  d1 = x
  ai = 0.0D+00
  do k = 2, n
    ai = ai + 1.0D+00
    d2 = ( ( ai + ai + 1.0D+00 ) * x * d1 - ai * d0 ) / ( ai + 1.0D+00 )
    d0 = d1
    d1 = d2
  end do

  w = coef2 / ( fd * d2 )

  return
end
subroutine abwe2 ( n, m, eps, coef2, even, b, x, w1, w2 )

!*****************************************************************************80
!
!! ABWE2 calculates a Gaussian abscissa and two weights.
!
!  Licensing:
!
!    This code is distributed under the GNU LGPL license.
!
!  Modified:
!
!    03 August 2010
!
!  Author:
!
!    Original FORTRAN77 version by Robert Piessens, Maria Branders.
!    FORTRAN90 version by John Burkardt.
!
!  Reference:
!
!    Robert Piessens, Maria Branders,
!    A Note on the Optimal Addition of Abscissas to Quadrature Formulas
!    of Gauss and Lobatto,
!    Mathematics of Computation,
!    Volume 28, Number 125, January 1974, pages 135-139.
!
!  Parameters:
!
!    Input, integer ( kind = 4 ) N, the order of the Gauss rule.
!
!    Input, integer ( kind = 4 ) M, the value of ( N + 1 ) / 2.
!
!    Input, real ( kind = 8 ) EPS, the requested absolute accuracy of the
!    abscissas.
!
!    Input, real ( kind = 8 ) COEF2, a value needed to compute weights.
!
!    Input, logical EVEN, is TRUE if N is even.
!
!    Input, real ( kind = 8 ) B(M+1), the Chebyshev coefficients.
!
!    Input/output, real ( kind = 8 ) X; on input, an estimate for
!    the abscissa, and on output, the computed abscissa.
!
!    Output, real ( kind = 8 ) W1, the Gauss-Kronrod weight.
!
!    Output, real ( kind = 8 ) W2, the Gauss weight.
!
  implicit none

  integer ( kind = 4 ) m

  real    ( kind = 8 ) ai
  real    ( kind = 8 ) an
  real    ( kind = 8 ) b(m+1)
  real    ( kind = 8 ) coef2
  real    ( kind = 8 ) delta
  real    ( kind = 8 ) eps
  logical              even
  integer ( kind = 4 ) i
  integer ( kind = 4 ) iter
  integer ( kind = 4 ) k
  integer ( kind = 4 ) ka
  integer ( kind = 4 ) n
  real    ( kind = 8 ) p0
  real    ( kind = 8 ) p1
  real    ( kind = 8 ) p2
  real    ( kind = 8 ) pd0
  real    ( kind = 8 ) pd1
  real    ( kind = 8 ) pd2
  real    ( kind = 8 ) w1
  real    ( kind = 8 ) w2
  real    ( kind = 8 ) x
  real    ( kind = 8 ) yy

  if ( x == 0.0D+00 ) then
    ka = 1
  else
    ka = 0
  end if
!
!  Iterative process for the computation of a Gaussian abscissa.
!
  do iter = 1, 50

    p0 = 1.0D+00
    p1 = x
    pd0 = 0.0D+00
    pd1 = 1.0D+00
    ai = 0.0D+00
    do k = 2, n
      ai = ai + 1.0D+00
      p2 = ( ( ai + ai + 1.0D+00 ) * x * p1 - ai * p0 ) / ( ai + 1.0D+00 )
      pd2 = ( ( ai + ai + 1.0D+00 ) * ( p1 + x * pd1 ) - ai * pd0 ) &
        / ( ai + 1.0D+00 )
      p0 = p1
      p1 = p2
      pd0 = pd1
      pd1 = pd2
    end do
!
!  Newton correction.
!
    delta = p2 / pd2
    x = x - delta

    if ( ka == 1 ) then
      exit
    end if

    if ( abs ( delta ) <= eps ) then
      ka = 1
    end if

  end do
!
!  Catch non-convergence.
!
  if ( ka /= 1 ) then
    write ( *, '(a)' ) ' '
    write ( *, '(a)' ) 'ABWE2 - Fatal error!'
    write ( *, '(a)' ) '  Iteration limit reached.'
    write ( *, '(a,g14.6)' ) '  EPS is ', eps
    write ( *, '(a,g14.6)' ) '  Last DELTA was ', delta
    stop
  end if
!
!  Computation of the weight.
!
  an = n

  w2 = 2.0D+00 / ( an * pd2 * p0 )

  p1 = 0.0D+00
  p2 = b(m+1)
  yy = 4.0D+00 * x * x - 2.0D+00
  do k = 1, m
    i = m - k + 1
    p0 = p1
    p1 = p2
    p2 = yy * p1 - p0 + b(i)
  end do

  if ( even ) then
    w1 = w2 + coef2 / ( pd2 * x * ( p2 - p1 ) )
  else
    w1 = w2 + 2.0D+00 * coef2 / ( pd2 * ( p2 - p0 ) )
  end if

  return
end
subroutine timestamp ( )

!*****************************************************************************80
!
!! TIMESTAMP prints the current YMDHMS date as a time stamp.
!
!  Example:
!
!    31 May 2001   9:45:54.872 AM
!
!  Licensing:
!
!    This code is distributed under the GNU LGPL license.
!
!  Modified:
!
!    06 August 2005
!
!  Author:
!
!    John Burkardt
!
!  Parameters:
!
!    None
!
  implicit none

  character ( len = 8  ) ampm
  integer   ( kind = 4 ) d
  integer   ( kind = 4 ) h
  integer   ( kind = 4 ) m
  integer   ( kind = 4 ) mm
  character ( len = 9  ), parameter, dimension(12) :: month = (/ &
    'January  ', 'February ', 'March    ', 'April    ', &
    'May      ', 'June     ', 'July     ', 'August   ', &
    'September', 'October  ', 'November ', 'December ' /)
  integer   ( kind = 4 ) n
  integer   ( kind = 4 ) s
  integer   ( kind = 4 ) values(8)
  integer   ( kind = 4 ) y

  call date_and_time ( values = values )

  y = values(1)
  m = values(2)
  d = values(3)
  h = values(5)
  n = values(6)
  s = values(7)
  mm = values(8)

  if ( h < 12 ) then
    ampm = 'AM'
  else if ( h == 12 ) then
    if ( n == 0 .and. s == 0 ) then
      ampm = 'Noon'
    else
      ampm = 'PM'
    end if
  else
    h = h - 12
    if ( h < 12 ) then
      ampm = 'PM'
    else if ( h == 12 ) then
      if ( n == 0 .and. s == 0 ) then
        ampm = 'Midnight'
      else
        ampm = 'AM'
      end if
    end if
  end if

  write ( *, '(i2,1x,a,1x,i4,2x,i2,a1,i2.2,a1,i2.2,a1,i3.3,1x,a)' ) &
    d, trim ( month(m) ), y, h, ':', n, ':', s, '.', mm, trim ( ampm )

  return
end
