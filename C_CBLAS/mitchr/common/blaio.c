/* -*- Mode:C; Coding:us-ascii-unix; fill-column:132 -*- */
/* ******************************************************************************************************************************
 */
/**
   @file      blaio.c
   @author    Mitch Richling <https://www.mitchr.me/>
   @Copyright Copyright 1993 by Mitch Richling.  All rights reserved.
   @brief     matrix/vector I/O@EOL
   @Keywords  blas numerical linear algebra matrix vector
   @Std       C89

   A few simple matrix/vector print/read functions useful for printing small
   test cases and debugging

*/

/* ------------------------------------------------------------------------------------------------------------------------------
 */

#include "blaio.h"
#include <ctype.h>  /* Char classes    ISOC  */
#include <stdio.h>  /* I/O lib         ISOC  */
#include <stdlib.h> /* Standard Lib    ISOC  */
#include <string.h> /* Strings         ISOC  */

/* ******************************************************************************************************************************
 */
void printMatrixUbr(
    const enum CBLAS_ORDER order, /* CBLAS row order */
    int n, int m, REALT *a, /* Size and array */
    char *inStr, char *outStr, /* "in" string, and "out" string */
    REALT minIn, REALT maxIn, /* Min/Max values for "in" range. */
    int wide, int prec, /* Width and precesion for floats */
    int *rowPerm, int *colPerm,
    char prtMode, /* b=bitmap, V=values, *=in/out) */
    char *fileName, int maskMode, /* L=below diag, U=above diag, D=Diagnal,
                                     M=Mask, 0=NONE, \0=NONE  */
    char *mask,
    char *pad, /* Right pad string */
    char *ldel, char *rdel, /* Left and right delimiter */
    char *lidel, char *ridel, /* Left and right INNER delimiter */
    char *tag /* Tag for first line */
    );

/* ******************************************************************************************************************************
 */
void printVector(int n, REALT *v, int wide, int prec, char *pad, char *ldel,
                 char *rdel, char *tag) {
  printMatrixUbr(CblasRowMajor, 1, n, v, NULL, NULL, 0.0, 0.0, wide, prec, NULL,
                 NULL, 'V', NULL, '0', NULL, pad, ldel, rdel, "", "", tag);
} /* end func printVector */

/* ******************************************************************************************************************************
 */
void printMatrix(const enum CBLAS_ORDER order, int n, int m, REALT *a, int wide,
                 int prec, char *pad, char *ldel, char *rdel, char *lidel,
                 char *ridel, char *tag) {
  printMatrixUbr(order, n, m, a, NULL, NULL, 0.0, 0.0, wide, prec, NULL, NULL,
                 'V', NULL, '0', NULL, pad, ldel, rdel, lidel, ridel, tag);
} /* end func printMatrix */

/* ******************************************************************************************************************************
 */
void printMatrixThr(const enum CBLAS_ORDER order, int n, int m, REALT *a,
                    char *inStr, char *outStr, REALT minIn, REALT maxIn,
                    char *pad, char *ldel, char *rdel, char *lidel, char *ridel,
                    char *tag) {
  printMatrixUbr(order, n, m, a, inStr, outStr, minIn, maxIn, 0, 0, NULL, NULL,
                 '*', NULL, '0', NULL, pad, ldel, rdel, lidel, ridel, tag);
} /* end func printMatrixThr*/

/* ******************************************************************************************************************************
 */
void printMatrixUbr(const enum CBLAS_ORDER order, /* CBLAS row order */
                    int n, int m, REALT *a, /* Size and array */
                    char *inStr,
                    char *outStr, /* "in" string, and "out" string    */
                    REALT minIn,
                    REALT maxIn,        /* Min/Max values for "in" range.   */
                    int wide, int prec, /* Width and precesion for floats   */
                    int *rowPerm, int *colPerm, /* Permute rows i->xx[i] */
                    char prtMode,   /* b=bitmap, V=values, *=in/out     */
                    char *fileName, /* if NULL, stdout.                 */
                    int maskMode,   /* L, U, D, M-Mask, 0=NONE          */
                    char *mask,     /* Mask (same size as a) ctrl print */
                    char *pad,      /* Right pad string                 */
                    char *ldel, char *rdel, /* Left and right delimiter */
                    char *lidel,
                    char *ridel, /* Left and right INNER delimiter   */
                    char *tag    /* Tag for first line               */
                    ) {
  int i, j, iP, jP;
  int k, ldelLen, tagLen, cIdx, prtPerMask;
  REALT pVal;

  if (inStr == NULL)
    inStr = "*";
  if (outStr == NULL)
    outStr = " ";
  if (wide < 0)
    wide = 5;
  if (prec < 0)
    prec = 2;
  if (ldel == NULL)
    ldel = "[";
  if (ridel == NULL)
    ridel = "]";
  if (lidel == NULL)
    lidel = "[";
  if (rdel == NULL)
    rdel = "]";
  if (pad == NULL)
    pad = " ";
  if (tag == NULL)
    tag = "";

  ldelLen = strlen(ldel);
  tagLen = strlen(tag);
  for (j = 0; j < n; j++) {
    if (j == 0)
      printf("%s%s%s%s", tag, ldel, lidel, pad);
    else {
      for (k = 0; k < tagLen; k++)
        printf(" ");
      for (k = 0; k < ldelLen; k++)
        printf(" ");
      printf("%s%s", lidel, pad);
    } /* end if/else */
    for (i = 0; i < m; i++) {
      if (colPerm != NULL)
        iP = colPerm[i];
      else
        iP = i;
      if (rowPerm != NULL)
        jP = rowPerm[j];
      else
        jP = j;
      if (order == CblasColMajor)
        cIdx = n * iP + jP;
      else
        cIdx = m * jP + iP;
      pVal = a[cIdx];
      // Figure out what the mask has to do with printing..
      if (maskMode == '0')
        prtPerMask = 1;
      else if (maskMode == 'L')
        prtPerMask = (iP < jP); // Row order specific!  Fix this.
      else if (maskMode == 'D')
        prtPerMask = (iP == jP);
      else if (maskMode == 'U')
        prtPerMask = (iP > jP); // Row order specific!  Fix this.
      else if (maskMode == 'M')
        prtPerMask = mask[cIdx];
      else
        prtPerMask = 1;

      if (prtMode == '*') {
        if (prtPerMask && (pVal >= minIn) && (pVal <= maxIn))
          printf("%s%s", inStr, pad);
        else
          printf("%s%s", outStr, pad);
      } else {
        if (prtPerMask)
          printf("%*.*f%s", wide, prec, pVal, pad);
        else
          printf("%*s%s", wide, outStr, pad);
      } /* end if/else */
    }   /* end for */
    if (j == n - 1)
      printf("%s%s\n", ridel, rdel);
    else
      printf("%s\n", ridel);
  } /* end for */
} /* end func printMatrixUbr*/

/* ******************************************************************************************************************************
 */
int readMatrix(int *n, int *m, REALT *a, int maxEle, char *fileName) {
  int inComment;
  int numNumbers;
  int ch;
  int lengthOfNumber;
  char numberBuffer[256];
  FILE *FP;

  FP = fopen(fileName, "r");
  if (FP == NULL)
    return 1;
  inComment = 0;
  lengthOfNumber = -1;
  numNumbers = 0;
  while (EOF != (ch = getc(FP))) {
    if (ch == '#')
      inComment = 1; /* Enter comment upon # char. */
    if (inComment && (ch < 20))
      inComment = 0; /* Break out of comment upon ANY control char. */
    if (!(inComment)) {
      if (isdigit(ch) || (ch == '.') || (ch == 'E') || (ch == 'e') ||
          (ch == '-') | (ch == '+')) {
        lengthOfNumber++;
        numberBuffer[lengthOfNumber] = ch;
      } else {
        if (lengthOfNumber >= 0) {
          numberBuffer[lengthOfNumber + 1] = '\0';
          lengthOfNumber = -1;
          numNumbers++;
          if (numNumbers == 1) {
            *n = atoi(numberBuffer);
          } else if (numNumbers == 2) {
            *m = atoi(numberBuffer);
          } else if (numNumbers < maxEle) {
            a[numNumbers - 3] = atof(numberBuffer);
          } else {
            return (-1);
          } /* end if/else */
        }   /* end if */
      }     /* end if/else */
    }       /* end if */
  }         /* end while */
  fclose(FP);
  return (numNumbers - 2);
} /* end func main */
