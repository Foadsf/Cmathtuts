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

TARGBF = blas1F blas2F blas3F
TARGBC = blas1C blas2C blas3C blas2bC
TARGLF = slvSysF symEigF triSlvF
TARGLC = slvSysC

# Put your compiler and basic compile options here
FC       = gfortran
CC       = gcc
FFLAGS   = -Wall
CFLAGS   = -Wall

# Put your Fortran 77 LAPACK and BLAS compile and link options here!
# What is below works on my stock Debian box, and works on my OS X
# 10.9.2 system when I comment out the first three and uncomment
# APLKRZ.
BLLIB  = -lblas
LPLIB  = -llapack
LPINC  = -I/usr/include/atlas
#APLKRZ  = -framework Accelerate

# You will need a Fortran compiler for the TARG*F targets.
TARGETS = $(TARGBC) $(TARGBF) $(TARGLF) $(TARGLC)
#TARGETS = $(TARGBC) $(TARGLC)

all : $(TARGETS)
	@echo Make Complete

blas1C : blas1C.c blaio.c blaio.h
	$(CC) $(CFLAGS) $(APLKRZ) blas1C.c blaio.c -lm $(BLLIB) -o blas1C

blas1F : blas1F.f blaio.f
	$(FC) $(FFLAGS) blas1F.f blaio.f $(BLLIB) -o blas1F

blas2bC : blas2bC.c blaio.c blaio.h
	$(CC) $(CFLAGS) $(APLKRZ) blas2bC.c blaio.c -lm  $(BLLIB) -o blas2bC

blas2C : blas2C.c blaio.c blaio.h
	$(CC) $(CFLAGS) $(APLKRZ) blas2C.c blaio.c   -lm $(BLLIB) -o blas2C

blas2F : blas2F.f blaio.f
	$(FC) $(FFLAGS) blas2F.f blaio.f $(BLLIB) -o blas2F

blas3C : blas3C.c blaio.c blaio.h
	$(CC) $(CFLAGS) $(APLKRZ) blas3C.c blaio.c  -lm $(BLLIB) -o blas3C

blas3F : blas3F.f blaio.f
	$(FC) $(FFLAGS) blas3F.f blaio.f $(BLLIB) -o blas3F

slvSysC : slvSysC.c blaio.c blaio.h
	$(CC) $(CFLAGS) $(APLKRZ) $(LPINC) slvSysC.c blaio.c  -lm $(LPLIB) $(BLLIB) -o slvSysC

slvSysF : slvSysF.f blaio.f
	$(FC) $(FFLAGS) slvSysF.f blaio.f $(LPLIB) $(BLLIB) -o slvSysF

symEigF : symEigF.f blaio.f
	$(FC) $(FFLAGS) symEigF.f blaio.f $(LPLIB) $(BLLIB) -o symEigF

triSlvF : triSlvF.f blaio.f
	$(FC) $(FFLAGS) triSlvF.f blaio.f $(LPLIB) $(BLLIB) -o triSlvF

clean :
	rm -rf a.out *~ *.bak $(TARGBF) $(TARGBC) $(TARGLF) $(TARGLC)
