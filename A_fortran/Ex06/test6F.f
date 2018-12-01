C *********** Fortran subprogram (f.f): ***********

      SUBROUTINE FCTN

      INTEGER I
      REAL A(10)
      DOUBLE PRECISION D
      COMMON /ST/ I, A, D

      INTEGER II

      WRITE(6,100) STI, STD
100   FORMAT ('IN FORTRAN: STI = ', I5, ', STD = ', D25.20)
      WRITE(6,200) (STA(II), II = 1,10)
200   FORMAT ('IN FORTRAN: STA =', 10F4.1)
      END
