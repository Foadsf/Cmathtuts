C    File FORSUBS.FOR
C
      INTEGER*4 FUNCTION fact(n)
C      INTEGER*4 n
C      INTEGER*4 i
      fact = 1
      DO i = 1, n
        fact = fact * i
      END DO
C      fact = amt
      END



      SUBROUTINE pythagoras(a, b, c)
C      REAL*4 a
C      REAL*4 b
C      REAL*4 c
      c = SQRT (a * a + b * b)
      END
C
