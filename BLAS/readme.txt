to compile these examples you need to have BLAS library installed. to do this you have two possibilities:
1. use existing capabilities of your operating system
  1.1. ubuntu:
    on ubuntu you need build-essential and libblas-dev
      sudo apt-get build-essential libblas-dev
    and then compile:
      gcc foo.c lblas

  1.2. mac OS X:
    Acceleration framework is already built in the OS just link against the frame work
      gcc foo.c -framework Accelerate
    or
      gcc foo.c lblas


2. compile it yourself:
  2.1. download the latest from netlib: http://www.netlib.org/blas/
  2.2. unarchive
  2.3. goo to the unarchived folder from terminal and find make.inc and open it in your editor
  2.4. find the line below:
    PLAT = _LINUX
  and change it to your platform. for example if you are on a mac change it to:
    PLAT = _DARWIN
  2.5. this is optional but if you want to follow the examples in this repository it is better to do this. find the line below (most probably the latest line):
    BLASLIB      = blas$(PLAT).a
  and change it to:
    BLASLIB      = libblas.a
  3. save and exit the editor. and then run make in the terminal
  4. copy the libblas.a file after to a folder you know. (e.g. /usr/local/lib/)
  5. when you want to compile link gcc against this file
    gcc foo.c path/to/libblas.a


useful notes:

to use BLAS fortran routine inside the C code you need to declare the fortran routine inside the C code first

if foo is a fortran routine then with output and inputs

output foo_(inputs)

and then use it as foo inside the code

source: http://stackoverflow.com/questions/22085277/how-to-call-clapack-from-c
