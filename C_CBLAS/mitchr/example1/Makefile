# blas1C : blas1C.c
# 	gcc -I../../../common/include/ blas1C.c ../common/blaio.c  -I../common ../../../common/lib/librefblas.a ../../../common/lib/libcblas.a -o blas1C.o

TARGBC = blas1C.out

FC       = gfortran
CC       = gcc
FFLAGS   = -Wall -c
CFLAGS   = -Wall

BLLIB  = ../../../common/lib/librefblas.a
LPLIB  = ../../../common/lib/libcblas.a
LPINC  = -I../../../common/include/ -I../common/

TARGETS = $(TARGBC)

all : $(TARGETS)
	@echo Make Complete

blas1C.out : blas1C.c ../common/blaio.c ../common/blaio.h
	$(CC) $(CFLAGS) $(LPINC) blas1C.c ../common/blaio.c -lm $(BLLIB) $(LPLIB) -o blas1C.out


clean :
	rm -rf a.out *~ *.bak $(TARGBF) $(TARGBC) $(TARGLF) $(TARGLC)
