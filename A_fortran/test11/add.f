      REAL*8 FUNCTION ADD (A, B, C, D)
      REAL*8 B,D
      INTEGER*4 A,C
      DIMENSION B(4), D(4)
      ADD = B(A) + D(C)
      RETURN
      END
