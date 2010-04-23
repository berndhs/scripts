#!/bin/bash

export XOPENSSL="$HOME/localinstall/openssl"
export SPECIAL_BIN="$XOPENSSL/bin"
export SPECIAL_LIB="$XOPENSSL/lib"
export SPECIAL_INCLUDE="$XOPENSSL/include"
export SPECIAL_SSL="$XOPENSSL/ssl"

export PATH="$SPECIAL_BIN:$PATH"
export LD_LIBRARY_PATH="$SPECIAL_LIB:$LD_LIBRARY_PATH"


