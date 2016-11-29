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
#
#
# zgesv_example: zgesv_example.o
# 	$(CC) zgesv_example.o  $(LDLIBS)  -o zgesv_example
#
# zgesv_example.o: zgesv_example.c
# 	$(CC) zgesv_example.c  $(INCDIRS) -c


FLNAME = zgesv_example.

# path to your libraries if you have followed the instructions spsecific for these examples or /usr/local/...
BINDIR = ../../../common

NBLAS = true
NGFORTRAN = false
NCBLAS = false
NLAPACK = false
NCLAPACK = true
NLAPACKE = false


include ../../../common/Makefile.inc
