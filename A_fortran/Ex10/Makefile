all:
	gfortran -c ranvec.f90
	gcc -c main.c
	gfortran -o result.out ranvec.o main.o
	rm -rf *.o

clean :
	rm -rf *.out *~ *.bak *.o
