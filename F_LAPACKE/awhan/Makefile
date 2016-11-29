# example.o: example.c
# 	# gcc example.c -I ../../common/include/ ../../common/lib/librefblas.a ../../common/lib/libcblas.a ../../common/lib/liblapack.a ../../common/lib/liblapacke.a /usr/local/Cellar/gcc/6.2.0/lib/gcc/6/libgfortran.a
# 		gcc example.c -I ../../common/include/ ../../common/lib/liblapacke.dylib


FLNAME = example.

# path to your libraries if you have followed the instructions spsecific for these examples or /usr/local/...
BINDIR = ../../common

NBLAS = false
NGFORTRAN = false
NCBLAS = false
NLAPACK = false
NCLAPACK = false
NLAPACKE = true


include ../../common/Makefile.inc

# example.out :example.c
# 	gcc -c example.c -I ../../common/include/
# 	gfortran ../../common/lib/liblapacke.a -o example.out example.o
