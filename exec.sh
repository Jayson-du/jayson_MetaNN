#!/usr/bin/bash

rm -f ./build/CMakeCache.txt

cmake -B build \
      -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
      -G "Ninja" \
      -S ./

cmake --build build -j 16
