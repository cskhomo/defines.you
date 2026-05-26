#!/bin/bash

rm -f calculator.so
g++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) calculator.cpp bindings.cpp -o calculator.so
