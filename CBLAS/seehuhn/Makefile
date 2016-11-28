#
# ifndef CC
# 	CC = gcc
# endif
#
# CCFLAGS= -lm
#
#
#
#
#
# # Check our platform and make sure we define the APPLE variable
# # and set up the right compiler flags and libraries
# PLATFORM = $(shell uname -s)
# ifeq ($(PLATFORM), Darwin)
# 	LIBS = -framework Accelerate
# 	#or
# 	#LIBS = -lcblas
# else
# 	LIBS = -lblas
# endif
#
#
# testblas: testblas.c
# 	$(CC) $^ $(CCFLAGS) $(LIBS)
#
#
# clean:
# 	rm -f testblas


FLNAME = testblas.

# path to your libraries if you have followed the instructions spsecific for these examples or /usr/local/...
BINDIR = ../../common

NBLAS = true
NGFORTRAN = true
NCBLAS = true
NLAPACK = false
NCLAPACK = false
NLAPACKE = false


include ../../common/Makefile.inc
