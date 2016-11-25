ubuntu:
to compile these examples on ubuntu you need build-essential and libblas-dev
sudo apt-get build-essential libblas-dev

mac OS X:
Acceleration framework is already built in the OS



to use BLAS fortran routine inside the C code you need to declare the fortran routine inside the C code first

if foo is a fortran routine then with output and inputs

output foo_(inputs)

and then use it as foo inside the code

source: http://stackoverflow.com/questions/22085277/how-to-call-clapack-from-c
