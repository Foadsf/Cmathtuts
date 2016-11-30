#! /bin/csh
setenv INSTALL /usr/local
curl "http://netlib.sandia.gov/cgi-bin/netlib/netlibfiles.tar?filename=netlib/f2c" -o "f2c.tar"
tar -xvf f2c.tar
gunzip -rf f2c/*
cd f2c
mkdir libf2c
mv libf2c.zip libf2c
cd libf2c
unzip libf2c.zip
cp makefile.u Makefile
make
cp f2c.h $INSTALL/include
cp libf2c.a $INSTALL/lib
cd ../src
cp makefile.u Makefile
make
cp f2c $INSTALL/bin
cd ..
mkdir -p $INSTALL/man/man1
cp f2c.1t $INSTALL/man/man1
cp fc $INSTALL/bin/f77
chmod +x $INSTALL/bin/f77
cd ..
rm -rf f2c
echo "==================SUMMARY=================="
echo $0 " has built and installed:"
find $INSTALL -name '*f2c*' -mmin -5
find $INSTALL -name '*f77*' -mmin -5
