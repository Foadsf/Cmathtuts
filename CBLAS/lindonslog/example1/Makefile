# example1.o: example1.c
	# gcc example1.c -I../../../common/include/ -lblas -o example1.o

#if you have your libblas.a in the common folder
example1.o: example1.c
	gcc example1.c -I../../../common/include/ ../../../common/lib/librefblas.a ../../../common/lib/libcblas.a  -o example1.o


#sample3.o: sample3.c
#	gcc sample3.c -framework Accelerate -o sample3.o
