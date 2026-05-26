#!/bin/bash

rm -rf build/; mkdir build/
g++ -O3 -shared -fPIC $(python3 -m pybind11 --includes) main/*.cpp -o build/calculator.so