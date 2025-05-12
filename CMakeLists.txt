cmake_minimum_required(VERSION 3.13)

project(cpplox)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.h)

add_executable(interpreter ${SOURCE_FILES})
