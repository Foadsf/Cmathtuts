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
# 	LIBS = -lblas -llapack
# endif
#
#
# testdgtsv: testdgtsv.c
# 	$(CC) $^ $(CCFLAGS) $(LIBS)
#
#
# clean:
# 	rm -f testdgtsv


FLNAME = testdgtsv.

# path to your libraries if you have followed the instructions spsecific for these examples or /usr/local/...
BINDIR = ../../common

NBLAS = false
NGFORTRAN = false
NCBLAS = false
NLAPACK = true
NCLAPACK = false
NLAPACKE = false


include ../../common/Makefile.inc
