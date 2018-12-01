all:
	gfortran -c test13F.f90
	gcc -c test13C.c
	gfortran -o result.out test13F.o test13C.o
	rm -rf *.o *.mod

clean :
	rm -rf *.out *~ *.bak *.o *.mod
