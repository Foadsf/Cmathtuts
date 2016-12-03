program main

!*****************************************************************************80
!
!! MAIN is the main program for HELLO_PRB.
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
  use iso_c_binding, only : C_CHAR, C_NULL_CHAR

  implicit none
!
!  The function PRINT_C is provided by a C function, and so the following
!  INTERFACE block must set up the interface.
!
!  Notice that the name of the C function is case sensitive.
!
  interface
    subroutine print_c ( string ) bind ( C, name = "print_C" )
      use iso_c_binding, only : C_CHAR
      character ( kind = C_CHAR ) :: string ( * )
    end subroutine print_c
  end interface

  call timestamp ( )
  write ( *, '(a)' ) ' '
  write ( *, '(a)' ) 'HELLO_PRB'
  write ( *, '(a)' ) '  FORTRAN90 version'
  write ( *, '(a)' ) '  Demonstrate how a FORTRAN90 program can call'
  write ( *, '(a)' ) '  a C function to print a character string.'
!
!  It is probably acceptable to replace C_CHAR_"Hello World!"
!  by just "Hello World!", but this is not actually guaranteed
!  by the FORTRAN standard.
!
  call print_c ( C_CHAR_"Hello World!" // C_NULL_CHAR )
!
!  Terminate.
!
  write ( *, '(a)' ) ' '
  write ( *, '(a)' ) 'HELLO_PRB:'
  write ( *, '(a)' ) '  Normal end of execution.'
  write ( *, '(a)' ) ' '
  call timestamp ( )

  stop
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
