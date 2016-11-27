on mac OS X
  1. use brew to get lapack installed: http://braumeister.org/repos/Homebrew/homebrew-dupes/formula/lapack
    brew install lapack
  2. look for liblapacke.dylib and link gcc against it
    -L/path/to/ -llapacke
  or simply:
    /path/to/liblapacke.dylib
  3. look for lapcke.h and link the gcc against it
    -I/path/to/
  you can have the lapacke.h also by installing openblas or compiling the netlib lapack


on ubuntu:
  sudo apt-get install liblapacke liblapacke-dev
