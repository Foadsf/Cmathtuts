source: http://www.pgroup.com/userforum/viewtopic.php?t=1764&highlight=fortran+bind

does not compile:

test13F.f90:35:33:

 CALL c_f_pointer(A%status,status,N)
                                 1
Error: 'shape' argument of 'c_f_pointer' intrinsic at (1) must be of rank 1
