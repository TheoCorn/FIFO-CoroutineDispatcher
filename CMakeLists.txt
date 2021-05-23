cmake_minimum_required(VERSION 3.16)
project(Looper)

set(CMAKE_CXX_STANDARD 20)

SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread")
add_executable(Looper main.cpp Looper.cpp Looper.h mtlNamespce.h Runnable.cpp Runnable.h Queue.cpp Queue.h)