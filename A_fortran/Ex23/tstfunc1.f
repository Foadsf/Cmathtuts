      subroutine tstfunc()
          implicit none
          real delta(5, 5)
          common /test/ delta
          integer i,j
          do i = 1, 5
             do j = 1, 5
                if (i.ne.j) then
                  delta(i,j)=0
                else
                  delta(i,j)=2
                end if
                write (*,*) delta(i,j)
              end do
          end do
      end
