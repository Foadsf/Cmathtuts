# example2.o: example2.c
	# gcc example2.c -I../../../common/include/ -lblas -o example2.o

#if you have your libblas.a in the common folder
# example2.o: example2.c
# 	gcc example2.c -I../../../common/include/ ../../../common/lib/librefblas.a ../../../common/lib/libcblas.a ../../../common/lib/libgfortran.dylib -o example2.o


#example2.o: example2.c
#	gcc example2.c -framework Accelerate -o example2.o

# all: example2
#
# example2: example2.c
# 	gcc -c -DADD_ example2.c -I../../../common/include/
# 	gfortran ../../../common/lib/librefblas.a ../../../common/lib/libcblas.a  -o example2 example2.o


FLNAME = example2.

# path to your libraries if you have followed the instructions spsecific for these examples or /usr/local/...
BINDIR = ../../../common

NBLAS = true
NGFORTRAN = false
NCBLAS = true
NLAPACK = false
NCLAPACK = false
NLAPACKE = false


include ../../../common/Makefile.inc
