#include <stdlib.h>
#include <stream.h>

/*
  The following trick indicates that the named functions are
  to be compiled without name mangling.  This allows programs written
  in other languages (C or FORTRAN, say) to call C++ routines.
  (Otherwise, the C++ compiler replaces the names of these functions
  by weird "mangled" names).
*/

extern "C"
{
  float double_add_func ( double *r1, double *r2 );
  void double_add_sub ( double *r1, double *r2, double *r3 );
  int int_add_func ( int *i1, int *i2 );
  void int_add_sub ( int *i1, int *i2, int *i3 );
  float real_add_func ( float *r1, float *r2 );
  void real_add_sub ( float *r1, float *r2, float *r3 );
}

/********************************************************************/

float double_add_func ( double *r1, double *r2 )

/********************************************************************/
/*
  Purpose:

    DOUBLE_ADD_FUNC adds two double precision reals, returning the result as an function value.
*/
{
  return ( *r1 + *r2 );
}
/********************************************************************/

void double_add_sub ( double *r1, double *r2, double *r3 )

/********************************************************************/
/*
  Purpose:

    DOUBLE_ADD_SUB adds two double precision reals, returning the result as an argument.
*/
{
  cout << "\n";
  cout << "DOUBLE_ADD_SUB:\n";
  cout << "  Input R1 = " << *r1 << ".\n";
  cout << "  Input R2 = " << *r2 << ".\n";

  *r3 = *r1 + *r2;

  cout << "  Output R3 = " << *r3 << ".\n";
}
/********************************************************************/

int int_add_func ( int *i1, int *i2 )

/********************************************************************/
/*
  Purpose:

    INT_ADD_FUNC adds two integers, returning the result as a function value.
*/
{
  return ( *i1 + *i2 );
}
/********************************************************************/

void int_add_sub ( int *i1, int *i2, int *i3 )

/********************************************************************/
/*
  Purpose:

    INT_ADD_SUB adds two integers, returning the result as an argument.
*/
{
  cout << "\n";
  cout << "INT_ADD_SUB:\n";
  cout << "  Input I1 = " << *i1 << ".\n";
  cout << "  Input I2 = " << *i2 << ".\n";

  *i3 = *i1 + *i2;

  cout << "  Output I3 = " << *i3 << ".\n";
}
/********************************************************************/

float real_add_func ( float *r1, float *r2 )

/********************************************************************/
/*
  Purpose:

    REAL_ADD_FUNC adds two reals, returning the result as a function value.
*/
{
  return ( *r1 + *r2 );
}
/********************************************************************/

void real_add_sub ( float *r1, float *r2, float *r3 )

/********************************************************************/
/*
  Purpose:

    REAL_ADD_SUB adds two real values, returning the result as an argument.
*/
{
  cout << "\n";
  cout << "REAL_ADD_SUB:\n";
  cout << "  Input R1 = " << *r1 << ".\n";
  cout << "  Input R2 = " << *r2 << ".\n";

  *r3 = *r1 + *r2;

  cout << "  Output R3 = " << *r3 << ".\n";
}
