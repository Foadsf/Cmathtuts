C      EXTERNAL ISCAN
C      INTEGER(KIND=8) ISCAN
      INTEGER(KIND=8) RET
      INTEGER J,K
      CHARACTER*(50) INP
      INP = '1  -99   3141592  0xfff  033 '
      J = 0
      DO WHILE (J .LT. LEN(INP))
            K = J
            RET = ISCAN(INP,J)
            PRINT *, K,': ',RET,' -->',J
      END DO
      END
