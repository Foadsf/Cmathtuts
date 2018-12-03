all:
	gfortran -c -std=legacy FORMAIN.FOR
	gcc -c CSUBS.c
	gfortran -o result.out -std=legacy FORMAIN.o CSUBS.o  
	rm -rf *.o


clean :
	rm -rf *.out *~ *.bak *.o
