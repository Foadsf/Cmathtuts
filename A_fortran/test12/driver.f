      program driver

      integer veclen matdim
      real mat, dot
      real vec1(2), vec2(2)
      real matrix1(3,3), matrix2(3,3), matrix3(3,3)

      veclen = 2
      matdim = 3

      vec1(1) = 1.0
      vec1(2) = 2.0
      vec2(1) = 3.0
      vec2(2) = 4.0

      matrix1(1,1) = 1.0
      matrix1(2,1) = 0.0
      matrix1(3,1) = 0.0
      matrix1(1,2) = 0.0
      matrix1(2,2) = 1.0
      matrix1(3,2) = 0.0
      matrix1(1,3) = 0.0
      matrix1(2,3) = 0.0
      matrix1(3,3) = 1.0

      matrix2(1,1) = 1.0
      matrix2(2,1) = 0.0
      matrix2(3,1) = 0.0
      matrix2(1,2) = 0.0
      matrix2(2,2) = 2.0
      matrix2(3,2) = 0.0
      matrix2(1,3) = 0.0
      matrix2(2,3) = 0.0
      matrix2(3,3) = 3.0

      mat = 0.0;

* mat should get incremented by 1 in testret
      do 10 i = 1, 10
         call testret(mat)
10    continue

* testdot should return the dot product of vec1 and vec2 as a real
      dot = testdot(veclen, vec1, vec2)

* testmat uses matrix1 and matrix2 to calculate matrix3
      call testmat(matdim, matrix1, matrix2, matrix3)

      print *, mat, '  ', dot
      print *,
      do 20 i = 1, matdim
        write (6,*) (matrix3(j,i), j=1,matdim)
20    continue


      end
