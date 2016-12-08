#!/bin/bash
#
#  Compile the FORTRAN file.
#
f77 -c -fno-underscoring ex1_main.f
if [ $? -ne 0 ]; then
  echo "Errors compiling ex1_main.f"
  exit
fi
#
#  Compile the C file.
#
cc -c ex1_sub.c
if [ $? -ne 0 ]; then
  echo "Errors compiling ex1_sub.c"
  exit
fi

#
#  Use the F77 program to load.
#  In some cases, the C libraries may need to be included,
#  using an argument like "-lc", as well as the C math libraries,
#  using an argument like "-lm".
#
f77 ex1_main.o ex1_sub.o -lc -lm
if [ $? -ne 0 ]; then
  echo "Errors linking and loading ex1_main.o + ex1_sub.o"
  exit
fi
#
mv a.out ex1_f77_cc
rm *.o
#
#  Run the program.
#
ex1_f77_cc > ex1_f77_cc_output.txt
if [ $? -ne 0 ]; then
  echo "Errors running ex1_f77_cc."
  exit
fi
rm ex1_f77_cc
#
echo "Program output written to ex1_f77_cc_output.txt"
