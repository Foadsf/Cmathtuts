# Cmathtuts
trying to collect all useful tutorials/examples for famous C math and algebra libraries such as BLAS, CBLAS, LAPACK, LAPACKE, CLAPACK, ATLAS, GSL...
I want to make sure if you are a C developer you can use any of these libraries without any problems regardless of your platform or hardware



issues:

1. I really do not understand the difference between LAPACK, LAPACKE and CLAPACK there might be some confusion in the tutorials
2. not able to compile ATLAS on mac OS X. a bug report was made on sourceforce: https://sourceforge.net/p/math-atlas/bugs/261/
3. for some of the BLAS and CBLAS examples the -lgfortran is requred to compile. I don't know why! (on mac OS X you need to install gfortran and then look for libgfortran.dylib and link against it while compiling)


to do:

1. make compiling/installation for all libraries for different platforms
2. check the Makefile s on other platforms(tested only on mac OS X)


sources to be studied:

1. http://physics.oregonstate.edu/~landaur/nacphy/lapack/cprogp.html
2. https://people.sc.fsu.edu/~jburkardt/c_src/clapack/clapack.html
3. http://stackoverflow.com/questions/22085277/how-to-call-clapack-from-c
4. ftp://ftp.icm.edu.pl/packages/netlib/lapack/lapacke.txt
5. https://pleiades.ucsc.edu/hyades/LAPACK
6. http://www.ccp4.ac.uk/dist/checkout/lapack-3.5.0/lapacke/example/example_DGELS_colmajor.c
7. http://www.linuxquestions.org/linux/answers/programming/installation_and_use_common_scientific_libraries_unix_part_2_lapack_and_its_wrappers_lapacke_and_atlas
8. http://theoryno3.blogspot.nl/2010/12/compiling-lapack-as-shared-library-in.html
9. http://www.dreamincode.net/forums/topic/287490-anyone-familiar-with-lapack-and-blas/
10. https://software.intel.com/sites/products/documentation/doclib/mkl_sa/11/mkl_lapack_examples/index.htm#zgesv.htm
11. https://pleiades.ucsc.edu/hyades/BLAS
12. https://software.intel.com/en-us/node/522288
13. http://stackoverflow.com/questions/17858104/what-is-the-relation-between-blas-lapack-and-atlas/17858345#17858345
14. http://stackoverflow.com/questions/1303182/how-does-blas-get-such-extreme-performance/11421344#11421344
15. http://stackoverflow.com/questions/1380371/what-are-the-most-widely-used-c-vector-matrix-math-linear-algebra-libraries-a/1452950#1452950
16. http://stackoverflow.com/questions/8206563/purpose-of-lda-argument-in-blas-dgemm/8209290#8209290
17. http://stackoverflow.com/questions/966249/scientific-math-with-functional-languages/966324#966324
18. http://stackoverflow.com/questions/24071622/replicating-blas-matrix-multiplication-performance-can-i-match-it
