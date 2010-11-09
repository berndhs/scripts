#!/bin/bash

# unpack a tar.gz archive and repack under a different name

usage () {
  echo "usage:"
  echo
  echo "$0 <old-compress> <old-base> <new-compress> <new-base>"
  echo
}

unpack_opts () {
  UNPACK_OPTS="zxvf"
  OLD_SUFFIX="gz"
  if [ $1 == "j" ] || [ $1 == "bz2" ]
  then
    UNPACK_OPTS="jxvf"
    OLD_SUFFIX="bz2"
  fi
}

pack_opts () {
  PACK_OPTS="zcvf"
  NEW_SUFFIX="gz"
  if [ $1 == "j" ] || [ $1 == "bz2" ]
  then
    PACK_OPTS="jcvf"
    NEW_SUFFIX="bz2"
  fi
}

OLD_COMPRESS=$1
OLD_BASE=$2
NEW_COMPRESS=$3
NEW_BASE=$4

if [ $# -lt 4 ] 
then
  usage
  exit 1
fi

echo " argument count " $#
echo "unpacking " $OLD_BASE
unpack_opts $OLD_COMPRESS
pack_opts $NEW_COMPRESS

UNTAR_COMMAND="tar $UNPACK_OPTS ${OLD_BASE}.tar.${OLD_SUFFIX}"
MOVE_COMMAND="mv ${OLD_BASE} ${NEW_BASE}"
RETAR_COMMAND="tar $PACK_OPTS ${NEW_BASE}.tar.${NEW_SUFFIX} ${NEW_BASE}"
CLEAN_COMMAND="rm -r ${NEW_BASE}"
echo $UNTAR_COMMAND
$UNTAR_COMMAND
echo $MOVE_COMMAND
$MOVE_COMMAND
echo $RETAR_COMMAND
$RETAR_COMMAND
echo $CLEAN_COMMAND
$CLEAN_COMMAND
