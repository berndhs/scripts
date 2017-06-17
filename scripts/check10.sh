#!/bin/bash
BASE=10.10.0.
GOOD=""
for A in  {100..120} ; do
  echo testing for $A 
  ping -c 1 ${BASE}${A}  >& /dev/null
  if [ $? -eq 0 ] ; then
	  GOOD=${GOOD}" "$A 
	  echo good on $GOOD
  fi
done
echo "\n\n" good on $GOOD

