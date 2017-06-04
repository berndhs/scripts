#!/bin/bash -x
FILE=$1
echo "file is "$FILE
TGT=`basename $FILE`
echo "target is $TGT"
read yorn
mv ${FILE} /home/bernd/Documents/iso_files/${TGT}
ln -s ~/Documents/iso_files/${TGT} ${FILE}
