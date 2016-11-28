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
