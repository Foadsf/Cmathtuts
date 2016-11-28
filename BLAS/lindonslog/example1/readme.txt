dscal scales a vector/array


source:
http://www.lindonslog.com/programming/atlas-blas-lapack-linear-algebra-libraries/


to compile:

gcc example1.c -lblas -o example1.out

if you have your libblas.a in the common folder

gcc example1.c ../../../common/lib/libblas.a -o example1.out

gcc example1.c ../../../common/lib/librefblas.a -o example1.out
