cmake_minimum_required(VERSION 3.20)
project(esercitazione_6) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")


add_executable(test0 test0.cpp)
add_executable(test1 test1.cpp)



