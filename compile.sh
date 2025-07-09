#!/bin/bash

echo "Building"
cd build
make clean
cmake ..
make
cd ..
ls -a build
echo "Done"
