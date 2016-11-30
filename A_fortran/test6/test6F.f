C *********** Fortran subprogram (f.f): ***********

      SUBROUTINE fctn

      COMMON /ST/ I, A(10), D
      INTEGER I
      REAL A
      DOUBLE PRECISION D

      INTEGER II

      WRITE(6,100) I, D
  100 FORMAT ('IN FORTRAN: I = ', I5, ', D = ', D25.20)
      WRITE(6,200) (A(II), II = 1,10)
  200 FORMAT ('IN FORTRAN: A =', 10F4.1)
      END
