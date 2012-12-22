#!/bin/bash

BUILD_DIR="build"

if [ -d "$BUILD_DIR" ]; then
    rm -r $BUILD_DIR
fi

mkdir $BUILD_DIR

cd $BUILD_DIR

cmake -Wdev -DSDL_BUILDING_LIBRARY=FALSE -G"MSYS Makefiles" -DADD_TESTS=TRUE .. 

make VERBOSE=1