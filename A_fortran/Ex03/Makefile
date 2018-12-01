all:
	gfortran -c FORMAIN.FOR
	gcc -c CSUBS.C
	gfortran -o result.out FORMAIN.o CSUBS.o  
	rm -rf *.o


clean :
	rm -rf *.out *~ *.bak *.o
