      PROGRAM main
      DOUBLE PRECISION X
      INTEGER A,B,C
      CHARACTER*10 S10
      COMMON /ABC/X,A,B,C,S10
      print *,'main1: begin'
      X = 888.2954
      A = -4
      B = 2
      C = 67
      S10 = 'U_ARE_FINE'
      print *,'X:',X
      print *,'A,B,C:',A,B,C
      print *,'S10:','[',S10,']'
      CALL cpps()
      print *,'X:',X
      print *,'A,B,C:',A,B,C
      print *,'S10:','[',S10,']'
      print *,'main1: end'
      END
