      program fprogram
      real a,b
      a=1.0
      b=2.0
 
      print*,'Before Fortran function is called:'
      print*,'a=',a
      print*,'b=',b
      call ffunction(a,b)
      print*,'After Fortran function is called:'
      print*,'a=',a
      print*,'b=',b
 
      print*,'Before C function is called:'
      print*,'a=',a
      print*,'b=',b
      call cfunction(a,b)
      print*,'After C function is called:'
      print*,'a=',a
      print*,'b=',b
 
      print*,'Before C++ function is called:'
      print*,'a=',a
      print*,'b=',b
      call cppfunction(a,b)
      print*,'After C++ function is called:'
      print*,'a=',a
      print*,'b=',b
 
      stop
      end
