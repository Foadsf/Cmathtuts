all:
	gfortran -c FORSUBS.FOR
	gcc -c CMAIN.c
	# gcc -o result.out CMAIN.o FORSUBS.o -L /usr/local/Cellar/gcc/6.2.0/lib/gcc/6/ -lgfortran
	gfortran -o result.out FORSUBS.o CMAIN.o 
	rm -rf *.o


clean :
	rm -rf *.out *~ *.bak *.o
