to do:

1. write a ruby Homebrew formula for CBLAS


instructions:

new:
the best way to get cblas is to get lapack https://github.com/Foadsf/Cmathtuts/tree/master/LAPACK

old:

to compile these examples under :
1. you need to have BLAS. go to BLAS folder for the instructions:https://github.com/Foadsf/Cmathtuts/blob/master/BLAS/readme.txt
2. compile the netlib cblas
  2.1. download CBLAS from from netlib website: http://www.netlib.org/blas/
  2.2. unarchive
  2.3. open the file Makefile.in
  2.4. look for the line BLLIB = .../blas_LINUX.a
  2.5. put the address of libblas.a you had from BLAS instructions here (or if you have the libblas.a installed put just -lblas)
  2.6. change PLAT = LINUX to your platform. for example for mac:
    PLAT = DARWIN
  2.7 optional: change the line below:
    CBLIB = ../lib/cblas_$(PLAT).a
  to
    CBLIB = ../lib/libcblas.a
  2.8. on mac OS X change the line below:
    FFLAGS = -O3
  to
    FFLAGS = -O3 -pipe -c
  2.9. go to the terminal in unarchived cblas folder and run make
3. look for the cblas.h file in the include folder and when you run the gcc link against this folder
4. you can copy the built files to the default folders so later the compiler automatically finds the files
  4.1. copy cblas_f77.h and cblas.h to /usr/local/include/
  4.2. copy libcblas.a to /usr/local/lib
source: http://avulanov.blogspot.nl/2015/03/cblas-compilation-as-shared-library.html


warning: order of linking is important. always link to libblas.a (or librefblas.a) before libcblas.a



list of functions:
1. cblas_zdotc_sub: dot product of two complex vectors
2. cblas_dgemm: matrix multiplication
3. cblas_dscal: scale a vector/array
4. cblas_dswap: Exchanges the elements of two vectors (double precision)
5. cblas_dcopy: Copies a vector to another vector (double-precision).
6. cblas_daxpy: Computes a vector-scalar product and adds the result to a vector.
7. cblas_dgemv: Multiplies a matrix by a vector (double precision).
8. cblas_dger: Multiplies vector X by the transform of vector Y, then adds matrix A (double precision).
9. cblas_ddot: Computes the dot product of two vectors (double-precision).
