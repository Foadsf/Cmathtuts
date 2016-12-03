      PROGRAM main
      DOUBLE PRECISION X
      INTEGER A,B,C
      CHARACTER*10 S10
      COMMON /ABC/X,A,B,C,S10
      print *,'main: begin'
      X = 55.39
      A = 1
      B = 2
      C = 5
      S10 = 'HOW_ARE_U?'
      print *,'X:',X
      print *,'A,B,C:',A,B,C
      print *,'S10:','[',S10,']'
      CALL cpps()
      print *,'X:',X
      print *,'A,B,C:',A,B,C
      print *,'S10:','[',S10,']'
      print *,'main: end'
      END 
