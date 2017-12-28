# Description:
FORTRAN/Fortran is obviously a different programing language from C. However, considering it has been the de facto programing language for mathematical and algebraic calculations, many legacy libraries, including original implementations BLAS and LAPACK APIs are written in Fortran. Of course you can use the libraries mentioned in this tutorial without knowing how to do mixed Fortran and C programing, but knowing that not only will help you a lot understanding what happening under the hood, but also gives you the ability to modify or even write your own Fortran subroutines if required. not to mention it opens the door to tens of other libraries out there written in Fortran. Fortran is historically the gold standard programing language for mathematical operations and learning Fortran for you as a C programmer will be life changing.

# keywords:
* mixed language programing
* call Fortran functions/subroutines from C/C++
* interface the function calls

# requirements
you need to have Fortran and C compilers. Preferably  GNU gcc and gfortran

# Points:
1. name of the routines/subroutines/functions and structs/commons in some versions or dialects of Fortran must be in small letters and an underscore _ must be added to the C function

# Sources to be studied:
3. http://arnholm.org/software/cppf77/cppf77.htm --> test35
4. http://www.nag.com/lapack-ex/node1.html#sec:Introduction
5. http://physics.oregonstate.edu/~landaur/nacphy/lapack/fortran.html
6. http://www.fortran.com/the-fortran-company-homepage/fortran-tools-libraries-and-application-software/ --> Fortran Tools, Libraries, and Application Software
7. iso_c_binding
8. https://docs.oracle.com/cd/E19059-01/stud.9/817-6694/11_cfort.html
9. https://www.math.utah.edu/software/c-with-fortran.html
10. https://software.intel.com/en-us/forums/intel-visual-fortran-compiler-for-windows/topic/290051
11. http://luthaf.github.io/calling-c++-from-fortran.html
12. http://alignment.hep.brandeis.edu/Software/Mixing/Mixing_Manual.html
13. http://www.fortran.bcs.org/2002/interop.htm
14. http://www.pgroup.com/userforum/viewtopic.php?p=7398&sid=2a05571a922045c6c4ae26d65bbf9fba
15. http://www.unidata.ucar.edu/software/netcdf/examples/programs/
16. http://people.sc.fsu.edu/~jburkardt/c_src/mixed/mixed.html
17. https://docs.oracle.com/cd/E19422-01/819-3685/11_cfort.html
18. cfortran--> http://www-zeus.desy.de/~burow/cfortran/


# To do:

1. Change the naming scheme from test-- to example-- and add 0 before the single digit numbers so it sorts correctly  


# Issues:
1. test22 result not correct
2. test19 does not compile
3. test24 not compiling
4. test4 not compiling
5. test34 not compiling
