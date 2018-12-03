C   File FORMAIN.FOR
C
      INTERFACE 
      INTEGER*4 FUNCTION Fact (n)
      INTEGER*4 n
      END
      END INTERFACE

      INTERFACE
      SUBROUTINE Pythagoras (a,b,c)
      REAL*4 a
      REAL*4 b
      REAL*4 c
      END
      END INTERFACE

      REAL*4 c
      WRITE (*,*) 'Factorial of 7 is ', Fact (7)
      CALL Pythagoras (30.0, 40.0, c)
      WRITE (*,*) 'Hypotenuse if sides 30, 40 is ', c
      END
