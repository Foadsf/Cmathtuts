/*                 C program (main.c):                   */

// #include <fortran.h>
#include <stdio.h>
#include <string.h>

/* Declare prototype of the Fortran function. Note the last */
/* argument passes the length of the first argument. */
double FTNFCTN_(char *, int *, int);

double FLOAT1 = 1.6;
double FLOAT2; /* Initialized in FTNFCTN */

int main() {
  int clogical, ftnlogical, cstringlen;
  double rtnval;
  char *cstring = "C Character String";

  /* Convert clogical to its Fortran equivalent */
  clogical = 1;
  ftnlogical = _btol(clogical);

  /* Print values of variables before call to Fortran function */
  printf(" In main: FLOAT1 = %g; FLOAT2 = %g\n", FLOAT1, FLOAT2);
  printf(" Calling FTNFCTN with arguments:\n");
  printf(" string = \"%s\"; logical = %d\n\n", cstring, clogical);
  cstringlen = strlen(cstring);
  rtnval = FTNFCTN_(cstring, &ftnlogical, cstringlen);

  /* Convert ftnlogical to its C equivalent */
  clogical = _ltob(&ftnlogical);

  /* Print values of variables after call to Fortran function */
  printf(" Back in main: FTNFCTN returned %g\n", rtnval);
  printf(" and changed the two arguments:\n");
  printf(" string = \"%.*s\"; logical = %d\n", cstringlen, cstring, clogical);

  return 0;
}
