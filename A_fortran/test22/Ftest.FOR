      REAL(4) a
      REAL(8) b
      INTEGER(4) i
      COMPLEX(4) c
      COMMON /mycom/ a,b,i,c

      a = 23.0
      b = 2.0D0
      i = 4
      c = (1.0,3.0)

      CALL GETVAL()
      
      END
