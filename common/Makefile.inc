#	if you have BLAS installed (compiler knows where to look for libblas.a)
#	BLASINST = true
# otherwise:
BLASINST = false

#	if you want to use Apple's Acceleration framework
#	MACOS =	true
#	otherwise
MACOS =	false

#	if your compiler knows where to look for libgfortran.*
#	GFORTRANINST = ture
# otherwise:
GFORTRANINST = false

# if your compiler knows where to look for libcblas.a
# CBLASINST = true
# otherwise
CBLASINST= false

# if your compiler knows where to look for liblapack.a
# LAPACKINST = true
# otherwise
LAPACKINST= false

# if your compiler knows where to look for liblapacke.a
# LAPACKEINST = true
# otherwise
LAPACKEINST= false



FC       = gfortran
CC       = gcc
FFLAGS   = -Wall -o
CFLAGS   = -Wall -c


ifeq ($(NBLAS),true)
  ifeq ($(BLASINST),true)
  	ifeq ($(MACOS),true)
  		BLASFLG	= -framework Accelerate
  	else
  		BLASFLG	= -lblas
  	endif
  else
  	BLASFLG	= $(BINDIR)/lib/librefblas.a
  endif
endif

ifeq ($(NGFORTRAN),true)
  ifeq ($(GFORTRANINST),true)
  	GFORTRANFLG = -lgfortran
  else
  	GFORTRANFLG = $(BINDIR)/lib/libgfortran.dylib
  endif
endif

ifeq ($(NCBLAS),true)
  ifeq ($(CBLASINST),true)
    ifeq ($(MACOS),true)
      CBLASFLG	= -framework Accelerate
    else
      CBLASFLG	= -lcblas
    endif
  else
    CBLASFLG	= $(BINDIR)/lib/libcblas.a
  endif
endif

ifeq ($(NCLAPACK),true)
  ifeq ($(LAPACKINST),true)
    ifeq ($(MACOS),true)
      LAPACKFLG	= -framework Accelerate
    else
      LAPACKFLG	= -llapack
    endif
  else
    LAPACKFLG	= $(BINDIR)/lib/liblapack.a
    F2CFLG = $(BINDIR)/lib/libf2c.a
  endif
endif

ifeq ($(NLAPACK),true)
  ifeq ($(LAPACKINST),true)
    ifeq ($(MACOS),true)
      LAPACKFLG	= -framework Accelerate
    else
      LAPACKFLG	= -llapack
    endif
  else
    LAPACKFLG	= $(BINDIR)/lib/liblapack.a
    F2CFLG = $(BINDIR)/lib/libf2c.a
  endif
endif

ifeq ($(NLAPACKE),true)
  ifeq ($(LAPACKEINST),true)
    ifeq ($(MACOS),true)
      LAPACKEFLG	= -framework Accelerate
    else
      LAPACKEFLG	= -llapacke
    endif
  else
    LAPACKEFLG	= $(BINDIR)/lib/liblapacke.a
    # or
    #LAPACKEFLG	= $(BINDIR)/lib/liblapacke.dylib
  endif
endif


#address to the *.h files
HINC = -I$(BINDIR)/include/


TARGETS = $(FLNAME)out
OBJ = $(FLNAME)c

all : $(TARGETS)
	@echo Make Complete


$(TARGETS) : $(OBJ)
ifeq ($(BLASINST),true)
	$(CC) $(CFLAGS) $(OBJ) $(HINC) $(LAPACKEFLG) $(LAPACKFLG) $(CBLASFLG) $(BLASFLG) $(F2CFLG) $(FFLAGS) $(TARGETS)
else
	$(CC) $(CFLAGS) $(OBJ) $(HINC)
	$(FC) $(LAPACKEFLG) $(LAPACKFLG) $(CBLASFLG) $(CBLASFLG) $(BLASFLG) $(F2CFLG) $(FFLAGS) $(TARGETS) $(FLNAME)o
	rm -rf *.o
	# or
	# $(CC) $(CFLAGS) $(OBJ) $(HINC) $(LAPACKEFLG) $(LAPACKFLG) $(CBLASFLG) $(BLASFLG) $(F2CFLG) $(GFORTRANFLG) $(FFLAGS) $(TARGETS)
endif


clean :
	rm -rf *.out *~ *.bak *.o $(TARGETS)
