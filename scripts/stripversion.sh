#!/bin/bash
VER=$1
N=$2

case "k$N" in
	k1) 
		RES=`cat $VER | awk 'BEGIN { FS = "." } ; { print $1 }' `
		;;
	k2)
		RES=`cat $VER | awk 'BEGIN { FS = "." } ; { print $1","$2 }'`
		;;
	k3)
		RES=`cat $VER | awk 'BEGIN { FS = "." } ; { print $1","$2 "."$3 }'`
		;;
	*)
		RES=`cat ${VER}`
		;;
esac
echo $RES
