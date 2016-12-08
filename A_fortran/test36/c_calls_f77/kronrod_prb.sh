#!/bin/bash
#
#  Compile the FORTRAN77 library.
#
gfortran -c kronrod.f
if [ $? -ne 0 ]; then
  echo "Errors executing gfortran -c kronrod.f"
  exit
fi
#
#  Compile the C main program.
#
gcc -c kronrod_prb.c
if [ $? -ne 0 ]; then
  echo "Errors executing gcc -c kronrod_prb.c"
  exit
fi
#
#  Link the main program and library.
#
#  You can use the GFORTRAN command to link:
#
# gfortran kronrod_prb.o kronrod.o
# if [ $? -ne 0 ]; then
#   echo "Errors executing gcc -c kronrod_prb.c"
#   exit
# fi
#
#  OR, you can use the GCC command to link,
#  if you include the -lgfortran library,
#
gcc kronrod_prb.o kronrod.o -lgfortran
if [ $? -ne 0 ]; then
  echo "Errors executing gcc -c kronrod_prb.c"
  exit
fi
#
#  Run the program.
#
mv a.out kronrod_prb
./kronrod_prb > kronrod_prb_output.txt
#
#  Clean up.
#
rm kronrod.o
rm kronrod_prb.o
rm kronrod_prb
echo "Test output written to kronrod_prb_output.txt"
#
#  Terminate.
#
exit
