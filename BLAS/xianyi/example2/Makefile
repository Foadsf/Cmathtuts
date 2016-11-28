# time_dgemm.o: time_dgemm.c
	# gcc time_dgemm.c -lblas -o time_dgemm.o

# time_dgemm.o: time_dgemm.c
# 	gcc time_dgemm.c ../../../common/lib/librefblas.a ../../../common/lib/libgfortran.dylib -o time_dgemm.o

# all: time_dgemm
#
# time_dgemm: time_dgemm.c
# 	gcc -c -DADD_ time_dgemm.c
# 	gfortran ../../../common/lib/librefblas.a  -o time_dgemm time_dgemm.o


FLNAME = time_dgemm.

# path to your libraries if you have followed the instructions spsecific for these examples or /usr/local/...
BINDIR = ../../../common

NBLAS = true
NGFORTRAN = false
NCBLAS = false
NLAPACK = false
NCLAPACK = false
NLAPACKE = false


include ../../../common/Makefile.inc
