rm -rf build
# cmake --build build --target clean
mkdir build && cd build
cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build .