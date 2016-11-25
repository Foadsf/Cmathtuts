##
# @file      makefile
# @author    Mitch Richling <https://www.mitchr.me/>
# @Copyright Copyright 1997,2014 by Mitch Richling.  All rights reserved.
# @brief     Simple make file to build the examples in this directory.@EOL
# @Keywords
# @Std       GenericMake
#
#
#


TARGBC = blas1C

# Put your compiler and basic compile options here
ifndef CC
	CC = gcc
endif
CFLAGS   = -Wall

COMMON = ../common


# Check our platform and make sure we define the APPLE variable
# and set up the right compiler flags and libraries
PLATFORM = $(shell uname -s)
ifeq ($(PLATFORM), Darwin)
	#BLIBS = -framework Accelerate
	#or
	BLIBS = -lcblas
else
	BLIBS = -lblas
endif


TARGETS = $(TARGBC)


all : $(TARGETS)
	@echo Make Complete

blas1C : blas1C.c ../common/blaio.c ../common/blaio.h
	$(CC) $(CFLAGS) blas1C.c ../common/blaio.c -lm -I $(COMMON) $(BLLIB) -o blas1C


clean :
	rm -rf a.out *~ *.bak  $(TARGBC)
