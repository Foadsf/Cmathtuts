BLAS is not a library but an API, specification or interface which gives you the ability to use specific functions for linear algebra, including vector-vector, vector-matrix and matrix-matrix operations. There are several implementations of BLAS including the original Netlib BLAS (formerly BellLabs), OpenBLAS/GotoBLAS2, ATLAS, GSL, ...


To compile these examples you need to have any of the BLAS implementations installed. to do this you have several possibilities:
1. Use existing capabilities/repositories of your operating system: if you use these options then you can compile your C code with -lblas linker and the compiler automatically knows where to look for libblas.* (e.g. gcc foo.c -lblas)
  1.1. ubuntu: on ubuntu you can install by
  
    sudo apt-get install libblas-dev 

  1.2. mac OS X: Acceleration framework is already built in the OS just link against the frame work
      gcc foo.c -framework Accelerate
    or
      gcc foo.c -lblas


2. compile the Netlib BLAS yourself:
  2.1. compile a C code if you have followed this option:
  following this option you will have a static library libblas.a or librefblas.a which is an archived collection of object files *.o compiled from Netlib BLAS fortran subroutines. when we want to compile a C code which want to call one of those routines, we also need to link to the gfortran library libgfortran.* or use gfortran to compile the object files so I will put two make files here:
    all:
      gcc -c foo.c
      gcc -o bar.out foo.o -L path/to/libgfortran.*/ -lgfortran -L path/to/libblas.a -lblas
  or alternatively compile the code directly with gfortran:
    all:
      gcc -c foo.c
      gfortran -o bar.out foo.o -L path/to/libblas.a -lblas
  or
    all:
      gcc foo.c bar.out  -L path/to/libgfortran.*/ -lgfortran -L path/to/libblas.a -lblas
  2.2. compile:
      2.2.1. compile using the unix bash script provided for you in the BZ_common folder. this will provide you with a libblas.a file inside the BZ_common/bin/lib which you can link against later
      2.2.2. compile it your self:
        a. download the latest from netlib: http://www.netlib.org/blas/
        b. unarchive
        c. run make from terminal
        d. rename the blas_LINUX.a to libblas.a
        e. if you want your compiler to know automatically where to look for the library copy the libblas.a file after to a folder you know. (e.g. /usr/local/lib/)
        d. compile your C code linking against this folder
          compiler bla...bla -L your/folder/ -lblas

3. install it with other libraries
  3.1. install it with ATLAS
  3.2. install it with openblas?
  3.3. install it with LAPACK

useful notes:
to use BLAS fortran routine inside the C code you need to declare the BLAS fortran routine inside the C code first. for example if foo is a fortran routine with output and inputs, you need to declare it in yor C code as:
  output foo_(inputs)
and then use it as foo_ inside the code. [source](http://stackoverflow.com/questions/22085277/how-to-call-clapack-from-c)



list of functions used in these examples:
1. dgemm : multiplies two matrices
2. dscal : scales a vector/array
3. ddot : dot product of two vector/array

complete list of BLAS routines/subroutines:


sources to be studied:
1. http://www.christophlassner.de/using-blas-from-c-with-row-major-data.html
  this sources claims that calling BLAS fortran routines directly is faster than using CBLAS
