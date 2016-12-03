! Multiply matrices A and B using the intrinsic Fortran function matmul, the result is stored in matrix C
SUBROUTINE matrix_multiply(A, rows_A, cols_A, B, rows_B, cols_B, C, rows_C, cols_C) BIND(c)
  USE iso_c_binding
  INTEGER(c_int) :: rows_A, cols_A, rows_B, cols_B, rows_C, cols_C
  REAL(c_double) :: A(rows_A, cols_A), B(rows_B, cols_B), C(rows_C, cols_C)

  C = MATMUL(A, B)
END SUBROUTINE matrix_multiply
