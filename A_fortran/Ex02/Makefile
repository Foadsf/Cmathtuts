all:
	gfortran -c test2F.f
	gcc -c test2C.c
	# gcc -o test1.out test2C.o test2F.o -L /usr/local/Cellar/gcc/6.2.0/lib/gcc/6/ -lgfortran
	gfortran -o test2.out test2F.o test2C.o  
	rm -rf *.o


clean :
	rm -rf *.out *~ *.bak *.o
