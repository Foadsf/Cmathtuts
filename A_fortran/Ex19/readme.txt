source: http://www.pgroup.com/userforum/viewtopic.php?t=1764&highlight=fortran+bind


issue:

does not compile:

test13F.f90:36:16:

   PARAMETER(N=10)
                1
Error: PARAMETER attribute conflicts with VALUE attribute in 'n' at (1)
test13F.f90:35:21:

   INTEGER, value :: N
                     1
Error: 'n' at (1) cannot have the VALUE attribute because it is not a dummy argument
make: *** [all] Error 1
