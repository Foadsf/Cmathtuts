fortran is actually a complete programing language separate from C, however considering it is the de facto programing language for mathematical and algebraic calculations, many legacy libraries, including BLAS and LAPACK are written in fortran. Of course you can use the libraries mentioned in this tutorial without knowing how to mix fortran and C, but knowing that not only will help you a lot to understand what happening under the hood but also gives you the ability to modify or even write your own fortran subroutines if required. not to mention it opens the door to tens of other libraries out there written in fortran. fortran is historically de facto programing language for mathematical operations and learning fortran for you as a C programer will be life changing.

keywords:
mixed language programing
call fortran functions/subroutines
interface the function calls

source:
1. http://www.yolinux.com/TUTORIALS/LinuxTutorialMixingFortranAndC.html


sources to be looked at:
1. https://msdn.microsoft.com/en-us/library/aa293328(v=vs.60).aspx
2. http://docs.cray.com/books/S-2179-52/html-S-2179-52/ppgzmrwh.html
3. http://arnholm.org/software/cppf77/cppf77.htm
4. http://www.nag.com/lapack-ex/node1.html#sec:Introduction
5. http://physics.oregonstate.edu/~landaur/nacphy/lapack/fortran.html
6. http://www.fortran.com/the-fortran-company-homepage/fortran-tools-libraries-and-application-software/
7. iso_c_binding
8. https://docs.oracle.com/cd/E19059-01/stud.9/817-6694/11_cfort.html
9. https://www.math.utah.edu/software/c-with-fortran.html

points:

1. name of the routines/subroutines/functions and structs/commons in some versions or dialects of fortran must be in small letters and and an underscore _ must be added to the C function
