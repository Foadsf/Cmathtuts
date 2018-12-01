source: http://stackoverflow.com/questions/33730643/how-c-call-fortran-77s-common-blocks


points:
1. common block in fortran is the equivalent of struct in C. if you have in the fortran side
  ftype1 var1
  ftype2 var2
  ...
  common /stct1/ var1, var2, ....
on the C side you must have
  extern struct{
    ctype1 var1;
    ctype2 var2;
    ...
  }stct1_;
or
  typedef struct{
    ctype1 var1;
    ctype2 var2;
    ...
  }mystct;

  extern mystct stct1_;
