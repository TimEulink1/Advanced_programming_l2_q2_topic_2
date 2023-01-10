cmake_minimum_required(VERSION 3.23)
project(a)

set(CMAKE_CXX_STANDARD 20)

add_executable(a main.cpp)
#target_include_directories(a PRIVATE /usr/include/python3.10/include)
find_package(pybind11 REQUIRED)