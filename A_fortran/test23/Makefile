all:
	gfortran -c tstfunc1.f
	g++ -c tst01.cc
	g++ -o result.out tst01.o tstfunc1.o -L /usr/local/Cellar/gcc/6.2.0/lib/gcc/6/ -lgfortran
	rm -rf *.o

clean :
	rm -rf *.out *~ *.bak *.o
