# Abstract:
This example shows how we can call a C function from Fortran and how to pass a string properly from Fortran to C

# Source:
 http://www.yolinux.com/TUTORIALS/LinuxTutorialMixingFortranAndC.html


# Points:
1. when you pass a string from Fortran to C you actually pass two variables including a pointer to an array of single characters (string) and also the length of the array.
2. when you pass a string to C you need to first be sure that you allocate at least one letter more than the characters you need. In C first of se "\0" or NULL as the end of the string
3. common in Fortran is the equivalent of struct in C
  in C:

```c
    extern struct {
      int i;
      char c;
      ...
    } mystruct_;
```

  in Fortran

```fortran  
    integer i
    character c
    ...
    common/mystruct/ i, c, ...
```

4. when Fortran passes a variable to C function, the C function receives a pointer?
5. when you want to call a C function in Fortran you don't need to declare a dummy in the Fortran code, unlike C Fortran doesn't care if the function is not declared and then on run time it will look for the function (how about variables and structs?)
6. when passing variables, functions or srtucts from/to C/Fortran it is Case-insensitive. but you should be careful that inside each world it is case sensitive.



# Questions:
1. this pages says when you want to call a C function from fortran you need to also declare it as external but here it works properly without declaring!
  https://docs.oracle.com/cd/E19059-01/stud.9/817-6694/11_cfort.html
I think we needed a
  external doubleijk
  here, but we don't!
2. Is Fortran code written in FORTRAN 77?




# Fortran points:
1. in FORTRAN 77 and Fortran 90 (?) one can use the `write` command to print to terminal:

```fortran
        write (<deviceNumber>, (<formatSring_1>, <formatSring_2>, ...)) var_1, var_2, ...
```
where `<deviceNumber>` specifies the output (terminals, files ...). One can put `6` for the standard terminal or `*` for the default output (which should be also the stardard terminal). The `<formatSring>` specfies how each variable should be printed depending to their data type. If `*` then the default formating will be used. More formating options for integers `Iw`, reals `Fw.d` and strings `Aw` can be found. Alternatively one can put a line lable instead and then specifiy the format for mutiple `write`/`print` commands:

```fortran
10    format (<formatSring_1>, <formatSring_2>, ...)
```
