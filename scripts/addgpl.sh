#!/bin/bash


for f in *.cpp
do
sed  s\%'//  Copyright (C) 2009 - Bernd H Stramm'%'//  Copyright (C) 2009 - Bernd H Stramm\
// \
// This Program is distributed under the terms \
// of the GNU General Public License. \
// \
'%  $f > tmp
mv tmp $f
done

