#!/bin/bash
#
#  Compile the FORTRAN file.
#
fort -c -assume nounderscore ex1_main.f90
if [ $? -ne 0 ]; then
  echo "Errors compiling ex1_main.f90"
  exit
fi
#
#  Compile the C file.
#
gcc -c ex1_sub.c
if [ $? -ne 0 ]; then
  echo "Errors compiling ex1_sub.c"
  exit
fi
#
#  Use the FORT program to load.
#  In some cases, the C libraries may need to be included,
#  using an argument like "-lc", as well as the C math libraries,
#  using an argument like "-lm".
#
fort ex1_main.o ex1_sub.o -lc -lm
if [ $? -ne 0 ]; then
  echo "Errors linking and loading ex1_main.o + ex1_sub.o"
  exit
fi
#
mv a.out ex1_fort_gcc
rm *.o
#
#  Run the program.
#
ex1_fort_gcc > ex1_fort_gcc_output.txt
if [ $? -ne 0 ]; then
  echo "Errors running ex1_fort_gcc."
  exit
fi
rm ex1_fort_gcc
#
echo "Program output written to ex1_fort_gcc_output.txt"
