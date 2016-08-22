#!/bin/sh
wget http://downloads.sourceforge.net/project/desr/Release/desrDL-1.6.0.tgz
tar xzf desrDL-1.6.0.tgz
g++ -IdesrDL -IdesrDL/ixe -IdesrDL/text -IdesrDL/classifier -I/usr/include/python2.7 -lpython2.7   readmodel.cpp  desrDL/src/libdesr.so  -w -fPIC -shared -o readmodel.so 
gunzip ru.model.gz
python test.py