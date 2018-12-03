all:
	gcc -c Cfile.c
	gfortran -c -std=legacy Ffile.f
	gfortran -o test.out -std=legacy Cfile.o Ffile.f
	#gcc -o test.out -std=legacy -lgfortran Cfile.o Ffile.o
	rm -rf *.o

clean:
	rm -rf *.o *.out
