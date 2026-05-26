#!/bin/bash

rm -f test/calculator.so
g++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) main/calculator.cpp main/bindings.cpp -o test/calculator.so
