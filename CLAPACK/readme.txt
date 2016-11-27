instructions:

1. to copile CLAPACK you need to have BLAS installed for a better performance: go to BLAS folder for the instructions:https://github.com/Foadsf/Cmathtuts/blob/master/BLAS/readme.txt alternatively there is also a BLAS inside the source folder but not recommended if you want the good performance
2. download latest version of CLAPACK from here: http://www.netlib.org/clapack/ and unarchive
3. rename the make.inc.example to make.include
4. open it in the editor and change the line
  PLAT= _LINUX
to your platform. for example for mac:
  PLAT= _DARWIN
5. find the line
  BLASLIB = ...
and put the address you had from BLAS instructions here (or if you have the libblas.a installed put just -lblas)
6. this is optional but if you want to follow these examples easily change the lines below:
  LAPACKLIB    = lapack$(PLAT).a
  F2CLIB       = ../../F2CLIBS/libf2c.a
  TMGLIB       = tmglib$(PLAT).a
  EIGSRCLIB    = eigsrc$(PLAT).a
  LINSRCLIB    = linsrc$(PLAT).a
  F2CLIB		 = ../../F2CLIBS/libf2c.a
to
  LAPACKLIB    = liblapack.a
  F2CLIB       = ../../F2CLIBS/libf2c.a
  TMGLIB       = libtmglib.a
  EIGSRCLIB    = libeigsrc.a
  LINSRCLIB    = liblinsrc.a

7. save and go to the terminal and run make
8. copy the files liblapack.a libtmglib.a libf2c.a to your lib folder. you can out them in /usr/local/lib/ if you want the compiler to find them automatically
9. from INCLUD folder copy clapack.h f2c.h blaswrap.h to your includ folder. (e.g. usr/local/include/)

warning:
always include f2c.h and  blaswrap.h before clapack.h in you code. source:
