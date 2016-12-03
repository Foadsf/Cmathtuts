# CC = gcc
# FC = gfortran
# # Make sure the CC and FC compilers were built with the same glibc library
# # g77 will work fine on most systems
# CFLAGS = -Wall
#
# OBJS = testdot.o testret.o testmat.o
#
# all: driver lib
#
# driver : driver.o $(OBJS)
# 	$(FC) -o driver driver.o $(OBJS) -lstdc++
#
# testret.o : testret.cpp
# 	$(CC) $(CFLAGS) -c testret.cpp
#
# testdot.o : testdot.cpp
# 	$(CC) $(CFLAGS) -c testdot.cpp
#
# testmat.o : testmat.cpp
# 	$(CC) $(CFLAGS) -c testmat.cpp
#
# driver.o : driver.f
# 	$(FC) -c driver.f
#
# # Default Targets for Cleaning up the Environment
# clean :
# 	rm *.o
# 	rm *.a
#
# pristine :
# 	rm *.o
# 	rm *.a
# 	touch *.cpp
#
# ctags :
# 	ctags *.cpp
#
# # Target for making the library
#
# lib: $(OBJS)
# 	ar -rc libbblas.a $(OBJS)
# 	ranlib libbblas.a


all:
	gfortran -c driver.f
	g++ -c testdot.cpp
	g++ -c testmat.cpp
	g++ -c testret.cpp
	g++ -o result.out testret.o testmat.o testdot.o driver.o -L /usr/local/Cellar/gcc/6.2.0/lib/gcc/6/ -lgfortran
	rm -rf *.o


clean :
	rm -rf *.out *~ *.bak *.o
