
instructions:

a. compiling from source code:

1. download the latest version of lapack from netlib website: http://www.netlib.org/lapack/
2. open the make.inc.example rename it to make.inc
  2.1. on mac OS X change line below:
    OPTS     = -O2 -frecursive
  to
    OPTS     = -O3 -frecursive -pipe
  2.2. save and exit
3. make blaslib -> to get Reference BLAS librefblas.a
4. make cblaslib -> to get CBLAS libcblas.a
5. make cblas_example -> To complie CBLAS example
6. make lapacklib -> To get LAPACK liblapack.a and libtmglib.a
7. make —>  to run ALL testings
8. cd LAPACKE and make --> to get LAPACKE liblapacke.a

b. using repositories:

1. ubuntu:
  sudo apt-get install liblapack-dev
2. mac OS X:
  brew install lapack

c. with other libraries:
  1. openblas?
  2. atlas?

d. built in OS:
1. on mac OS X use Accelerate framework to compile
  gcc foo.c -framework Accelerate


intel examples:
1. https://software.intel.com/sites/products/documentation/doclib/mkl_sa/11/mkl_lapack_examples/sgesv_ex.c.htm
2. https://software.intel.com/sites/products/documentation/doclib/mkl_sa/11/mkl_lapack_examples/zgeev_ex.c.htm
