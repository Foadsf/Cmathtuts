to run it on mac OS X:
  gcc testblas.c -o testblas -framework Accelerate -lm

to do:
1. add a cross platform MakeFile


comments:
1. it is also possible to use openblas on mac OS X
  a. brew install openblas
  b. compile using the command:
    gcc testblas.c -o testblas -lblas -lm -I/usr/local/Cellar/openblas/0.2.18_2/include
