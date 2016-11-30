this file shows how we can call a C function from fortran
source: http://www.yolinux.com/TUTORIALS/LinuxTutorialMixingFortranAndC.html


points:
1. when you pass a string from fortran to C you actually pass two variables including an array of single characters and also the length of the array.
2. when you pass a string to C you need to first be sure that you allocate at least one letter more than the characters you need and in C first of se "\0" or NULL as the end of the string
3. common is the equivalent of struct in C
  in C:
    extern struct {
      int i;
      char c;
      ...
    } mystruct_;
  in fortran
    integer i
    character c
    ...
    common/mystruct/ i, c, ...

4. when fortran passes a variable to C function, the C function receives a pointer



questions:
1. this pages says when you want to call a C function from fortran you need to also declare it as external but here it works properly without declaring!
  https://docs.oracle.com/cd/E19059-01/stud.9/817-6694/11_cfort.html
I think we needed a
  external doubleijk
  here, but we don't!
