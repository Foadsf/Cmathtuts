all:
	gfortran -c kronrod.f 
	gcc -c kronrod_prb.c
	gfortran -o result.out kronrod.o kronrod_prb.o
	rm -rf *.o

clean :
	rm -rf *.out *~ *.bak *.o
