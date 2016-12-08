C   File FORMAIN.FOR
C
      INTERFACE TO INTEGER*4 FUNCTION Fact [C,ALIAS:'_Fact'] (n)
      INTEGER*4 n [VALUE]
      END

      INTERFACE TO SUBROUTINE Pythagoras [C,ALIAS:'_Pythagoras'] (a,b,c)
      REAL*4 a [VALUE]
      REAL*4 b [VALUE]
      REAL*4 c [REFERENCE]
      END

      INTEGER*4 Fact
      REAL*4 c
      WRITE (*,*) 'Factorial of 7 is ', Fact (7)
      CALL Pythagoras (30, 40, c)
      WRITE (*,*) 'Hypotenuse if sides 30, 40 is ', c
      END
