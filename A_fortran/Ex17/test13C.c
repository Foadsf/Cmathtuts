/*
|| C functions to export the facilities of strtoll()
|| to Fortran programs.  Effective Fortran declaration:
||
|| FUNCTION ISCAN(S,J)
|| INTEGER(KIND=8) :: ISCAN
|| CHARACTER*(*) S
|| INTEGER J
||
|| String S(J:) is scanned for the next signed long value
|| as specified by strtoll(3c) for a "base" argument of 0
|| (meaning that octal and hex literals are accepted).
||
|| The converted long long is the function value, and J is
|| updated to the nonspace character following the last
|| converted character, or to 1+LEN(S).
||
|| Note: if this routine is called when S(J:J) is neither
|| whitespace nor the initial of a valid numeric literal,
|| it returns 0 and does not advance J.
*/
#include <ctype.h>  /* for isspace() */
#include <stdlib.h> // for strtoll()
#include <string.h>

long long iscan_(char *ps, int *pj, int ls) {

  long long ret = 0;

  char *endpt;
  /* when J>LEN(S), do nothing, return 0 */
  if (ls >= *pj) {
    int scanPos, scanLen;
    char wrk[1024];

    /* convert J to origin-0, permit J=0 */
    scanPos = (0 < *pj) ? *pj - 1 : 0;

    /* calculate effective length of S(J:) */
    scanLen = ls - scanPos;

    /* copy S(J:) and append a null for strtoll() */
    strncpy(wrk, (ps + scanPos), scanLen);
    wrk[scanLen] = '\0';

    /* scan for the integer */
    ret = strtoll(wrk, &endpt, 0);

    /*
    || Advance over any whitespace following the number.
    || Trailing spaces are common at the end of Fortran
    || fixed-length char vars.
    */
    while (isspace(*endpt)) {
      ++endpt;
    }
    *pj = (endpt - wrk) + scanPos + 1;
  }
  return ret;
}
