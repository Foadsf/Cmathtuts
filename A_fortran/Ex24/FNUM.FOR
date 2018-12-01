C  FORTRAN program FNUM.FOR contains the following lines of code:

      SUBROUTINE FNUM
      INTEGER*4 INUM,JNUM,KNUM
      COMMON /NUMBERS/ INUM,JNUM,KNUM

      TYPE 10, (INUM,JNUM,KNUM)
10    FORMAT (318)
      RETURN
      END

C  End of FORTRAN program
