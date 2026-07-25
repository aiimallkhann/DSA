cmake_minimum_required(VERSION 4.2)
project(DSA)

set(CMAKE_CXX_STANDARD 20)

add_executable(DSA Array/main.cpp
        Array/read-and-print-array.cpp
        Array/insert-at-front.cpp
        Array/insert-at-index.cpp
        Array/insert-at-end.cpp
        Array/delete-at-index.cpp
        Array/sum-of-all-elements.cpp)
