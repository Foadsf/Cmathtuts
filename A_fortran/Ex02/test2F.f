      subroutine fortfunc(iii,fff)
C      integer iii
C      real*4  fff

      write(6,100) iii, fff
100   format('ii=',i2,' ff=',f6.3)

      return
      end
