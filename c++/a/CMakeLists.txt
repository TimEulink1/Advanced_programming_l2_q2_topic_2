cmake_minimum_required(VERSION 3.23)
project(a)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(pybind11)

pybind11_add_module(module_name main.cpp)