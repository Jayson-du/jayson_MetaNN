#!/usr/bin/bash

rm -f ./build/CMakeCache.txt

cmake -B build -S ./

cmake --build build