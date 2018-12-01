all:
	gfortran -c fortran_matrix_multiply.f90
	g++ -c cpp_main_1.cpp -std=c++11
	g++ -o result.out cpp_main_1.o fortran_matrix_multiply.o -L /usr/local/Cellar/gcc/6.2.0/lib/gcc/6/ -lgfortran
	# gfortran -o result.out cpp_main_1.o fortran_matrix_multiply.o
	rm -rf *.o


clean :
	rm -rf *.out *~ *.bak *.o
