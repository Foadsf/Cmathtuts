#!/bin/bash
#
#  Compile the C file.
#
cc -c ex2_main.c
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
cc ex2_main.o ex2_sub.o -lm -lfor
if [ $? -ne 0 ]; then
  echo "Errors linking and loading ex2_main.o + ex2_sub.o"
  exit
fi
#
mv a.out ex2_cc_fort
rm *.o
#
#  Run the program.
#
ex2_cc_fort > ex2_cc_fort_output.txt
if [ $? -ne 0 ]; then
  echo "Errors running ex2_cc_fort"
  exit
fi
rm ex2_cc_fort
#
echo "Program output writtento ex2_cc_fort_output.txt"
