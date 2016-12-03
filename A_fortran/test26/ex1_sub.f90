subroutine int_add_sub ( i1, i2, i3 )
!
!*******************************************************************************
!
!! INT_ADD_SUB adds the first two arguments and returns the sum in the third.
!
  implicit none
!
  integer i1
  integer i2
  integer i3
!
  write ( *, '(a)' ) ' '
  write ( *, '(a)' ) '  The FORTRAN routine INT_ADD_SUB received input:'
  write ( *, '(a,i6)' ) '    I1 = ', i1
  write ( *, '(a,i6)' ) '    I2 = ', i2

  i3 = i1 + i2

  write ( *, '(a)' ) '  It is sending back the output:'
  write ( *, '(a,i6)' ) '    I3 = ', i3
 
  return
end
function int_add_func ( i1, i2 )
!
!*******************************************************************************
!
!! INT_ADD_FUNC returns the sum of its two arguments as the function value.
!
  implicit none
!
  integer i1
  integer i2
  integer int_add_func
!
  int_add_func = i1 + i2

  return
end
subroutine real_add_sub ( r1, r2, r3 )
!
!*******************************************************************************
!
!! REAL_ADD_SUB adds the first two arguments and returns the sum in the third.
!
  implicit none
!
  real r1
  real r2
  real r3
!
  write ( *, '(a)' ) ' '
  write ( *, '(a)' ) '  The FORTRAN routine REAL_ADD_SUB received input:'
  write ( *, '(a,g14.6)' ) '    R1 = ', r1
  write ( *, '(a,g14.6)' ) '    R2 = ', r2

  r3 = r1 + r2

  write ( *, '(a)' ) '  It is sending back the output:'
  write ( *, '(a,g14.6)' ) '    R3 = ', r3
 
  return
end
function real_add_func ( r1, r2 )
!
!*******************************************************************************
!
!! REAL_ADD_FUNC returns the sum of its two arguments as the function value.
!
  implicit none
!
  real r1
  real r2
  real real_add_func
!
  real_add_func = r1 + r2

  return
end
subroutine double_add_sub ( r1, r2, r3 )
!
!*******************************************************************************
!
!! DOUBLE_ADD_SUB adds the first two arguments and returns the sum in the third.
!
  implicit none
!
  double precision r1
  double precision r2
  double precision r3
!
  write ( *, '(a)' ) ' '
  write ( *, '(a)' ) '  The FORTRAN routine DOUBLE_ADD_SUB received input:'
  write ( *, '(a,g14.6)' ) '    R1 = ', r1
  write ( *, '(a,g14.6)' ) '    R2 = ', r2

  r3 = r1 + r2

  write ( *, '(a)' ) '  It is sending back the output:'
  write ( *, '(a,g14.6)' ) '    R3 = ', r3
 
  return
end
function double_add_func ( r1, r2 )
!
!*******************************************************************************
!
!! DOUBLE_ADD_FUNC returns the sum of its two arguments as the function value.
!
  implicit none
!
  double precision r1
  double precision r2
  double precision double_add_func
!
  double_add_func = r1 + r2

  return
end
