all:
	# gfortran -c test6F.f -fno-align-commons
	gfortran -c Ftest.FOR -fno-align-commons
	gcc -c Ctest.c
	gfortran -o result.out Ctest.o Ftest.o
	rm -rf *.o

clean :
	rm -rf *.out *~ *.bak *.o
