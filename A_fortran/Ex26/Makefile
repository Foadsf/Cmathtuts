all:
	gcc -c CMAIN.c
	gfortran -c FORSUBS.FOR 
	gfortran -o result.out CMAIN.o FORSUBS.o 

clean :
	rm -rf *.out *~ *.bak *.o

