#include <pybind11/pybind11.h>

float add(float arg1, float arg2){
    return arg1 + arg2;
}

PYBIND11_MODULE(example, m){
    m.def("add", &add, "Beschrijving")
}