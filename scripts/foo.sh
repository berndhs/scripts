#!/bin/bash
fullfile=$0
filename=$(basename "$fullfile")
extension="${filename##*.}"
filename="${filename%.*}"
echo "file " $filename " ext " $extension
