MODULE type_mod

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

END MODULE type_mod

PROGRAM test_f_to_c

  USE iso_c_binding
  USE type_mod

  INTERFACE
     SUBROUTINE init_data(A,N) bind(c)
       USE iso_c_binding
       USE type_mod
       TYPE(type1_t) :: A
       INTEGER(c_int), value :: N
     END SUBROUTINE init_data
  END INTERFACE

  INTEGER, value :: N
  PARAMETER(N=10)
  TYPE(type1_t) :: A
  INTEGER :: i
  TYPE(type3_t), DIMENSION(:), POINTER :: status

  CALL init_data(A,N)

  PRINT *, A%idx, A%params%idx, A%params%size
  CALL c_f_pointer(A%status,status,[N])
  DO i=1,N
     PRINT *, i, status(i)%idx, status(i)%size
  ENDDO

END PROGRAM test_f_to_c
