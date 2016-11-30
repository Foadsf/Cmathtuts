C    File FORSUBS.FOR
C
      INTEGER*4 FUNCTION fact(n)
      INTEGER*4 n
      INTEGER*4 i, amt
      amt = 1
      DO i = 1, n
        amt = amt * i
      END DO
      Fact = amt
      END

      SUBROUTINE pythagoras(a, b, c)
      REAL*4 a
      REAL*4 b
      REAL*4 c
      c = SQRT (a * a + b * b)
      END
C
