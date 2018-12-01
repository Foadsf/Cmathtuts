      subroutine kronrod ( n, eps, x, w1, w2, ier )

c*********************************************************************72
c
cc KRONROD adds N+1 points to an N-point Gaussian rule.
c
c  Discussion:
c
c    This subroutine calculates the abscissas and weights of the 2N+1
c    point Gauss Kronrod quadrature formula which is obtained from the
c    N point Gauss quadrature formula by the optimal addition of N+1 points.
c
c    The optimally added points are called Kronrod abscissas.  The
c    abscissas and weights for both the Gauss and Gauss Kronrod rules
c    are calculated for integration over the interval [-1,+1].
c
c    Since the quadrature formula is symmetric with respect to the origin,
c    only the nonnegative abscissas are calculated.
c
c    Note that the code published in Mathematics of Computation
c    omitted the definition of the variable which is here called COEF2.
c
c  Storage:
c
c    Given N, let M = ( N + 1 ) / 2.
c
c    The Gauss-Kronrod rule will include 2*N+1 points.  However, by symmetry,
c    only N + 1 of them need to be listed.
c
c    The arrays X, W1 and W2 contain the nonnegative abscissas in decreasing
c    order, and the weights of each abscissa in the Gauss-Kronrod and
c    Gauss rules respectively.  This means that about half the entries
c    in W2 are zero.
c
c    For instance, if N = 3, the output is:
c
c    I      X               W1              W2
c
c    1    0.960491        0.104656         0.000000
c    2    0.774597        0.268488         0.555556
c    3    0.434244        0.401397         0.000000
c    4    0.000000        0.450917         0.888889
c
c    and if N = 4, (notice that 0 is now a Kronrod abscissa)
c    the output is
c
c    I      X               W1              W2
c
c    1    0.976560        0.062977        0.000000
c    2    0.861136        0.170054        0.347855
c    3    0.640286        0.266798        0.000000
c    4    0.339981        0.326949        0.652145
c    5    0.000000        0.346443        0.000000
c
c  Licensing:
c
c    This code is distributed under the GNU LGPL license.
c
c  Modified:
c
c    02 August 2010
c
c  Author:
c
c    Original FORTRAN77 version by Robert Piessens, Maria Branders.
c    This FORTRAN77 version by John Burkardt.
c
c  Reference:
c
c    Robert Piessens, Maria Branders,
c    A Note on the Optimal Addition of Abscissas to Quadrature Formulas
c    of Gauss and Lobatto,
c    Mathematics of Computation,
c    Volume 28, Number 125, January 1974, pages 135-139.
c
c  Parameters:
c
c    Input, integer N, the order of the Gauss rule.
c
c    Input, double precision EPS, the requested absolute accuracy of the
c    abscissas.
c
c    Output, double precision X(N+1), the abscissas.
c
c    Output, double precision W1(N+1), the weights for
c    the Gauss-Kronrod rule.
c
c    Output, double precision W2(N+1), the weights for
c    the Gauss rule.
c
c    Output, integer IER, an error flag.
c    0, no error occurred.
c    1, an error occurred.
c
      implicit none

      integer n

      double precision ak
      double precision an
      double precision b(((n+1)/2)+1)
      double precision bb
      double precision c
      double precision coef
      double precision coef2
      double precision d
      double precision eps
      logical even
      integer i
      integer ier
      integer k
      integer l
      integer ll
      integer m
      double precision s
      double precision tau(( n + 1 ) / 2 )
      double precision w1(n+1)
      double precision w2(n+1)
      double precision x(n+1)
      double precision x1
      double precision xx
      double precision y

      ier = 0
      m = ( n + 1 ) / 2
      even = ( 2 * m .eq. n )

      d = 2.0D+00
      an = 0.0D+00
      do k = 1, n
        an = an + 1.0D+00
        d = d * an / ( an + 0.5D+00 )
      end do
c
c  Calculation of the Chebyshev coefficients of the orthogonal polynomial.
c
      tau(1) = ( an + 2.0D+00 ) / ( an + an + 3.0D+00 )
      b(m) = tau(1) - 1.0D+00
      ak = an

      do l = 1, m - 1

        ak = ak + 2.0D+00
        tau(l+1) = ( ( ak - 1.0D+00 ) * ak
     &    - an * ( an + 1.0D+00 ) ) * ( ak + 2.0D+00 ) * tau(l)
     &    / ( ak * ( ( ak + 3.0D+00 ) * ( ak + 2.0D+00 )
     &    - an * ( an + 1.0D+00 ) ) )
        b(m-l) = tau(l+1)

        do ll = 1, l
          b(m-l) = b(m-l) + tau(ll) * b(m-l+ll)
        end do

      end do

      b(m+1) = 1.0D+00
c
c  Calculation of approximate values for the abscissas.
c
      bb = sin ( 1.570796D+00 / ( an + an + 1.0D+00 ) )
      x1 = sqrt ( 1.0D+00 - bb * bb )
      s = 2.0D+00 * bb * x1
      c = sqrt ( 1.0D+00 - s * s )
      coef = 1.0D+00 - ( 1.0D+00 - 1.0D+00 / an )
     &  / ( 8.0D+00 * an * an )
      xx = coef * x1
c
c  Coefficient needed for weights.
c
c  COEF2 = 2^(2*n+1) * n! * n! / (2n+1)!
c
      coef2 = 2.0D+00 / dble ( 2 * n + 1 )
      do i = 1, n
        coef2 = coef2 * 4.0D+00 * dble ( i ) / dble ( n + i )
      end do
c
c  Calculation of the K-th abscissa (a Kronrod abscissa) and the
c  corresponding weight.
c
      do k = 1, n, 2

        call abwe1 ( n, m, eps, coef2, even, b, xx, w1(k), ier )
        w2(k) = 0.0D+00

        if ( ier .eq. 1 ) then
          return
        end if

        x(k) = xx
        y = x1
        x1 = y * c - bb * s
        bb = y * s + bb * c

        if ( k .eq. n ) then
          xx = 0.0D+00
        else
          xx = coef * x1
        end if
c
c  Calculation of the K+1 abscissa (a Gaussian abscissa) and the
c  corresponding weights.
c
        call abwe2 ( n, m, eps, coef2, even, b, xx, w1(k+1),
     &    w2(k+1), ier )

        if ( ier .eq. 1 ) then
          return
        end if

        x(k+1) = xx
        y = x1
        x1 = y * c - bb * s
        bb = y * s + bb * c
        xx = coef * x1

      end do
c
c  If N is even, we have one more Kronrod abscissa to compute,
c  namely the origin.
c
      if ( even ) then
        xx = 0.0D+00
        call abwe1 ( n, m, eps, coef2, even, b, xx, w1(n+1), ier )
        w2(n+1) = 0.0D+00
        x(n+1) = xx
      end if

      return
      end
      subroutine abwe1 ( n, m, eps, coef2, even, b, x, w, ier )

c*********************************************************************72
c
cc ABWE1 calculates a Kronrod abscissa and weight.
c
c  Licensing:
c
c    This code is distributed under the GNU LGPL license.
c
c  Modified:
c
c    02 August 2010
c
c  Author:
c
c    Original FORTRAN77 version by Robert Piessens, Maria Branders.
c    This FORTRAN77 version by John Burkardt.
c
c  Reference:
c
c    Robert Piessens, Maria Branders,
c    A Note on the Optimal Addition of Abscissas to Quadrature Formulas
c    of Gauss and Lobatto,
c    Mathematics of Computation,
c    Volume 28, Number 125, January 1974, pages 135-139.
c
c  Parameters:
c
c    Input, integer N, the order of the Gauss rule.
c
c    Input, integer M, the value of ( N + 1 ) / 2.
c
c    Input, double precision EPS, the requested absolute accuracy of the
c    abscissas.
c
c    Input, double precision COEF2, a value needed to compute weights.
c
c    Input, logical EVEN, is TRUE if N is even.
c
c    Input, double precision B(M+1), the Chebyshev coefficients.
c
c    Input/output, double precision X; on input, an estimate for
c    the abscissa, and on output, the computed abscissa.
c
c    Output, double precision W, the weight.
c
c    Output, integer IER, error flag.
c    0, no error occurred.
c    1, an error occurred.
c
      implicit none

      integer m

      double precision ai
      double precision b(m+1)
      double precision b0
      double precision b1
      double precision b2
      double precision coef2
      double precision d0
      double precision d1
      double precision d2
      double precision delta
      double precision dif
      double precision eps
      logical even
      double precision f
      double precision fd
      integer i
      integer ier
      integer iter
      integer k
      integer ka
      integer n
      double precision w
      double precision x
      double precision yy

      iter = 0

      if ( x .eq. 0.0D+00 ) then
        ka = 1
      else
        ka = 0
      end if
c
c  Iterative process for the computation of a Kronrod abscissa.
c
10    continue

      iter = iter + 1

      if ( 50 < iter ) then
        ier = 1
        write ( *, '(a)' ) ' '
        write ( *, '(a)' ) 'ABWE1 - Fatal error!'
        write ( *, '(a)' ) '  Iteration limit reached.'
        write ( *, '(a,g14.6)' ) '  Last DELTA was ', delta
        return
      end if

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
c
c  Newton correction.
c
      delta = f / fd
      x = x - delta

      if ( ka .ne. 1 ) then
        if ( abs ( delta ) .le. eps ) then
          ka = 1
        end if
        go to 10
      end if
c
c  Computation of the weight.
c
      d0 = 1.0D+00
      d1 = x
      ai = 0.0D+00
      do k = 2, n
        ai = ai + 1.0D+00
        d2 = ( ( ai + ai + 1.0D+00 ) * x * d1 - ai * d0 )
     &    / ( ai + 1.0D+00 )
        d0 = d1
        d1 = d2
      end do

      w = coef2 / ( fd * d2 )

      return
      end
      subroutine abwe2 ( n, m, eps, coef2, even, b, x, w1, w2, ier )

c*********************************************************************72
c
cc ABWE2 calculates a Gaussian abscissa and two weights.
c
c  Licensing:
c
c    This code is distributed under the GNU LGPL license.
c
c  Modified:
c
c    02 August 2010
c
c  Author:
c
c    Original FORTRAN77 version by Robert Piessens, Maria Branders.
c    This FORTRAN77 version by John Burkardt.
c
c  Reference:
c
c    Robert Piessens, Maria Branders,
c    A Note on the Optimal Addition of Abscissas to Quadrature Formulas
c    of Gauss and Lobatto,
c    Mathematics of Computation,
c    Volume 28, Number 125, January 1974, pages 135-139.
c
c  Parameters:
c
c    Input, integer N, the order of the Gauss rule.
c
c    Input, integer M, the value of ( N + 1 ) / 2.
c
c    Input, double precision EPS, the requested absolute accuracy of the
c    abscissas.
c
c    Input, double precision COEF2, a value needed to compute weights.
c
c    Input, logical EVEN, is TRUE if N is even.
c
c    Input, double precision B(M+1), the Chebyshev coefficients.
c
c    Input/output, double precision X; on input, an estimate for
c    the abscissa, and on output, the computed abscissa.
c
c    Output, double precision W1, the Gauss-Kronrod weight.
c
c    Output, double precision W2, the Gauss weight.
c
c    Output, integer IER, error flag.
c    0, no error occurred.
c    1, an error occurred.
c
      implicit none

      integer m

      double precision ai
      double precision an
      double precision b(m+1)
      double precision coef2
      double precision delta
      double precision eps
      logical even
      integer i
      integer ier
      integer iter
      integer k
      integer ka
      integer n
      double precision p0
      double precision p1
      double precision p2
      double precision pd0
      double precision pd1
      double precision pd2
      double precision w1
      double precision w2
      double precision x
      double precision yy

      iter = 0

      if ( x .eq. 0.0D+00 ) then
        ka = 1
      else
        ka = 0
      end if
c
c  Iterative process for the computation of a Gaussian abscissa.
c
10    continue

      iter = iter + 1

      if ( 50 .lt. iter ) then
        write ( *, '(a)' ) ' '
        write ( *, '(a)' ) 'ABWE2 - Fatal error!'
        write ( *, '(a)' ) '  Iteration limit reached.'
        write ( *, '(a,g14.6)' ) '  Last DELTA was ', delta
        ier = 1
        return
      end if

      p0 = 1.0D+00
      p1 = x
      pd0 = 0.0D+00
      pd1 = 1.0D+00
      ai = 0.0D+00
      do k = 2, n
        ai = ai + 1.0D+00
        p2 = ( ( ai + ai + 1.0D+00 ) * x * p1 - ai * p0 )
     &    / ( ai + 1.0D+00 )
        pd2 = ( ( ai + ai + 1.0D+00 ) * ( p1 + x * pd1 ) - ai * pd0 )
     &    / ( ai + 1.0D+00 )
        p0 = p1
        p1 = p2
        pd0 = pd1
        pd1 = pd2
      end do
c
c  Newton correction.
c
      delta = p2 / pd2
      x = x - delta

      if ( ka .ne. 1 ) then
        if ( abs ( delta ) .le. eps ) then
          ka = 1
        end if
        go to 10
      end if

      an = n
c
c  Computation of the weight.
c
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

c*********************************************************************72
c
cc TIMESTAMP prints out the current YMDHMS date as a timestamp.
c
c  Licensing:
c
c    This code is distributed under the GNU LGPL license.
c
c  Modified:
c
c    12 January 2007
c
c  Author:
c
c    John Burkardt
c
c  Parameters:
c
c    None
c
      implicit none

      character * ( 8 ) ampm
      integer d
      character * ( 8 ) date
      integer h
      integer m
      integer mm
      character * ( 9 ) month(12)
      integer n
      integer s
      character * ( 10 ) time
      integer y

      save month

      data month /
     &  'January  ', 'February ', 'March    ', 'April    ',
     &  'May      ', 'June     ', 'July     ', 'August   ',
     &  'September', 'October  ', 'November ', 'December ' /

      call date_and_time ( date, time )

      read ( date, '(i4,i2,i2)' ) y, m, d
      read ( time, '(i2,i2,i2,1x,i3)' ) h, n, s, mm

      if ( h .lt. 12 ) then
        ampm = 'AM'
      else if ( h .eq. 12 ) then
        if ( n .eq. 0 .and. s .eq. 0 ) then
          ampm = 'Noon'
        else
          ampm = 'PM'
        end if
      else
        h = h - 12
        if ( h .lt. 12 ) then
          ampm = 'PM'
        else if ( h .eq. 12 ) then
          if ( n .eq. 0 .and. s .eq. 0 ) then
            ampm = 'Midnight'
          else
            ampm = 'AM'
          end if
        end if
      end if

      write ( *,
     &  '(i2,1x,a,1x,i4,2x,i2,a1,i2.2,a1,i2.2,a1,i3.3,1x,a)' )
     &  d, month(m), y, h, ':', n, ':', s, '.', mm, ampm

      return
      end
