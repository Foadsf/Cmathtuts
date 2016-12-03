all:
	g++ -c cppprogram.cpp
	gfortran -c ffunction.f
	gcc -c cfunction1.c
	g++ -c cppfunction.cpp
	g++ -o result.out cppprogram.o ffunction.o cppfunction.o cfunction1.o
	rm -rf *.o

clean :
	rm -rf *.out *~ *.bak *.o
