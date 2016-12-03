#!/bin/bash
#
gfortran -fno-underscoring -c kronrod_prb.f
if [ $? -ne 0 ]; then
  echo "Errors compiling kronrod_prb.f"
  exit
fi
#
gcc -c -g kronrod.c
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
