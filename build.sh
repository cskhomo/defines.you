#!/bin/bash

rm -f build/calculator.so
g++ -O3 -shared -fPIC $(python3 -m pybind11 --includes) main/*.cpp -o build/calculator.so