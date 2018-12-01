#!/bin/bash
#
#  Compile the C file.
#
gcc -c ex2_main.c
if [ $? -ne 0 ]; then
  echo "Errors compiling ex2_main.c"
  exit
fi
#
#  Compile the FORTRAN file.
#
fort -c ex2_sub.f90
if [ $? -ne 0 ]; then
  echo "Errors compiling ex2_sub.f90"
  exit
fi
#
gcc ex2_main.o ex2_sub.o -lm -lfor
if [ $? -ne 0 ]; then
  echo "Errors linking and loading ex2_main.o + ex2_sub.o"
  exit
fi
#
mv a.out ex2_gcc_fort
rm *.o
#
#  Run the program.
#
ex2_gcc_fort > ex2_gcc_fort_output.txt
if [ $? -ne 0 ]; then
  echo "Errors running ex2_gcc_fort"
  exit
fi
rm ex2_gcc_fort
#
echo "Program output written to ex2_gcc_fort_output.txt"
