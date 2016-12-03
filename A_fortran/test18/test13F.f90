SUBROUTINE fortran_func (Aptr, N)

  USE iso_c_binding

  TYPE, bind(c) :: type2_t
  INTEGER(c_int) :: idx, size
END TYPE type2_t

TYPE, bind(c) :: type3_t
INTEGER(c_int) :: idx, size
END TYPE type3_t

TYPE, bind(c) :: type1_t
TYPE(type2_t) :: params
TYPE(c_ptr) :: status
INTEGER(c_int) :: idx
END TYPE type1_t

TYPE(c_ptr), value :: Aptr
TYPE(type1_t), POINTER :: A
TYPE(type3_t), DIMENSION(:), POINTER :: status
INTEGER, value :: N
INTEGER :: i

! Assocatate the C "Aptr" pointer to a local fortran
! pointer to type1_t
CALL c_f_pointer(Aptr,A)

A%idx = 1
A%params%idx = 100
A%params%size = 1000

! Associate the 'status' type1_t pointer to A%status
! You must add a shape arguement (N) since its an array
CALL c_f_pointer(A%status,status,[N])

DO i=1,N
status(i)%idx = i
status(i)%size = N-i
ENDDO

END SUBROUTINE fortran_func
