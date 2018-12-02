all:
	gfortran -c -std=legacy test1F.f
	gcc -c test1C.c
	gfortran -o test1.out -std=legacy test1C.o test1F.o
	rm -rf *.o


clean :
	rm -rf *.out *~ *.bak *.o
