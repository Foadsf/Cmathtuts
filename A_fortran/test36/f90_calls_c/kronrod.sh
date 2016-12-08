#!/bin/bash
#
gfortran -c kronrod_prb.f90
if [ $? -ne 0 ]; then
  echo "Errors compiling kronrod_prb.f90"
  exit
fi
#
gcc -c kronrod.c
if [ $? -ne 0 ]; then
  echo "Errors compiling kronrod_prb.c"
  exit
fi
#
gfortran kronrod_prb.o kronrod.o -lm
if [ $? -ne 0 ]; then
  echo "Errors linking and loading kronrod_prb.o + kronrod.o"
  exit
fi
rm kronrod_prb.o
rm kronrod.o
#
mv a.out kronrod
./kronrod > kronrod_output.txt
if [ $? -ne 0 ]; then
  echo "Errors running kronrod"
  exit
fi
rm kronrod
#
echo "Test program output written to kronrod_output.txt."
