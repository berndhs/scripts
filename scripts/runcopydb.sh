#!/bin/bash
echo "This is runcopydb"
date -R
/home/bernd/bin/copydb -M 48 --server www.bernd-stramm.com --nodisplay
echo $?
