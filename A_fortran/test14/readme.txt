source: http://striky.ece.jhu.edu/~sasha/SOFTWARE/FORTRAN/007-3696-005/sgi_html/ch07.html


on the fortran side if you do not specify a the type of the variable it assumes it's real!

when transferring a string or an array from C to fortran we must use strlen or size of function to pass the size as well

  void func_(int *, int, char *, int);

  char * mychar = "some text";
  int * myint = {1,2,3,4};

  func_(myint, sizeof(myint), mychar , strlen(mychar));


what surprises me is that somehow miraculously even if we change the order of the variables fortran understands to assign the output of strlen and sizeof functions to the right array/string
