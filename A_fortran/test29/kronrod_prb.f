      program main

c*********************************************************************72
c
cc MAIN is the main program for KRONROD_PRB.
c
c  Discussion:
c
c    KRONROD_PRB tests the KRONROD library.
c
c  Licensing:
c
c    This code is distributed under the GNU LGPL license.
c
c  Modified:
c
c    21 December 2010
c
c  Author:
c
c    John Burkardt
c
      implicit none

      call timestamp ( )
      write ( *, '(a)' ) ' '
      write ( *, '(a)' ) 'KRONROD_PRB:'
      write ( *, '(a)' ) '  FORTRAN77 version.'
      write ( *, '(a)' ) '  Test the KRONROD library.'

      call test01 ( )
      call test02 ( )
c
c  Terminate.
c
      write ( *, '(a)' ) ' '
      write ( *, '(a)' ) 'KRONROD_PRB:'
      write ( *, '(a)' ) '  Normal end of execution.'
      write ( *, '(a)' ) ' '
      call timestamp ( )

      stop
      end
      subroutine test01 ( )

c*********************************************************************72
c
cc TEST01 tests the code for the odd case N = 3.
c
c  Licensing:
c
c    This code is distributed under the GNU LGPL license.
c
c  Modified:
c
c    21 December 2010
c
c  Author:
c
c    John Burkardt
c
      implicit none

      integer n
      parameter ( n = 3 )

      double precision eps
      integer i
      integer i2
      double precision s
      double precision w1(n+1)
      double precision w2(n+1)
      double precision wg(n)
      double precision wk(2*n+1)
      double precision x(n+1)
      double precision xg(n)
      double precision xk(2*n+1)

      save wg
      save wk
      save xg
      save xk

      data wg /
     &  0.555555555555555555556D+00,
     &  0.888888888888888888889D+00,
     &  0.555555555555555555556D+00 /
      data wk /
     &  0.104656226026467265194D+00,
     &  0.268488089868333440729D+00,
     &  0.401397414775962222905D+00,
     &  0.450916538658474142345D+00,
     &  0.401397414775962222905D+00,
     &  0.268488089868333440729D+00,
     &  0.104656226026467265194D+00 /
      data xg /
     & -0.77459666924148337704D+00,
     &  0.0D+00,
     &  0.77459666924148337704D+00 /
      data xk /
     & -0.96049126870802028342D+00,
     & -0.77459666924148337704D+00,
     & -0.43424374934680255800D+00,
     &  0.0D+00,
     &  0.43424374934680255800D+00,
     &  0.77459666924148337704D+00,
     &  0.96049126870802028342D+00 /

      write ( *, '(a)' ) ' '
      write ( *, '(a)' ) 'TEST01'
      write ( *, '(a)' ) '  Request KRONROD to compute the Gauss rule'
      write ( *, '(a)' ) '  of order 3, and the Kronrod extension of'
      write ( *, '(a)' ) '  order 3+4=7.'
      write ( *, '(a)' ) ' '
      write ( *, '(a)' ) '  Compare to exact data.'

      eps = 0.000001D+00

      call kronrod ( %val ( n ), %val ( eps ), x, w1, w2 )

      write ( *, '(a)' ) ' '
      write ( *, '(a,i2)' )
     &  '  KRONROD returns 3 vectors of length ', n + 1
      write ( *, '(a)' ) ' '
      write ( *, '(a)' )
     &  '     I      X               WK              WG'
      write ( *, '(a)' ) ' '
      do i = 1, n + 1
        write ( *, '(2x,i4,2x,g14.6,2x,g14.6,2x,g14.6)' )
     &  i, x(i), w1(i), w2(i)
      end do

      write ( *, '(a)' ) ' '
      write ( *, '(a)' ) '               Gauss Abscissas'
      write ( *, '(a)' ) '            Exact           Computed'
      write ( *, '(a)' ) ' '
      do i = 1, n
        if ( 2 * i .le. n + 1 ) then
          i2 = 2 * i
          s = -1.0D+00
        else
          i2 = 2 * ( n + 1 ) - 2 * i
          s = +1.0D+00
        end if
        write ( *, '(2x,i4,2x,g14.6,2x,g14.6)' ) i, xg(i), s * x(i2)
      end do
      write ( *, '(a)' ) ' '
      write ( *, '(a)' ) '               Gauss Weights'
      write ( *, '(a)' ) '            Exact           Computed'
      write ( *, '(a)' ) ' '
      do i = 1, n
        if ( 2 * i .le. n + 1 ) then
          i2 = 2 * i
        else
          i2 = 2 * ( n + 1 ) - 2 * i
        end if
        write ( *, '(2x,i4,2x,g14.6,2x,g14.6)' ) i, wg(i), w2(i2)
      end do

      write ( *, '(a)' ) ' '
      write ( *, '(a)' ) '             Gauss Kronrod Abscissas'
      write ( *, '(a)' ) '            Exact           Computed'
      write ( *, '(a)' ) ' '
      do i = 1, 2 * n + 1
        if ( i .le. n + 1 ) then
          i2 = i
          s = -1.0D+00
        else
          i2 = 2 * ( n + 1 ) - i
          s = +1.0D+00
        end if
        write ( *, '(2x,i4,2x,g14.6,2x,g14.6)' ) i, xk(i), s * x(i2)
      end do
      write ( *, '(a)' ) ' '
      write ( *, '(a)' ) '             Gauss Kronrod Weights'
      write ( *, '(a)' ) '            Exact           Computed'
      write ( *, '(a)' ) ' '
      do i = 1, 2 * n + 1
        if ( i .le. n + 1 ) then
          i2 = i
        else
          i2 = 2 * ( n + 1 ) - i
        end if
        write ( *, '(2x,i4,2x,g14.6,2x,g14.6)' ) i, wk(i), w1(i2)
      end do

      return
      end
      subroutine test02 ( )

c*********************************************************************72
c
cc TEST02 tests the code for the even case N = 4.
c
c  Licensing:
c
c    This code is distributed under the GNU LGPL license.
c
c  Modified:
c
c    21 December 2010
c
c  Author:
c
c    John Burkardt
c
      implicit none

      integer n
      parameter ( n = 4 )

      double precision eps
      integer i
      integer i2
      double precision s
      double precision w1(n+1)
      double precision w2(n+1)
      double precision x(n+1)

      write ( *, '(a)' ) ' '
      write ( *, '(a)' ) 'TEST02'
      write ( *, '(a)' ) '  Request KRONROD to compute the Gauss rule'
      write ( *, '(a)' ) '  of order 4, and the Kronrod extension of'
      write ( *, '(a)' ) '  order 4+5=9.'

      eps = 0.000001D+00

      call kronrod ( %val ( n ), %val ( eps ), x, w1, w2 )

      write ( *, '(a)' ) ' '
      write ( *, '(a,i2)' )
     &  '  KRONROD returns 3 vectors of length ', n + 1
      write ( *, '(a)' ) ' '
      write ( *, '(a)' )
     &  '     I      X               WK              WG'
      write ( *, '(a)' ) ' '
      do i = 1, n + 1
        write ( *, '(2x,i4,2x,g14.6,2x,g14.6,2x,g14.6)' )
     &  i, x(i), w1(i), w2(i)
      end do

      return
      end

