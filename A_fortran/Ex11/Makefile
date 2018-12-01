all:
	gfortran -c add.f
	gcc -c test11.c
	gfortran -o result.out add.o test11.o
	rm -rf *.o

clean :
	rm -rf *.out *~ *.bak *.o
