to do:
1. write a how to for compiling CBLAS on mac OS X
2. write a ruby Homebrew formula for CBLAS


instructions:

to compile these examples under ubuntu :
1. you need to have the BLAS from netlib:
  1.1. download latest version of the BLAS from here: http://www.netlib.org/blas/
  1.2. uncompress and got to the folder in the terminal and run make
    make
  1.3. look for the file named blas_LINUX.a and save the address to this file
2. compile the netlib cblas
  2.1. download CBLAS from the same page
  2.2. uncompress
  2.3. open the file Makefile.in
  2.4. look for the line BLLIB = .../blas_LINUX.a
  2.5. put the address you had in step one here
  2.6. go to the terminal in unzipped cblas folder and run make
3. look for the cblas.h file in the include folder and when you run the gcc link against this folder
4. you can copy the built files to the default folders so later the compiler automatically finds the files
  4.1. copy cblas_f77.h and cblas.h to /usr/local/include/
  4.2. copy blas_LINUX.a and cblas_LINUX.a to /usr/local/lib
source: http://avulanov.blogspot.nl/2015/03/cblas-compilation-as-shared-library.html
