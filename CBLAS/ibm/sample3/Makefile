# sample3.o: sample3.c
	# gcc sample3.c -I../../../common/include/ -lblas -o sample3.o

#if you have your libblas.a in the common folder
# sample3.o: sample3.c
# 	gcc sample3.c -I../../../common/include/ ../../../common/lib/librefblas.a ../../../common/lib/libcblas.a ../../../common/lib/libgfortran.dylib -o sample3.o
	#../../../common/lib/liblapack.a ../../../common/lib/libcblas.a ../../../common/lib/libblas.a  ../../../common/lib/libgfortran.dylib -o sample3.o


#sample3.o: sample3.c
#	gcc sample3.c -framework Accelerate -o sample3.o


all: sample3.out

sample3.out: sample3.c
	gcc -c -DADD_ sample3.c -I../../../common/include/
	gfortran ../../../common/lib/librefblas.a ../../../common/lib/libcblas.a  -o sample3.out sample3.o
	rm -rf *.o


clean :
	rm -rf *.out *~ *.bak *.o
