to compile these examples:
gcc foo.c -llapack

1. download the latest version from netlib website
2. open the make.inc
  2.1. on mac OS X change line below:
    OPTS     = -O2 -frecursive
  to
    OPTS     = -O3 -frecursive -pipe
3. make blaslib -> to get Reference BLAS librefblas.a
4. make cblaslib -> to get CBLAS libcblas.a
5. make cblas_example -> To complie CBLAS example
6. make lapacklib -> To get LAPACK liblapack.a and libtmglib.a
7. make —>  to run ALL testings
8. cd LAPACKE and make --> to get LAPACKE liblapacke.a
installation on ubuntu:

1. sudo apt-get install liblapack-dev



intel examples:
1. https://software.intel.com/sites/products/documentation/doclib/mkl_sa/11/mkl_lapack_examples/sgesv_ex.c.htm
2. https://software.intel.com/sites/products/documentation/doclib/mkl_sa/11/mkl_lapack_examples/zgeev_ex.c.htm
