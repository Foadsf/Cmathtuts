#
# Makefile for building a program that calls a routine from
# the CLAPACK Library
#
# Dr. Andrew J. Pounds
# Departments of Chemistry and Computer Science
# Mercer University
#
# November 2004
#
# modified by Foad Sojoodi Farimani
# November 2016

# CC = gcc
# FCLAPACK = /path/to/compiled/CLAPACK
# FBLAS	= /path/to/compiled/BLAS
# INCDIRS = -I$(FCLAPACK)/SRC -I$(FCLAPACK)/INCLUDE
# F2CDIR  = $(FCLAPACK)/F2CLIBS
# LDLIBS  = $(FCLAPACK)/liblapack.a \
#           $(FBLAS)/libblas.a \
#           $(F2CDIR)/libf2c.a -lm
#
# dgesv_example: dgesv_example.o
# 	$(CC) dgesv_example.o  $(LDLIBS)  -o dgesv_example
#
# dgesv_example.o: dgesv_example.c
# 	$(CC) dgesv_example.c  $(INCDIRS) -c

FLNAME = dgesv_example.

# path to your libraries if you have followed the instructions spsecific for these examples or /usr/local/...
BINDIR = ../../../common

NBLAS = true
NGFORTRAN = false
NCBLAS = false
NLAPACK = false
NCLAPACK = true
NLAPACKE = false


include ../../../common/Makefile.inc


# dgesv_example.out : dgesv_example.c
# 	gcc -c dgesv_example.c -I ../../../common/include/
# 	gfortran	../../../common/lib/liblapack.a ../../../common/lib/librefblas.a -o dgesv_example.out dgesv_example.o
