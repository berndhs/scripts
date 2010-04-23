#!/bin/sh

FILE=$1

if [ ! -d "$FILE" ] ; then
  git add $FILE
fi
