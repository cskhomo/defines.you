#include <pybind11/pybind11.h>
#include "calculator.h"

PYBIND11_MODULE(calculator, m) {
    m.def("add", &add);
}
