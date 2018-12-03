on ubuntu install BLAS via 
    sudo apt-get install libblas-dev
and then compile with 
    gcc foo.c -lblas

source: https://www.ibm.com/support/knowledgecenter/SSLTBW_2.1.0/com.ibm.zos.v2r1.cbcpx01/atlasexample1.htm

issues:

1. the Makefile works but not properly!
2. I don't know why this specific example needs -lgfortran on ubuntu


from source:
Examples - Compiling, linking, and running a simple matrix multiplication

This simple sample achieves a multiplication of two matrices, A and B. A and B have elements randomly generated with values between 0 and 1. The multiplication is achieved in the following ways:
by calling dgemm BLAS functionality provided by ATLAS
by a manual calculation of the same
The resulting matrices C and D will contain the same elements.
Sample output produced by all executables across all platforms and architectures should look like this:

Matrix A has 3 rows and 6 columns:
0.566 0.974 0.202 0.941 0.294 0.427
0.580 0.539 0.772 0.248 0.832 0.848
0.080 0.533 0.434 0.163 0.576 0.416

Matrix B has 6 rows and 4 columns:
0.309 0.316 0.569 0.182
0.725 0.389 0.472 0.649
0.448 0.368 0.354 0.665
0.994 0.740 0.649 0.616
0.133 0.906 0.447 0.590
0.773 0.774 0.893 0.913

Matrix C has 3 rows and 4 columns:
2.276 1.926 1.978 2.013
1.928 2.270 2.148 2.387
1.165 1.356 1.185 1.469

Matrix D has 3 rows and 4 columns:
2.276 1.926 1.978 2.013
1.928 2.270 2.148 2.387
1.165 1.356 1.185 1.469

Pay attention to the fact that matrices C and D are congruent.

Also note that matrix data is organized or ordered in the Fortran way, namely columns major.

This program contains a C invocation of the Fortran BLAS function dgemm_
