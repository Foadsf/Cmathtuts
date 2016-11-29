/* testlapack.c - test program for the Atlas clapack_dgesv function
 *
 * Copyright (C) 2004  Jochen Voss.
 * updated by Foad Sojoodi Farimani for mac OS X portability
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * $Id: testlapack.c 5698 2004-05-12 18:17:53Z voss $
 *
 * part of the tutorials by Jochen Voss "Numerical Linear Algebra Packages on
 * Linux"
 * link: http://www.seehuhn.de/pages/linear
 *
 * source code: http://m.seehuhn.de/data/testlapack.c
 */

#include <stdio.h>

#include "clapack.h"
#include <atlas_enum.h>

double m[] = {3, 1, 3, 1, 5, 9, 2, 6, 5};

double x[] = {-1, 3, -3};

int main() {
  int ipiv[3];
  int i, j;
  int info;

  for (i = 0; i < 3; ++i) {
    for (j = 0; j < 3; ++j)
      printf("%5.1f", m[i * 3 + j]);
    putchar('\n');
  }

  info = clapack_dgesv(CblasRowMajor, 3, 1, m, 3, ipiv, x, 3);
  if (info != 0)
    fprintf(stderr, "failure with error %d\n", info);

  for (i = 0; i < 3; ++i)
    printf("%5.1f %3d\n", x[i], ipiv[i]);

  return 0;
}
