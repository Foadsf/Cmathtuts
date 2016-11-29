/* -*- Mode:C; Coding:us-ascii-unix; fill-column:132 -*- */
/* ******************************************************************************************************************************
 */
/**
   @file      blaio.h
   @author    Mitch Richling <https://www.mitchr.me/>
   @Copyright Copyright 1999 by Mitch Richling.  All rights reserved.
   @brief     Basic Linear Algebra I/O Subroutines@EOL
   @Keywords  none
   @Std       C89

   Include file for the BLAIO (Basic Linear Algebra I/O Subroutines).  The BLAIO
   is intended to provide a very simple interface for
   printing and reading matrix and vector quantities.  The library is primarily
   useful for debugging software making use of BLAS or
   higher level numerical linear algebra libraries.

*/

/* ------------------------------------------------------------------------------------------------------------------------------
 */

// #ifdef __APPLE__
// #include <Accelerate/Accelerate.h> /* The MacOS X blas/lapack stuff */
// #else
#include <cblas.h> /* C BLAS          BLAS  */
// #endif

//#define REALT __CLPK_real
//#define REALT float
#define REALT double

#ifndef REALT
#define REALT double
#endif

void sgeprt(int m, int n, REALT, char *c);
void dgeprt(int m, int n, REALT, char *c);

/* ******************************************************************************************************************************
 */
/* This function is intended to be used as a utility function for numerical
   software working with REALT precession vectors in C.  It
   will attractively print vectors in semi-mathematical notation in an easy and
   flexible way. */
void printVector(int n, REALT *v,        /* Size and array                 */
                 int wide, int prec,     /* Width and precesion for floats */
                 char *pad,              /* Right pad string               */
                 char *ldel, char *rdel, /* Left and right delimiter       */
                 char *tag               /* Tag for first line             */
                 );

/* ******************************************************************************************************************************
 */
/* Print a matrix out with the matrix elements printed a format string like
   "%wide.precf".  Each row will be delimited by
   lidel/ridel.  The matrix will be delimited by ldel/rdel.  Each number, and
   left delimiter will be followed by the pad string.
   The first line of the matrix will have the tag string printed at the start of
   the line, and all remaining lines will have spaces
   printed to align the rest of the matrix past the tag. */
void printMatrix(const enum CBLAS_ORDER order, int n, int m,
                 REALT *a,                 /* Size and array                 */
                 int wide, int prec,       /* Width and precesion for floats */
                 char *pad,                /* Right pad string               */
                 char *ldel, char *rdel,   /* Left and right delimiter       */
                 char *lidel, char *ridel, /* Left and right INNER delimiter */
                 char *tag                 /* Tag for first line             */
                 );

/* ******************************************************************************************************************************
 */
/* Returns the number of elements it found.  Sets n and m to the size of the
 * matrix. */
int readMatrix(int *n,
               int *m,     /* Will contain size of the array after the read */
               REALT *a,   /* Will point to the data                        */
               int maxEle, /* Maximum number of elements to read            */
               char *fileName /* The file name to read the data from */
               );

/* ******************************************************************************************************************************
 */
/* Print out a matrix of chars indicateing a magnitude threshold on each
   element.  For example, print a '*' for non-zero elements,
   and a ' ' for zero elements. Both positive and negative thresholds may be
   provided for added flexibility.  The intent is that
   this will be used for visual output on a screen or printer.  If you want an
   "image", then see the function writeMatrixImage. */
void printMatrixThr(
    const enum CBLAS_ORDER order, int n, int m, REALT *a, /* Size and array */
    char *inStr, char *outStr, /* "in" string, and "out" string  */
    REALT minIn, REALT maxIn,  /* Min/Max values for "in" range. */
    char *pad,                 /* Right pad string               */
    char *ldel, char *rdel,    /* Left and right delimiter       */
    char *lidel, char *ridel,  /* Left and right INNER delimiter */
    char *tag                  /* Tag for first line             */
    );
