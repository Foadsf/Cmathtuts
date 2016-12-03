all:
	gfortran -c main.f
	g++ -c cpps.cpp
	g++ -o result.out main.o cpps.o -L /usr/local/Cellar/gcc/6.2.0/lib/gcc/6/ -lgfortran
	rm -rf *.o

clean :
	rm -rf *.out *~ *.bak *.o
