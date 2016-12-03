this file shows how we can call a fortran function from C
source: http://www.yolinux.com/TUTORIALS/LinuxTutorialMixingFortranAndC.html

points:
1. when passing variables from C to fortran function we pass pointers. from C side it must be pointer and from fortran the value
2. if the variables are defined on the C side you don;t have to declare a dummy in fortran side
3. in general gfortran compiler does not care if a variable/function/... has been declared or not during the compiling. it will look for it anyway during the run time.
