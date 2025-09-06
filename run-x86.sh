rm -rf build-x86
mkdir build-x86
cd build-x86
cmake .. -DTOOLCHAIN_FILE=cmake/toolchain-rpi.cmake
make -j 4
