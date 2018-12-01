#!/bin/bash
#
#  Compile the FORTRAN file.
#
g77 -c -fno-underscoring ex1_main.f
if [ $? -ne 0 ]; then
  echo "Errors compiling ex1_main.f"
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
#  Use the G77 program to load.
#  In some cases, the C libraries may need to be included,
#  using an argument like "-lc", as well as the C math libraries,
#  using an argument like "-lm".
#
g77 ex1_main.o ex1_sub.o -lc -lm
if [ $? -ne 0 ]; then
  echo "Errors linking and loading ex1_main.o + ex1_sub.o"
  exit
fi
#
mv a.out ex1_g77_gcc
rm *.o
#
#  Run the program.
#
ex1_g77_gcc > ex1_g77_gcc_output.txt
if [ $? -ne 0 ]; then
  echo "Errors running ex1_g77_gcc."
  exit
fi
rm ex1_g77_gcc
#
echo "Program output written to ex1_g77_gcc_output.txt"
