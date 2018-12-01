SUBROUTINE ranvec(v, n)
  INTEGER                        :: n
  DOUBLE PRECISION, DIMENSION(n) :: v

  CALL RANDOM_SEED()
  CALL RANDOM_NUMBER(v)

END SUBROUTINE ranvec
