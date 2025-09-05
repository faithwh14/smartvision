rm -rf build-rpi
mkdir build-rpi
cd build-rpi
cmake .. -DTOOLCHAIN_FILE=cmake/toolchain-rpi.cmake
make -j 4
