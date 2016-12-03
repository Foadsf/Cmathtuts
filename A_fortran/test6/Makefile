all:
	# gfortran -c test6F.f -fno-align-commons
	gfortran -c test6F.f -fno-align-commons
	gcc -c test6C.c
	#gcc -o test6.out test6C.o test6F.o -L /usr/local/Cellar/gcc/6.2.0/lib/gcc/6/ -lgfortran
	gfortran -o result.out test6C.o test6F.o
	rm -rf *.o

clean :
	rm -rf *.out *~ *.bak *.o
