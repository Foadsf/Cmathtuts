
ifndef CC
	CC = gcc
endif

CCFLAGS= -lm





# Check our platform and make sure we define the APPLE variable
# and set up the right compiler flags and libraries
PLATFORM = $(shell uname -s)
ifeq ($(PLATFORM), Darwin)
	LIBS = -framework Accelerate
else
	LIBS = -lblas -llapack
endif


testdgtsv: testdgtsv.c
	$(CC) $^ $(CCFLAGS) $(LIBS)


clean:
	rm -f testdgtsv
