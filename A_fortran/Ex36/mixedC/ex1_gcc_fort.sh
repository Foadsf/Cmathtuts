#!/bin/bash
#
#  Compile the C file.
#
gcc -c ex1_main.c
if [ $? -ne 0 ]; then
  echo "Errors compiling ex1_main.c"
  exit
fi
#
#  Compile the FORTRAN file.
#
fort -c -assume nounderscore ex1_sub.f90
if [ $? -ne 0 ]; then
  echo "Errors compiling ex1_sub.f90"
  exit
fi
#
#  Use the GCC program to load.
#  In some cases, the FORTRAN libraries may need to be included,
#  using an argument like "-lfor".
#  The C math libraries may need to be included, with "-lm".
#
#gcc ex1_main.o ex1_sub.o -lfor
#
gcc ex1_main.o ex1_sub.o -lfor -lm
if [ $? -ne 0 ]; then
  echo "Errors linking and loading ex1_main.o + ex1_sub.o"
  exit
fi
#
mv a.out ex1_gcc_fort
rm *.o
#
#  Run the program.
#
ex1_gcc_fort > ex1_gcc_fort_output.txt
if [ $? -ne 0 ]; then
  echo "Errors running ex1_gcc_fort"
  exit
fi
rm ex1_gcc_fort
#
echo "Program output written to ex1_gcc_fort_output.txt"
