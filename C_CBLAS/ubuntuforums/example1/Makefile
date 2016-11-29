# example1.o: example1.c
	# gcc example1.c -I../../../common/include/ -lblas -o example1.o

# all: example1
#
# #if you have your libblas.a in the common folder
# example1: example1.c
# 	# gcc example1.c -I../../../common/include/ ../../../common/lib/librefblas.a ../../../common/lib/libcblas.a  -o example1.o
# 	gcc -c -DADD_ example1.c -I../../../common/include/
# 	gfortran ../../../common/lib/librefblas.a ../../../common/lib/libcblas.a  -o example1 example1.o


#sample3.o: sample3.c
#	gcc sample3.c -framework Accelerate -o sample3.o

FLNAME = example1.

# path to your libraries if you have followed the instructions spsecific for these examples or /usr/local/...
BINDIR = ../../../common

NBLAS = true
NGFORTRAN = false
NCBLAS = true
NLAPACK = false
NCLAPACK = false
NLAPACKE = false


include ../../../common/Makefile.inc
