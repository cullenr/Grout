#!/bin/bash

BUILD_DIR="build"

if [ -d "$BUILD_DIR" ]; then
    rm -r $BUILD_DIR
fi

mkdir $BUILD_DIR

cd $BUILD_DIR

cmake -Wdev -DSDL_BUILDING_LIBRARY=FALSE -G"MSYS Makefiles" .. 

make VERBOSE=1