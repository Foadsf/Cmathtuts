subroutine for1 ( array )
!
!*******************************************************************************
!
!! FOR1 manipulates a 3x3 array.
!
!
!  Arrays passed from C have the contents kept row-wise by column-wise,
!  whilst FORTRAN keeps arrays column-wise by row-wise.  Therefore,
!  a[i][j] in C becomes a(j,i) in FORTRAN.
!
  implicit none
!
  integer array(3,3)
  integer i
  integer j
!
  write ( *, '(a)' ) ' '
  write ( *, '(a)' ) 'FOR1'
  write ( *, '(a)' ) '  The C routine passed in the following 2D array:'
  write ( *, '(a)' ) ' '

  do i = 1, 3
    write ( *, '(3i5)' ) array(i,1:3)
  end do

  write ( *, '(a)' ) ' '
  write ( *, '(a)' ) 'FOR1:'
  write ( *, '(a)' ) '  Reset the array so that A(I,J) = 10*I+J:'

  do i =  1, 3
    do j = 1, 3
      array(i,j) = 10 * i + j
    end do
  end do

  write ( *, '(a)' ) ' '
  write ( *, '(a)' ) 'FOR1'
  write ( *, '(a)' ) '  The output array is:'
  write ( *, '(a)' ) ' '

  do i = 1, 3
    write ( *, '(3i5)' ) array(i,1:3)
  end do

  return
end
subroutine for2 ( i, r, c, d )
!
!*******************************************************************************
!
!! FOR2 accepts arguments of a variety of number types.
!
!
!  INTEGER in FORTRAN is int in C
!  REAL in FORTRAN is float in C
!  DOUBLE PRECISION in FORTRAN is double in C
!  COMPLEX in FORTRAN is a pair of floats in C (array of length 2)
!
  implicit none
!
  complex c
  double precision d
  integer i
  real r
!
  write ( *, '(a)' ) ' '
  write ( *, '(a)' ) 'FOR2:'
  write ( *, '(a)' ) '  Received numeric input from a C main program:'
  write ( *, '(a)' ) ' '
  write ( *, '(a,i6)' ) '  Integer:          ', i
  write ( *, '(a,g14.6)' ) '  Real:             ', r
  write ( *, '(a,2g14.6)' ) '  Complex:          ', c
  write ( *, '(a,g14.6)' ) '  Double precision: ', d

  i = i + 17
  c = cmplx ( ( real ( c ) * r ), ( aimag ( c ) / r ) )
  r = sign ( 1.0E+00, r ) * sqrt ( abs ( r ) )
  d = d / 2.0D+00

  write ( *, '(a)' ) ' '
  write ( *, '(a)' ) 'FOR2 transforms these numbers to:'
  write ( *, '(a)' ) ' '
  write ( *, '(a,i6)' ) '  Integer:          ', i
  write ( *, '(a,g14.6)' ) '  Real:             ', r
  write ( *, '(a,2g14.6)' ) '  Complex:          ', c
  write ( *, '(a,g14.6)' ) '  Double precision: ', d

  return
end
subroutine for3 ( )
!
!*******************************************************************************
!
!! FOR3 calls a C routine.
!
!  The C routine gets the current working directory into a character string.
!     -1 is returned if there is a problem, 0 otherwise.
!
  implicit none
!
  integer c1
  real*8 dir(8)
  character ( len = 64 ) fred
  integer len_fred
  integer len_nonnull
  integer status
!
  external c1
!
  write ( *, '(a)' ) ' '
  write ( *, '(a)' ) 'FOR3 calls a C routine to get the current directory.'
  write ( *, '(a)' ) ' '
!
!  Get the current working directory, and decide how it went.
!
  status = c1 ( dir )

  if ( status >= 0 ) then
    write ( *, '(a)' ) ' '
    write ( *, '(a)' ) 'FOR3:'
    write ( *, '(a)' ) '  C1 returns the current working directory as:'
    write ( fred, '(8a8)' ) dir    
    len_fred = len_nonnull ( fred )
    write ( *, '(a)' ) fred(1:len_fred)
  else
    write ( *, '(a)' ) ' '
    write ( *, '(a)' ) 'FOR3:'
    write ( *, '(a)' ) '  Error getting current working directory.'
  end if

  return
end
subroutine for4 ( array )
!
!*******************************************************************************
!
!! FOR4 calls a C routine.
!
!  C2 just does some manipulation of an array
!
  implicit none
!
  integer array(3,3)
  integer i
!
  external c2
!
  write ( *, '(a)' ) ' '
  write ( *, '(a)' ) 'FOR4:'
  write ( *, '(a)' ) '  On input, ARRAY has the value:'
  write ( *, '(a)' ) ' '

  do i = 1, 3
    write ( *, '(3i5)') array(i,1:3)
  end do
!
!  Call c2 to adjust array
!
  write ( *, '(a)' ) ' '
  write ( *, '(a)' ) 'FOR4:'
  write ( *, '(a)' ) '  Call C2 to adjust the array.'

  call c2 ( array )

  write ( *, '(a)' ) ' '
  write ( *, '(a)' ) 'FOR4:'
  write ( *, '(a)' ) '  On return from C2, ARRAY is:'
  write ( *, '(a)' ) ' '

  do i = 1, 3
    write ( *, '(3i5)') array(i,1:3)
  end do
 
  return
end
function len_nonnull ( s )
!
!*******************************************************************************
!
!! LEN_NONNULL returns the length of a string up to the last non-null character.
!
!
!  Modified:
!
!    26 November 2000
!
!  Author:
!
!    John Burkardt
!
!  Parameters:
!
!    Input, character ( len = * ) S, the string to measure.
!
!    Output, integer LEN_NONNULL, the length of the string, up to the last
!    non-null character.
!
  implicit none
!
  integer i
  integer len_nonnull
  integer len_s
  character, parameter :: NULL = char ( 0 )
  character ( len = * ) s
!
  len_s = len ( s )

  do i = len_s, 1, -1
    if ( s(i:i) /= NULL ) then
      len_nonnull = i
      return
    end if
  end do

  len_nonnull = 0

  return
end
