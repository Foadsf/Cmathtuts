      program main

c*********************************************************************72
c
cc MAIN is a FORTRAN77 program that calls a C routine.
c
c  Discussion:
c
c    Routines in C are all called "functions", but if a C function is
c    "void", then it seems much like a FORTRAN subroutine.  Otherwise,
c    a C function is similar to a FORTRAN function.
c
c    The details of this routine depend on the machine being used
c    and the compilers involved.  In some cases, you need to tell the
c    FORTRAN compiler not to append an underscore to symbolic names.
c
c    For instance, on the DEC/COMPAQ ALPHA, you do this with the command
c
c      fort -assume nounderscore myprog.f90
c
c    or, for FORTRAN77 code:
c
c      f77 -fno-underscoring myprog.f
c
c    On other machines, the FORTRAN compiler may append an underscore,
c    and you may have to append a corresponding underscore to the names
c    of the routines in the C text (but not in the FORTRAN codec).
c
c    Also, if you use a FORTRAN command to link and load the object
c    files, you may need to include an explicit request for the C libraries,
c    so that the C routines can access routines that they need.
c    This might be done by a command like:
c
c      fort myprog.o mysub.o -lm -lc
c
c    or
c
c      f77 myprog.o mysub.o -lm -lc
c
c    but of course, the actual names and locations of the necessary C
c    libraries can vary from machine to machine.
c
c  Modified:
c
c    29 October 2003
c
c  Author:
c
c    John Burkardt
c
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
      write ( *, '(a)' ) 'PROB6_MAIN'
      write ( *, '(a)' ) '  Demonstrate how a FORTRAN77'
      write ( *, '(a)' ) '  program calls a C routine.'

      i1 = 42
      i2 = 22
      call int_add_sub ( i1, i2, i3 )
      i4 = int_add_func ( i1, i2 )

      write ( *, '(a)' ) ' '
      write ( *, '(a)' ) '  Set the value of two'
      write ( *, '(a)' ) '  integers I1 and I2.'
      write ( *, '(a)' ) '  Call a C routine to '
      write ( *, '(a)' ) '  compute I1 + I2.'
      write ( *, '(a)' ) ' '
      write ( *, '(a,i6)' ) '  Input I1 = ', i1
      write ( *, '(a,i6)' ) '  Input I2 = ', i2
      write ( *, '(a,i6)' ) 
     &   '  INT_ADD_SUB  returns I3 = ', i3
      write ( *, '(a,i6)' ) 
     &   '  INT_ADD_FUNC returns I4 = ', i4

      r1 = 42.0E+00
      r2 = 22.0E+00
      call real_add_sub ( r1, r2, r3 )
      r4 = real_add_func ( r1, r2 )

      write ( *, '(a)' ) ' '
      write ( *, '(a)' ) 
     &   '  Set the value of two reals R1 and R2.'
      write ( *, '(a)' ) 
     &   '  Call a C routine to compute R1 + R2.'
      write ( *, '(a)' ) ' '
      write ( *, '(a,g14.6)' ) '  Input R1 = ', r1
      write ( *, '(a,g14.6)' ) '  Input R2 = ', r2
      write ( *, '(a,g14.6)' ) 
     &   '  REAL_ADD_SUB  returns R3 = ', r3
      write ( *, '(a,g14.6)' ) 
     &   '  REAL_ADD_FUNC returns R4 = ', r4

      d1 = 42.0D+00
      d2 = 22.0D+00
      call double_add_sub ( d1, d2, d3 )
      d4 = double_add_func ( d1, d2 )

      write ( *, '(a)' ) ' '
      write ( *, '(a)' ) 
     &   '  Set the value of two double precision '
      write ( *, '(a)' ) '  values D1 and D2.'
      write ( *, '(a)' ) 
     &   '  call a C routine to compute D1 + D2.'
      write ( *, '(a)' ) ' '
      write ( *, '(a,g14.6)' ) '  Input D1 = ', d1
      write ( *, '(a,g14.6)' ) '  Input D2 = ', d2
      write ( *, '(a,g14.6)' ) 
     &   '  DOUBLE_ADD_SUB  returns output D3 = ', d3
      write ( *, '(a,g14.6)' ) 
     &   '  DOUBLE_ADD_FUNC returns output D4 = ', d4

      write ( *, '(a)' ) ' '
      write ( *, '(a)' ) 'PROB6_MAIN:'
      write ( *, '(a)' ) '  Normal end of execution.'

      stop
      end
