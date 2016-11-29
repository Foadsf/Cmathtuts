#!/bin/sh
setenv INSTALL /usr/local
###################################################################
# This UNIX script builds the Netlib Nelib BLAS                   #
# cross platform                                                  #
# Make this script executable with "chmod +x buildnetlibblas.sh"  #
###################################################################
echo "==================================="
echo "Build Netlib Nelib BLAS            "
echo "==================================="
echo "USAGE: link your gcc or gfortran compiler with -lblas"

######################################
# Set trap to allow abort on signal: #
######################################
trap 'echo "Interrupted by signal" >&2; exit' 1 2 3 15

########################################################
# 1. Download BLAS source from Netlib.               #
# (Tar file is not visible - it's created on the fly.) #
########################################################
echo "--------------------------------------------"
echo "1. Downloading BLAS source from Netlib ..."
echo "--------------------------------------------"

curl http://www.netlib.org/blas/blas-3.6.0.tgz -o "blas.tar"
echo "... done."

#####################################
# 2. Uncompress blas tarred archive: #
#####################################
echo "-------------------------------"
echo "2. Uncompressing BLAS source ..."
echo "-------------------------------"
tar -xvf blas.tar
echo "... done."

##################################################
# 3. Create and install blas library "libblas.a" #
##################################################
echo "-------------------------------------------------------"
echo "3. Creating and installing blas library libblas.a   ..."
echo "-------------------------------------------------------"
cd BLAS-3.6.0
make
mv blas_LINUX.a libblas.a
ranlib libblas.a


while true; do
    read -p "Do you wish to install BLAS into your /usr/local (not a good practice!) Yy/Nn?" yn
    case $yn in
        [Yy]* ) cp libblas.a $INSTALL/lib/; echo "... done."; break;;
        [Nn]* ) break;;
        * ) echo "Please answer yes: Y y or no: N n.";;
    esac
done

cd ..
mv BLAS-3.6.0 bin
cd bin
rm -f *.o *.f make.inc Makefile
mkdir lib
mv libblas.a ./lib/libblas.a
make clean
cd ..
rm -f blas.tar
echo "... All done!"

#############################################
# 4. Test blas on your FORTRAN source code: #
#############################################
echo "==========================================================================================================="
echo "==========================================================================================================="
echo "==========================================================================================================="
echo "   === To compile C source code:                                                                        ==="
echo "   === 1. gcc -c myprog.c                                                                               ==="
echo "   ===    gfortran -o myprog.out myprog.o -L path/to/libblas.a/ -blas                                   ==="
echo "   === 2. gcc -c myprog.c                                                                               ==="
echo "   ===    gcc -o myprog.out myprog.o -L path/to/libblas.a/ -blas -L path/to/libgfortran.*/ -lgfortran   ==="
echo "   === 3. gcc myprog.c -L path/to/libblas.a/ -blas -L path/to/libgfortran.*/ -lgfortran                 ==="
echo "==========================================================================================================="
echo "==========================================================================================================="
echo "==========================================================================================================="

exit
