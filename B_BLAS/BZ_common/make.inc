#this file is for compiling the examples not the BLAS intself. to compile Netlib BLAS run the buildnetlibblas.sh bash script



#	if you have BLAS installed (compiler knows where to look for libblas.a) true otherwise false
BLASINST = false

#	if you want to use Apple's Acceleration framework
#	MACOS =	true
#	otherwise
MACOS =	false

#	if your compiler knows where to look for libgfortran.*
#	GFORTRANINST = ture
# otherwise:
GFORTRANINST = false

#if you have used the bash script to compile Netlib BLAS
BINDIR = ./bin/
LIBDIR = $(BINDIR)/lib/
INCDIR = $(BINDIR)/include/

GFORTRANDIR = ../../common/lib/

LIBFLG = -L $(LIBDIR) -L $(GFORTRANDIR)
INCGLG = -I $(INCDIR)

FC       = gfortran
CC       = gcc
FFLAGS   =
CFLAGS   =

ifeq ($(GFORTRANINST),true)
  GFORTRANFLG = -lgfortran
else
  GFORTRANFLG = $(BINDIR)/lib/libgfortran.dylib
endif

ifeq ($(BLASINST),true)
  ifeq ($(MACOS),true)
    BLASFLG	= -framework Accelerate
  else
    BLASFLG	= -lblas
  endif
else
  BLASFLG	= $(BINDIR)/lib/librefblas.a
endif


TARGETS = $(FLNAME)out
OBJ = $(FLNAME)c

all : $(TARGETS)
	@echo Make Complete


$(TARGETS) : $(OBJ)
	$(CC) $(OBJ) $(TARGETS) $(BLASFLG) $(GFORTRANFLG)
  # or
	# $(CC) -c $(OBJ)
	# $(FC) -o $(TARGETS) $(FLNAME)o $(BLASFLG)
  # or
  # $(CC) -c $(OBJ)
	# $(CC) -o $(TARGETS) $(FLNAME)o $(BLASFLG) $(GFORTRANFLG)
	rm -rf *.o



clean :
	rm -rf *.out *~ *.bak *.o
