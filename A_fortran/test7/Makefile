all:
	gcc -c cprogram.c
	gfortran -c ffunction.f
	g++ -c cppfunction.cpp
	gcc -c cfunction1.c
	gfortran -o result.out cprogram.o ffunction.o cppfunction.o cfunction1.o
	rm -rf *.o

clean :
	rm -rf *.out *~ *.bak *.o
