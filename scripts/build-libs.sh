#!/bin/bash

PROJ_HOME=$(pwd)

export YUTILS_HOME="$PROJ_HOME/vendor/Yutils"

if [ "$(find "$PROJ_HOME/vendor/Yutils" -mindepth 1 | wc -l)" -gt 0 ]; then
    git submodule update --remote --recursive
else
    git submodule update --init --recursive
fi

# Build Yutils
cd $YUTILS_HOME
bash ./scripts/build.sh Release --libo $PROJ_HOME/lib -c
cd $PROJ_HOME
