all:
	gfortran -c ffunction.f
	gcc -c cfunction1.c
	g++ -c cppfunction.cpp
	gfortran -c fprogram.f
	gfortran -o result.out ffunction.o cfunction1.o cppfunction.o fprogram.o
	rm -rf *.o

clean :
	rm -rf *.out *~ *.bak *.o
