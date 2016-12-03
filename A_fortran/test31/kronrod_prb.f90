program main

!*****************************************************************************80
!
!! MAIN is the main program for KRONROD_PRB.
!
!  Licensing:
!
!    This code is distributed under the GNU LGPL license. 
!
!  Modified:
!
!    01 September 2011
!
!  Author:
!
!    John Burkardt
!
  use, intrinsic :: iso_c_binding

  implicit none
!
!  TIMESTAMP is provided by the C library, and so the following
!  INTERFACE block must set up the interface.
!
  interface
    subroutine timestamp ( ) bind ( c )
      use iso_c_binding
    end subroutine timestamp
  end interface

  call timestamp ( )

  write ( *, '(a)' ) ' '
  write ( *, '(a)' ) 'KRONROD_PRB:'
  write ( *, '(a)' ) '  FORTRAN90 version'
  write ( *, '(a)' ) '  FORTRAN90 test program calls C functions.'

  call test01 ( )
  call test02 ( )
!
!  Terminate.
!
  write ( *, '(a)' ) ' '
  write ( *, '(a)' ) 'KRONROD_PRB:'
  write ( *, '(a)' ) '  Normal end of execution.'

  write ( *, '(a)' ) ' '
  call timestamp ( )

  stop
end
subroutine test01 ( )

!*****************************************************************************80
!
!! TEST01 tests the code for the odd case N = 3.
!
!  Licensing:
!
!    This code is distributed under the GNU LGPL license. 
!
!  Modified:
!
!    21 October 2010
!
!  Author:
!
!    John Burkardt
!
  use, intrinsic :: iso_c_binding

  implicit none
!
!  KRONROD is provided by the C library, and so the following
!  INTERFACE block must be set up to describe how data is to 
!  be passed.
!
  interface
    subroutine kronrod ( n, eps, x, w1, w2 ) bind ( c )
      use iso_c_binding
      integer ( c_int ), VALUE :: n
      real ( c_double ), VALUE :: eps
      real ( c_double ) :: x(*)
      real ( c_double ) :: w1(*)
      real ( c_double ) :: w2(*)
    end subroutine kronrod
  end interface

  integer ( c_int ), parameter :: n = 3

  real ( c_double ) eps
  integer ( c_int ) i
  integer ( c_int ) i2
  real ( c_double ) s
  real ( c_double ) w1(n+1)
  real ( c_double ) w2(n+1)
  real ( c_double ) :: wg(n) = (/ &
    0.555555555555555555556D+00, &
    0.888888888888888888889D+00, &
    0.555555555555555555556D+00 /)
  real    ( c_double ) :: wk(2*n+1) = (/ &
    0.104656226026467265194D+00, &
    0.268488089868333440729D+00, &
    0.401397414775962222905D+00, &
    0.450916538658474142345D+00, &
    0.401397414775962222905D+00, &
    0.268488089868333440729D+00, &
    0.104656226026467265194D+00 /)
  real ( c_double ) x(n+1)
  real ( c_double ) :: xg(n) = (/ &
   -0.77459666924148337704D+00, &
    0.0D+00, &
    0.77459666924148337704D+00 /)
  real ( c_double ) :: xk(2*n+1) = (/ &
   -0.96049126870802028342D+00, &
   -0.77459666924148337704D+00, &
   -0.43424374934680255800D+00, &
    0.0D+00, &
    0.43424374934680255800D+00, &
    0.77459666924148337704D+00, &
    0.96049126870802028342D+00 /)

  write ( *, '(a)' ) ' '
  write ( *, '(a)' ) 'TEST01'
  write ( *, '(a)' ) '  Request KRONROD to compute the Gauss rule'
  write ( *, '(a)' ) '  of order 3, and the Kronrod extension of'
  write ( *, '(a)' ) '  order 3+4=7.'
  write ( *, '(a)' ) ' '
  write ( *, '(a)' ) '  Compare to exact data.'

  eps = 0.000001D+00

  call kronrod ( n, eps, x, w1, w2 )

  write ( *, '(a)' ) ' '
  write ( *, '(a,i2)' ) '  KRONROD returns 3 vectors of length ', n + 1
  write ( *, '(a)' ) ' '
  write ( *, '(a)' ) '     I      X               WK              WG'
  write ( *, '(a)' ) ' '
  do i = 1, n + 1
    write ( *, '(2x,i4,2x,g14.6,2x,g14.6,2x,g14.6)' ) i, x(i), w1(i), w2(i)
  end do

  write ( *, '(a)' ) ' '
  write ( *, '(a)' ) '               Gauss Abscissas'
  write ( *, '(a)' ) '            Exact           Computed'
  write ( *, '(a)' ) ' '
  do i = 1, n
    if ( 2 * i <= n + 1 ) then
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
    if ( 2 * i <= n + 1 ) then
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
    if ( i <= n + 1 ) then
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
    if ( i <= n + 1 ) then
      i2 = i
    else
      i2 = 2 * ( n + 1 ) - i
    end if
    write ( *, '(2x,i4,2x,g14.6,2x,g14.6)' ) i, wk(i), w1(i2)
  end do

  return
end
subroutine test02 ( )

!*****************************************************************************80
!
!! TEST02 tests the code for the even case N = 4.
!
!  Licensing:
!
!    This code is distributed under the GNU LGPL license. 
!
!  Modified:
!
!    21 October 2010
!
!  Author:
!
!    John Burkardt
!
  use, intrinsic :: iso_c_binding

  implicit none
!
!  KRONROD is provided by the C library, and so the following
!  INTERFACE block must be set up to describe how data is to 
!  be passed.
!
  interface
    subroutine kronrod ( n, eps, x, w1, w2 ) bind ( c )
      use iso_c_binding
      integer ( c_int ), VALUE :: n
      real ( c_double ), VALUE :: eps
      real ( c_double ) :: x(*)
      real ( c_double ) :: w1(*)
      real ( c_double ) :: w2(*)
    end subroutine kronrod
  end interface

  integer ( c_int ), parameter :: n = 4

  real ( c_double ) eps
  integer ( c_int ) i
  integer ( c_int ) i2
  real ( c_double ) s
  real ( c_double ) w1(n+1)
  real ( c_double ) w2(n+1)
  real ( c_double ) x(n+1)

  write ( *, '(a)' ) ' '
  write ( *, '(a)' ) 'TEST02'
  write ( *, '(a)' ) '  Request KRONROD to compute the Gauss rule'
  write ( *, '(a)' ) '  of order 4, and the Kronrod extension of'
  write ( *, '(a)' ) '  order 4+5=9.'

  eps = 0.000001D+00

  call kronrod ( n, eps, x, w1, w2 )

  write ( *, '(a)' ) ' '
  write ( *, '(a,i2)' ) '  KRONROD returns 3 vectors of length ', n + 1
  write ( *, '(a)' ) ' '
  write ( *, '(a)' ) '     I      X               WK              WG'
  write ( *, '(a)' ) ' '
  do i = 1, n + 1
    write ( *, '(2x,i4,2x,g14.6,2x,g14.6,2x,g14.6)' ) i, x(i), w1(i), w2(i)
  end do

  return
end

