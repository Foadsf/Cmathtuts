program main

!*****************************************************************************80
!
!! MAIN is the main program for EX2.
!
!  Discussion:
!
!    EX2 is a mixed FORTRAN90/C++ program.
!
!    If the C++ compiler is used to load the FORTRAN and C++ object
!    codes, then this main program MUST be called "main"!
!
!    Routines in C++ are all called "functions", but if a C++ function is
!    "void", then it seems much like a FORTRAN subroutine.  Otherwise,
!    a C++ function is similar to a FORTRAN function.
!
!    The details of this routine depend on the machine being used
!    and the compilers involved.  In some cases, you need to tell the
!    FORTRAN compiler not to append an underscore to symbolic names.
!
!    For instance, on the DEC/COMPAQ ALPHA, you do this with the command
!
!      fort -assume nounderscore myprog.f90
!
!    and with GFORTRAN you say
!
!      gfortran -fno-underscoring myprog.f90
!
!    On other machines, the FORTRAN compiler may append an underscore,
!    and you may have to append a corresponding underscore to the names
!    of the routines in the C++ text (but not in the FORTRAN code!).
!
!    Also, if you use a FORTRAN command to link and load the object
!    files, you may need to include an explicit request for the C++ libraries,
!    so that the C routines can access routines that they need.
!    This might be done by a command like:
!
!      fort myprog.o mysub.o -lm -lc
!
!    but of course, the actual names and locations of the necessary C++
!    libraries can vary from machine to machine.
!
!  Modified:
!
!    25 June 2008
!
!  Author:
!
!    John Burkardt
!
  implicit none

  double precision d1
  double precision d2
  double precision d3
  double precision d4
  double precision double_add_func
  integer i1
  integer i2
  integer i3
  integer i4
  integer int_add_func
  real r1
  real r2
  real r3
  real r4
  real real_add_func

  write ( *, '(a)' ) ' '
  write ( *, '(a)' ) 'EX2'
  write ( *, '(a)' ) '  FORTRAN90 main program'
  write ( *, '(a)' ) ' '
  write ( *, '(a)' ) '  Demonstrate how a FORTRAN program '
  write ( *, '(a)' ) '  can call a C++ routine.'

  i1 = 42
  i2 = 22
  call int_add_sub ( i1, i2, i3 )
  i4 = int_add_func ( i1, i2 )

  write ( *, '(a)' ) ' '
  write ( *, '(a)' ) '  Set the value of two integers I1 and I2.'
  write ( *, '(a)' ) '  Call a C++ routine to compute I1 + I2.'
  write ( *, '(a)' ) ' '
  write ( *, '(a,i6)' ) '  Input I1 = ', i1
  write ( *, '(a,i6)' ) '  Input I2 = ', i2
  write ( *, '(a,i6)' ) '  INT_ADD_SUB  returns I3 = ', i3
  write ( *, '(a,i6)' ) '  INT_ADD_FUNC returns I4 = ', i4

  r1 = 42.0E+00
  r2 = 22.0E+00
  call real_add_sub ( r1, r2, r3 )
  r4 = real_add_func ( r1, r2 )

  write ( *, '(a)' ) ' '
  write ( *, '(a)' ) '  Set the value of two reals R1 and R2.'
  write ( *, '(a)' ) '  Call a C++ routine to compute R1 + R2.'
  write ( *, '(a)' ) ' '
  write ( *, '(a,g14.6)' ) '  Input R1 = ', r1
  write ( *, '(a,g14.6)' ) '  Input R2 = ', r2
  write ( *, '(a,g14.6)' ) '  REAL_ADD_SUB  returns R3 = ', r3
  write ( *, '(a,g14.6)' ) '  REAL_ADD_FUNC returns R4 = ', r4

  d1 = 42.0D+00
  d2 = 22.0D+00
  call double_add_sub ( d1, d2, d3 )
  d4 = double_add_func ( d1, d2 )

  write ( *, '(a)' ) ' '
  write ( *, '(a)' ) '  Set the value of two double precision values D1 and D2.'
  write ( *, '(a)' ) '  call a C++ routine to compute D1 + D2.'
  write ( *, '(a)' ) ' '
  write ( *, '(a,g14.6)' ) '  Input D1 = ', d1
  write ( *, '(a,g14.6)' ) '  Input D2 = ', d2
  write ( *, '(a,g14.6)' ) '  DOUBLE_ADD_SUB  returns output D3 = ', d3
  write ( *, '(a,g14.6)' ) '  DOUBLE_ADD_FUNC returns output D4 = ', d4
!
!  Terminate.
!
  write ( *, '(a)' ) ' '
  write ( *, '(a)' ) 'EX2:'
  write ( *, '(a)' ) '  Normal end of execution.'

  stop
end
