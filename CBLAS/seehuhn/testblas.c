/* testblas.c - test program for the cblas_dgemv function
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
 * $Id: testblas.c 5698 2004-05-12 18:17:53Z voss $
 *
 * part of the tutorials by Jochen Voss "Numerical Linear Algebra Packages on
 * Linux"
 * link: http://www.seehuhn.de/pages/linear
 *
 * source code: http://m.seehuhn.de/data/testblas.c
 */

// #ifdef __APPLE__
// #include <Accelerate/Accelerate.h> /* The MacOS X blas/lapack */
// #else
#include <cblas.h> /* C BLAS          BLAS  */
// #endif

#include <stdio.h>

int main() {
  int i;
  double x[] = {1, 1, 1};

  cblas_dscal(3, 4.323, x, 1);

  for (i = 0; i < 3; ++i)
    printf("%f\n", x[i]);

  return 0;
}
