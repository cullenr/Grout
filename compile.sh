BUILD_DIR="build"

if [ -d "$BUILD_DIR" ]; then
    rm -r $BUILD_DIR
fi

mkdir $BUILD_DIR

cd $BUILD_DIR

cmake -Wdev -DADD_TESTS=ON .. 

make