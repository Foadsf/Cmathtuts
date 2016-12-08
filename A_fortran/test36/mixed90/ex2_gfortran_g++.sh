#!/bin/bash
#
#  Compile the FORTRAN file.
#
#  The "fno-underscoring" option keeps the FORTRAN compiler from adding underscores
#  to the names of the compiled routines.
#
gfortran -c -fno-underscoring ex2_main.f90
if [ $? -ne 0 ]; then
  echo "Errors compiling ex2_main.f90"
  exit
fi
#
#  Compile the C++ file.
#  Every routine in the file that is to be accessed by a FORTRAN routine must be
#  declared with the "extern "C" {}" property, so that the C++ compiler doesn't
#  do weird things to the names.
#
g++ -c ex2_sub.cpp
if [ $? -ne 0 ]; then
  echo "Errors compiling ex2_sub.cpp"
  exit
fi
#
#  Use GFORTRAN to load, but include the libraries that G++ needs.
#
gfortran ex2_main.o ex2_sub.o -lstdc++ -lm
if [ $? -ne 0 ]; then
  echo "Errors linking and loading ex2_main.o + ex2_sub.o"
  exit
fi
#
mv a.out ex2_gfortran_g++
rm *.o
#
#  Run the program.
#
ex2_gfortran_g++ > ex2_gfortran_g++_output.txt
if [ $? -ne 0 ]; then
  echo "Errors running ex2_gfortran_g++."
  exit
fi
rm ex2_gfortran_g++
#
echo "Program output written to ex2_gfortran_g++_output.txt"
