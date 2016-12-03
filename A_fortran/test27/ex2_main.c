#include <stdlib.h>
#include <stdio.h>

/* 
   This example demonstrates how a C program can call FORTRAN subroutines and 
   functions, and pass information back and forth.
*/

#define ARRSIZE 3           /* array size */
/*
  Here we are declaring the names of the routines we'll be calling.

  Note that the routines FOR1_, FOR2_, FOR3_ and FOR4_ are FORTRAN routines.  
  In the source code, they do not have underscores at the end of their names; 
  when the FORTRAN compiler compiles them, it inserts an underscore, and a C
  program must include this underscore to access the FORTRAN code.
 
  That's just a feature of how most FORTRAN compilers work on UNIX.
*/
int  c1_    ( char dir[64] );
void c2_    ( int a[ARRSIZE][ARRSIZE] );
void for1_  ( int a[ARRSIZE][ARRSIZE] );
void for2_  ( int *int_val, float *real_val, float *complex_val, double *d_val );
void for3_  ( void );
void for4_  ( int a[ARRSIZE][ARRSIZE] );
void print_array ( int a[ARRSIZE][ARRSIZE] );
int main    ( void );
void test01 ( void );
void test02 ( void );
void test03 ( void );
void test04 ( void );

/********************************************************************/

int main ( void )

/********************************************************************/
/*
  Purpose:

    MAIN is the main program of set of C routines that call FORTRAN90 routines.
*/
{
/*
  Introduction
*/
  printf ( "\n");
  printf ( "MAIN:\n" );
  printf ( "  An example of a C/FORTRAN interface.\n");
  printf ( "  The main program is written in C.\n" );
  printf ( "  It calls FORTRAN routines, which in turn call C routines.\n" );
  printf ( "\n");

  test01();
  test02();
  test03();
  test04();

  printf ( "\n" );
  printf ( "MAIN:\n" );
  printf ( "  Normal end of execution.\n" );

}
/********************************************************************/

void test01 ( void ) 

/********************************************************************/
/*
  Purpose:

    TEST01 passes an array to and from a FORTRAN90 routine.

  Discussion:

    ARRAY is declared in the FORTRAN routine as 
    integer a(3,3)
*/
{
  static int array[ARRSIZE][ARRSIZE] =
    {
      { 1, 2, 3 },
      { 4, 5, 6 },
      { 7, 8, 9 }
    };

  printf ( "\n" );
  printf ( "TEST01:\n" );
  printf ( "  Define a 3 by 3 integer array in a C routine.\n" );
  printf ( "  Pass it to a FORTRAN routine for modification.\n" );
  printf ( "  Examine the returned value.\n");
  
  printf ( "\n" );
  printf ( "TEST01:\n" );
  printf ( "  Here is the initial value of ARRAY:\n");

  print_array ( array );

  printf ( "\n" );
  printf ( "TEST01:\n" );
  printf ( "  Now we pass ARRAY to the FORTRAN routine FOR1 for processing.\n" );

  for1_ ( array );

  printf ( "\n" );
  printf ( "TEST01:\n" );
  printf ( "  After return from FOR1, here is ARRAY:\n");

  print_array ( array );
}
/********************************************************************/

void test02 ( void ) 

/********************************************************************/
/*
  Purpose:

    TEST02 passes numeric data to and from a FORTRAN90 routine.
*/
{
  int int_val;
  float real_val;
  static float complex_val[2];
  double d_val;

  int_val = 13;
  real_val = 42.85;
  complex_val[0] = 123.45; 
  complex_val[1] = 6.789; 
  d_val = 12345.006789;
   
  printf ( "\n" );
  printf ( "TEST02:\n" );
  printf ( "  Pass numeric data to a FORTRAN routine, alter it, return it.\n" );
  printf ( "\n" );
  printf ( "  Integer value = %d\n", int_val );
  printf ( "  Real value = %f\n", real_val );
  printf ( "  Complex value = %f + %f*i\n", complex_val[0], complex_val[1] );
  printf ( "  Double value = %f\n", d_val );

  printf ( "\n" );
  printf ( "TEST02\n" );
  printf ( "  Call FOR2 to modify these values.\n" );

  for2_ ( &int_val, &real_val, complex_val, &d_val );

  printf ( "\n" );
  printf ( "TEST02:\n" );
  printf ( "  New values of data as modified by FOR2:\n" );
  printf ( "\n" );
  printf ( "  Integer value = %d\n", int_val );
  printf ( "  Real value = %f\n", real_val );
  printf ( "  Complex value = %f + %f*i\n", complex_val[0], complex_val[1] );
  printf ( "  Double value = %f\n", d_val );

  return;
}
/********************************************************************/

void test03 ( void ) 

/********************************************************************/
/*
  Purpose:

    TEST03 calls a FORTRAN90 routine which in turn calls a C routine.
*/
{

  printf ( "\n" );
  printf ( "TEST03:\n" );
  printf ( "  Call a FORTRAN routine which calls a C routine.\n" );
  printf ( "  The C routine returns character data of some sort.\n" );

  for3_ ( );

  return;
}
/********************************************************************/

void test04 ( void ) 

/********************************************************************/
/*
  Purpose:

    TEST04 passes an array to a FORTRAN90 routine which passes it to a C routine.

  Discussion:

    Note that in order to access the FORTRAN routine whose text name is "FOR4",
    it is necessary to append an underscore to the name, since the FORTRAN compiler
    has stored the compiled name as "FOR4_".
*/
{
  static int array[ARRSIZE][ARRSIZE] =
    {
      { 1, 2, 3 },
      { 4, 5, 6 },
      { 7, 8, 9 }
    };

  printf ( "\n" );
  printf ( "TEST04:\n" );
  printf ( "  Pass an array to a FORTRAN routine.\n" );
  printf ( "  The FORTRAN routine passes the array to a C routine.\n" );

  printf ( "\n" );
  for4_ ( array );

  return;
}
/********************************************************************/

int c1_ ( char dir[64] ) 

/********************************************************************/
/*
  Purpose:

    C1_ returns the current working directory as a string.

  Discussion:

    The FORTRAN routine will get here by calling "C1".  This routine has
    an underscore appended to its name, because if it had been written
    in FORTRAN, the compiler would have automatically appended an underscore
    to its name in the compiled code.

    You must use an array, not a pointer string.  If a pointer string is
    used, only the first element will be passed back to FORTRAN.  FORTRAN
    expects the space for the string to be previously allocated, therefore
    the C pointer string may cause problems.
*/
{
  char *getcwd();
  char *cwd;
/*
  Store the current working directory in the string CWD.
*/
  cwd = getcwd ( (char *) NULL, 64 );

  if ( cwd == NULL ) 
  {
    return (-1);
  }

  printf ( "\n" );
  printf ( "C1:\n" );
  printf ( "  By calling the library routine GETCWD, we see that\n" );
  printf ( "  the current working directory is %s.\n", cwd );
/*
  Copy CWD to an array of single characters.  

  It's easier for FORTRAN to deal with an array of characters than with
  a C string.
 */

  strcpy ( dir, cwd );
  return 0;
}
/********************************************************************/

void c2_ ( int a[ARRSIZE][ARRSIZE] ) 

/********************************************************************/
{
/*
  Purpose:

    C2_ modifies an array.  

  Discussion:

    Since the array was created and filled in a C routine, then
    passed to FORTRAN, the indices are in the correct (C) order.
*/
  int abs();
  int i;
  int j;

  printf ( "\n" );
  printf ( "C2:\n" );
  printf ( "  The input value of ARRAY:\n");

  print_array ( a );

  for ( i = 0; i < ARRSIZE; i++ ) 
  {
    for ( j = 0; j < ARRSIZE; j++ ) 
    { 
      if ( a[i][j] < 0 ) 
      {
        a[i][j] = - a[i][j];
      } 
      a[i][j] = a[i][j] + 1; 
    }
  }

  printf ( "\n" );
  printf ( "C2:\n" );
  printf ( "  Modified value of ARRAY is:\n");

  print_array ( a );

  return;
}
/********************************************************************/

void print_array ( int a[ARRSIZE][ARRSIZE] )

/********************************************************************/
/*
  Purpose:

   PRINT_ARRAY prints an integer doubly dimensioned array.  
*/
{
  int i;
  int j;

  for ( i = 0; i < ARRSIZE; i++ ) 
  {
    for ( j = 0; j < ARRSIZE; j++ ) 
    {
      printf ( "%4.0d ", a[i][j] );
    }
    printf("\n"); 
  }
  printf("\n");

  return;
}
